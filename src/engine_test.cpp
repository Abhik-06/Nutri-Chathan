#include <iostream>
#include <iomanip>
#include <vector>
#include "optimization_engine.hpp"
#include "config_models.hpp"
#include "data_models.hpp"
#include "result_models.hpp"
#include "mock_data.hpp"

int main() {
    std::cout << "--- NutriSolve MILP Engine Test (Mock Data) ---\n\n";

    // 1. Load the mock recipes (Rice Dish & Lentil Dish)
    std::vector<Recipe> recipes = create_mock_recipes();

    // 2. Configure constraints achievable by the mock dishes
    UserConfig config;
    config.days = 2;
    config.min_protein = 6.0;      // Achievable by either Rice Dish or Lentil Dish
    config.min_calories = 180.0;   // Achievable by either Rice Dish or Lentil Dish
    config.max_budget = 50.0;
    config.require_variety = true; // Day 2 must pick a different dish than Day 1

    // 3. Execute 2-day plan
    std::vector<SolveResult> plan = OptimizationEngine::generate_weekly_plan(config, recipes);

    // 4. Print results
    std::cout << std::fixed << std::setprecision(2);
    for (size_t day = 0; day < plan.size(); ++day) {
        const auto& res = plan[day];
        std::cout << "=== Day " << (day + 1) << " ===\n";
        std::cout << "Status: " << res.status_message << "\n";
        
        if (res.is_optimal) {
            std::cout << "Total Cost: " << res.total_cost 
                      << " | Protein: " << res.total_protein << "g"
                      << " | Calories: " << res.total_calories << " kcal\n";
            for (const auto& dish : res.dishes) {
                std::cout << "  Selected Dish: " << dish.dish_name << "\n";
                for (const auto& ing : dish.ingredients) {
                    std::cout << "    - " << ing.ingredient_name << ": " << ing.grams << "g\n";
                }
            }
        }
        std::cout << "\n";
    }

    return 0;
}