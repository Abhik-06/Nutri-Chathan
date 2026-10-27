#include "optimization_engine.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include <algorithm>
#include <memory>

using operations_research::MPSolver;
using operations_research::MPVariable;
using operations_research::MPConstraint;
using operations_research::MPObjective;
using operations_research::MPSolverParameters;

SolveResult OptimizationEngine::solve(
    const std::vector<Recipe>& recipes,
    const UserConfig& config) const 
{
    return solve_single_day(config, recipes, {});
}

SolveResult OptimizationEngine::solve_single_day(
    const UserConfig& config, 
    const std::vector<Recipe>& recipes,
    const std::vector<std::string>& banned_dishes) 
{
    SolveResult result;
    result.is_optimal = false;

    if (recipes.empty()) {
        result.status_message = "No recipes provided.";
        return result;
    }

    std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("CBC"));
    if (!solver) {
        result.status_message = "Solver initialization failed.";
        return result;
    }

    const double INF = solver->infinity();
    
    std::vector<MPVariable*> dish_vars;
    std::vector<std::vector<MPVariable*>> ingredient_vars;

    // 1. Variable Creation & Big-M Culinary Constraints
    for (size_t d = 0; d < recipes.size(); ++d) {
        const auto& recipe = recipes[d];
        MPVariable* y_d = solver->MakeIntVar(0.0, 1.0, "dish_" + recipe.name);
        dish_vars.push_back(y_d);
        
        // Variety Constraint: Ban previously eaten dishes
        for (const auto& ban : banned_dishes) {
            if (recipe.name == ban) {
                y_d->SetBounds(0.0, 0.0);
            }
        }

        // Dislikes Constraint (Dish level)
        for (const auto& dislike : config.dislikes) {
            if (recipe.name == dislike) {
                y_d->SetBounds(0.0, 0.0);
            }
        }

        std::vector<MPVariable*> item_vars;
        for (size_t i = 0; i < recipe.ingredients.size(); ++i) {
            const auto& recipe_ingredient = recipe.ingredients[i];
            const auto& ing_data = recipe_ingredient.ingredient;

            MPVariable* x_id = solver->MakeNumVar(0.0, INF, recipe.name + "_" + ing_data.code);
            item_vars.push_back(x_id);

            // Upper Bound: x_id - max_grams * y_d <= 0
            MPConstraint* upper_bound = solver->MakeRowConstraint(-INF, 0.0);
            upper_bound->SetCoefficient(x_id, 1.0);
            upper_bound->SetCoefficient(y_d, -recipe_ingredient.max_grams);

            // Lower Bound: x_id - min_grams * y_d >= 0
            MPConstraint* lower_bound = solver->MakeRowConstraint(0.0, INF);
            lower_bound->SetCoefficient(x_id, 1.0);
            lower_bound->SetCoefficient(y_d, -recipe_ingredient.min_grams);
            
            // Spicy Exclusion
            if (config.avoid_spicy && ing_data.is_spicy) {
                x_id->SetBounds(0.0, 0.0);
            }

            // Allergy Exclusion
            if (!config.allergy.empty() && ing_data.allergen == config.allergy) {
                x_id->SetBounds(0.0, 0.0);
            }

            // Dislikes Exclusion (Ingredient level)
            for (const auto& dislike : config.dislikes) {
                if (ing_data.name == dislike || ing_data.code == dislike) {
                    x_id->SetBounds(0.0, 0.0);
                }
            }
        }
        ingredient_vars.push_back(item_vars);
    }

    // 2. Macronutrient Floors & Budget Cap
    MPConstraint* protein_floor = solver->MakeRowConstraint(config.min_protein, INF, "ProteinFloor");
    MPConstraint* calorie_floor = solver->MakeRowConstraint(config.min_calories, INF, "CalorieFloor");
    
    MPConstraint* budget_cap = nullptr;
    if (config.max_budget > 0.0) {
        budget_cap = solver->MakeRowConstraint(0.0, config.max_budget, "BudgetCap");
    }

    // 3. Selection Integrity (Select at least 1 dish)
    MPConstraint* meal_count = solver->MakeRowConstraint(1.0, INF, "AtLeastOneDish");

    // 4. Objective Function: Minimize Cost
    MPObjective* const objective = solver->MutableObjective();
    objective->SetMinimization();

    for (size_t d = 0; d < recipes.size(); ++d) {
        meal_count->SetCoefficient(dish_vars[d], 1.0);
        for (size_t i = 0; i < recipes[d].ingredients.size(); ++i) {
            const auto& ing_data = recipes[d].ingredients[i].ingredient;
            MPVariable* x_id = ingredient_vars[d][i];

            objective->SetCoefficient(x_id, ing_data.price_per_gram);
            protein_floor->SetCoefficient(x_id, ing_data.protein_per_gram);
            calorie_floor->SetCoefficient(x_id, ing_data.calories_per_gram);

            if (budget_cap) {
                budget_cap->SetCoefficient(x_id, ing_data.price_per_gram);
            }
        }
    }

    // 5. Configure Optimality Gap (margin %) & Solve
    MPSolverParameters params;
    if (config.margin > 0.0) {
        params.SetDoubleParam(MPSolverParameters::RELATIVE_MIP_GAP, config.margin / 100.0);
    }

    const MPSolver::ResultStatus status = solver->Solve(params);

    if (status == MPSolver::OPTIMAL || status == MPSolver::FEASIBLE) {
        result.is_optimal = true;
        result.status_message = "Optimal diet found.";
        result.total_cost = objective->Value();
        
        result.total_protein = 0.0; result.total_calories = 0.0;
        result.total_iron = 0.0; result.total_calcium = 0.0; result.total_vitamin_c = 0.0;
        
        for (size_t d = 0; d < recipes.size(); ++d) {
            if (dish_vars[d]->solution_value() > 0.5) { 
                DishResult chosen_dish;
                chosen_dish.dish_name = recipes[d].name;

                for (size_t i = 0; i < recipes[d].ingredients.size(); ++i) {
                    double grams = ingredient_vars[d][i]->solution_value();
                    if (grams > 1e-5) {
                        const auto& ing_data = recipes[d].ingredients[i].ingredient;

                        IngredientResult ir;
                        ir.ingredient_name = ing_data.name;
                        ir.grams = grams;
                        chosen_dish.ingredients.push_back(ir);

                        result.total_protein += grams * ing_data.protein_per_gram;
                        result.total_calories += grams * ing_data.calories_per_gram;
                        result.total_iron += grams * ing_data.iron_per_gram;
                        result.total_calcium += grams * ing_data.calcium_per_gram;
                        result.total_vitamin_c += grams * ing_data.vitamin_c_per_gram;
                    }
                }
                result.dishes.push_back(chosen_dish);
            }
        }
    } else {
        result.status_message = "Constraints infeasible (check budget or macro floors).";
    }

    return result;
}

std::vector<SolveResult> OptimizationEngine::generate_weekly_plan(
    const UserConfig& config, 
    const std::vector<Recipe>& recipes) 
{
    std::vector<SolveResult> weekly_plan;
    std::vector<std::string> banned_dishes;
    
    int num_days = (config.days > 0) ? config.days : 1;

    for (int i = 0; i < num_days; ++i) {
        SolveResult daily_result = solve_single_day(config, recipes, banned_dishes);
        
        if (daily_result.is_optimal && !daily_result.dishes.empty()) {
            weekly_plan.push_back(daily_result);
            if (config.require_variety) {
                for (const auto& dish : daily_result.dishes) {
                    banned_dishes.push_back(dish.dish_name);
                }
            }
        } else {
            SolveResult failed;
            failed.is_optimal = false;
            failed.status_message = "Failed to find optimal meal on day " + std::to_string(i + 1) + ": " + daily_result.status_message;
            weekly_plan.push_back(failed);
        }
    }
    
    return weekly_plan;
}