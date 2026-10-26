
#ifndef NUTRISOLVE_DATA_MODELS_HPP
#define NUTRISOLVE_DATA_MODELS_HPP

#include <string>
#include <vector>

// Represents one ingredient used in a recipe.
struct Ingredient
{
    std::string code;
    std::string name;

    // Price and nutritional values per gram.
    double price_per_gram = 0.0;
    double protein_per_gram = 0.0;
    double carbs_per_gram = 0.0;
    double fat_per_gram = 0.0;
    double calories_per_gram = 0.0;

    double iron_per_gram = 0.0;
    double calcium_per_gram = 0.0;
    double vitamin_c_per_gram = 0.0;

    std::string allergen;
    bool is_spicy = false;
};

// Represents an ingredient and its allowed quantity in a dish.
struct RecipeIngredient
{
    Ingredient ingredient;
    double min_grams = 0.0;
    double max_grams = 0.0;
};

// Represents a dish or meal combination.
struct Recipe
{
    std::string name;
    std::vector<RecipeIngredient> ingredients;
};

#endif // NUTRISOLVE_DATA_MODELS_HPP
