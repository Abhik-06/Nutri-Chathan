
#ifndef NUTRISOLVE_RESULT_MODELS_HPP
#define NUTRISOLVE_RESULT_MODELS_HPP

#include <string>
#include <vector>

struct IngredientResult
{
    std::string ingredient_name;
    double grams = 0.0;
};

struct DishResult
{
    std::string dish_name;
    std::vector<IngredientResult> ingredients;
};

struct SolveResult
{
    bool is_optimal = false;
    std::string status_message;

    double total_cost = 0.0;
    double total_protein = 0.0;
    double total_calories = 0.0;

    double total_iron = 0.0;
    double total_calcium = 0.0;
    double total_vitamin_c = 0.0;

    std::vector<DishResult> dishes;
};

#endif // NUTRISOLVE_RESULT_MODELS_HPP
