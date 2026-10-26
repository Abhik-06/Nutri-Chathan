
#include <iostream>
#include <vector>

#include "data_models.hpp"
#include "mock_data.hpp"
#include "config_models.hpp"
#include "result_models.hpp"

int main()
{
    std::vector<Recipe> recipes = create_mock_recipes();

    std::cout << "NutriSolve - Team B OR Engine\n";
    std::cout << "-----------------------------\n";
    std::cout << "Mock recipes loaded: " << recipes.size() << "\n\n";

    for (const Recipe &recipe : recipes)
    {
        std::cout << "Dish: " << recipe.name << "\n";

        for (const RecipeIngredient &item : recipe.ingredients)
        {
            std::cout << "  Ingredient: "
                      << item.ingredient.name << "\n";
            std::cout << "  Allowed quantity: "
                      << item.min_grams << " - "
                      << item.max_grams << " grams\n";
            std::cout << "  Cost per gram: "
                      << item.ingredient.price_per_gram << "\n";
            std::cout << "  Protein per gram: "
                      << item.ingredient.protein_per_gram << "\n";
            std::cout << "  Calories per gram: "
                      << item.ingredient.calories_per_gram << "\n";
        }

        std::cout << "\n";
    }

    UserConfig config;
    config.max_budget = 200.0;
    config.min_protein = 50.0;
    config.min_calories = 1800.0;
    config.days = 1;

    SolveResult result;
    result.is_optimal = false;
    result.status_message = "Not solved yet";

    std::cout << "--- Configuration Test ---\n";
    std::cout << "Budget: " << config.max_budget << "\n";
    std::cout << "Minimum protein: " << config.min_protein << " g\n";
    std::cout << "Minimum calories: " << config.min_calories << "\n";
    std::cout << "Days: " << config.days << "\n\n";

    std::cout << "--- Result Model Test ---\n";
    std::cout << "Solved: " << (result.is_optimal ? "Yes" : "No") << "\n";
    std::cout << "Status: " << result.status_message << "\n";

    return 0;
}
