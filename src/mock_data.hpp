
#ifndef NUTRISOLVE_MOCK_DATA_HPP
#define NUTRISOLVE_MOCK_DATA_HPP

#include "data_models.hpp"

#include <vector>

inline std::vector<Recipe> create_mock_recipes()
{
    // Ingredient prices and nutritional values are illustrative.
    // All nutritional values and prices are expressed per gram.

    Ingredient rice;
    rice.code = "R001";
    rice.name = "Rice";
    rice.price_per_gram = 0.05;
    rice.protein_per_gram = 0.027;
    rice.carbs_per_gram = 0.28;
    rice.fat_per_gram = 0.003;
    rice.calories_per_gram = 1.30;

    Ingredient lentils;
    lentils.code = "L001";
    lentils.name = "Lentils";
    lentils.price_per_gram = 0.12;
    lentils.protein_per_gram = 0.09;
    lentils.carbs_per_gram = 0.20;
    lentils.fat_per_gram = 0.004;
    lentils.calories_per_gram = 1.16;

    Ingredient vegetables;
    vegetables.code = "V001";
    vegetables.name = "Vegetables";
    vegetables.price_per_gram = 0.08;
    vegetables.protein_per_gram = 0.02;
    vegetables.carbs_per_gram = 0.08;
    vegetables.fat_per_gram = 0.002;
    vegetables.calories_per_gram = 0.40;

    Recipe rice_dish;
    rice_dish.name = "Rice Dish";
    rice_dish.ingredients = {
        {rice, 50.0, 200.0},
        {vegetables, 20.0, 100.0}};

    Recipe lentil_dish;
    lentil_dish.name = "Lentil Dish";
    lentil_dish.ingredients = {
        {lentils, 30.0, 150.0},
        {vegetables, 20.0, 100.0}};

    return {rice_dish, lentil_dish};
}

#endif // NUTRISOLVE_MOCK_DATA_HPP
