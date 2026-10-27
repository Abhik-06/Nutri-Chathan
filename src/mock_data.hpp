
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

    Ingredient chicken;
    chicken.code = "C001";
    chicken.name = "Chicken";
    chicken.price_per_gram = 0.25;
    chicken.protein_per_gram = 0.27;
    chicken.carbs_per_gram = 0.0;
    chicken.fat_per_gram = 0.10;
    chicken.calories_per_gram = 2.39;

    Ingredient eggs;
    eggs.code = "E001";
    eggs.name = "Eggs";
    eggs.price_per_gram = 0.18;
    eggs.protein_per_gram = 0.13;
    eggs.carbs_per_gram = 0.01;
    eggs.fat_per_gram = 0.11;
    eggs.calories_per_gram = 1.55;

    Ingredient potatoes;
    potatoes.code = "P001";
    potatoes.name = "Potatoes";
    potatoes.price_per_gram = 0.04;
    potatoes.protein_per_gram = 0.02;
    potatoes.carbs_per_gram = 0.17;
    potatoes.fat_per_gram = 0.001;
    potatoes.calories_per_gram = 0.77;

    Ingredient milk;
    milk.code = "M001";
    milk.name = "Milk";
    milk.price_per_gram = 0.07;
    milk.protein_per_gram = 0.034;
    milk.carbs_per_gram = 0.05;
    milk.fat_per_gram = 0.035;
    milk.calories_per_gram = 0.61;

    Ingredient oats;
    oats.code = "O001";
    oats.name = "Oats";
    oats.price_per_gram = 0.10;
    oats.protein_per_gram = 0.17;
    oats.carbs_per_gram = 0.66;
    oats.fat_per_gram = 0.07;
    oats.calories_per_gram = 3.89;

    Ingredient bananas;
    bananas.code = "B001";
    bananas.name = "Bananas";
    bananas.price_per_gram = 0.06;
    bananas.protein_per_gram = 0.011;
    bananas.carbs_per_gram = 0.228;
    bananas.fat_per_gram = 0.003;
    bananas.calories_per_gram = 0.89;

    Ingredient paneer;
    paneer.code = "PN001";
    paneer.name = "Paneer";
    paneer.price_per_gram = 0.30;
    paneer.protein_per_gram = 0.18;
    paneer.carbs_per_gram = 0.02;
    paneer.fat_per_gram = 0.20;
    paneer.calories_per_gram = 2.65;

    Ingredient cooking_oil;
    cooking_oil.code = "OIL001";
    cooking_oil.name = "Cooking Oil";
    cooking_oil.price_per_gram = 0.15;
    cooking_oil.protein_per_gram = 0.0;
    cooking_oil.carbs_per_gram = 0.0;
    cooking_oil.fat_per_gram = 1.0;
    cooking_oil.calories_per_gram = 8.84;

    Ingredient wheat_flour;
    wheat_flour.code = "W001";
    wheat_flour.name = "Wheat Flour";
    wheat_flour.price_per_gram = 0.05;
    wheat_flour.protein_per_gram = 0.13;
    wheat_flour.carbs_per_gram = 0.72;
    wheat_flour.fat_per_gram = 0.025;
    wheat_flour.calories_per_gram = 3.64;

    Ingredient chickpeas;
    chickpeas.code = "CH001";
    chickpeas.name = "Chickpeas";
    chickpeas.price_per_gram = 0.10;
    chickpeas.protein_per_gram = 0.089;
    chickpeas.carbs_per_gram = 0.27;
    chickpeas.fat_per_gram = 0.027;
    chickpeas.calories_per_gram = 1.64;

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

    Recipe chicken_rice;
    chicken_rice.name = "Chicken Rice";
    chicken_rice.ingredients = {
        {rice, 50.0, 200.0},
        {chicken, 50.0, 150.0},
        {vegetables, 20.0, 100.0},
        {cooking_oil, 5.0, 15.0}};

    Recipe paneer_roti;
    paneer_roti.name = "Paneer Roti";
    paneer_roti.ingredients = {
        {wheat_flour, 40.0, 120.0},
        {paneer, 40.0, 120.0},
        {vegetables, 20.0, 80.0},
        {cooking_oil, 3.0, 10.0}};

    Recipe egg_rice;
    egg_rice.name = "Egg Rice";
    egg_rice.ingredients = {
        {rice, 50.0, 200.0},
        {eggs, 30.0, 100.0},
        {vegetables, 20.0, 100.0},
        {cooking_oil, 5.0, 15.0}};

    Recipe potato_curry;
    potato_curry.name = "Potato Curry";
    potato_curry.ingredients = {
        {potatoes, 80.0, 200.0},
        {vegetables, 20.0, 80.0},
        {cooking_oil, 5.0, 15.0}};

    Recipe oatmeal;
    oatmeal.name = "Oatmeal";
    oatmeal.ingredients = {
        {oats, 40.0, 100.0},
        {milk, 100.0, 250.0},
        {bananas, 30.0, 100.0}};

    Recipe chickpea_curry;
    chickpea_curry.name = "Chickpea Curry";
    chickpea_curry.ingredients = {
        {chickpeas, 40.0, 150.0},
        {vegetables, 20.0, 100.0},
        {cooking_oil, 5.0, 15.0}};

    Recipe lentil_rice;
    lentil_rice.name = "Lentil Rice";
    lentil_rice.ingredients = {
        {rice, 40.0, 150.0},
        {lentils, 30.0, 100.0},
        {vegetables, 20.0, 80.0},
        {cooking_oil, 3.0, 10.0}};

    Recipe paneer_rice;
    paneer_rice.name = "Paneer Rice";
    paneer_rice.ingredients = {
        {rice, 50.0, 180.0},
        {paneer, 30.0, 100.0},
        {vegetables, 20.0, 100.0},
        {cooking_oil, 3.0, 10.0}};

    Recipe boiled_eggs_potatoes;
    boiled_eggs_potatoes.name = "Eggs and Potatoes";
    boiled_eggs_potatoes.ingredients = {
        {eggs, 50.0, 150.0},
        {potatoes, 80.0, 200.0},
        {vegetables, 20.0, 80.0}};

    Recipe banana_oats;
    banana_oats.name = "Banana Oats";
    banana_oats.ingredients = {
        {oats, 40.0, 80.0},
        {bananas, 50.0, 120.0},
        {milk, 100.0, 200.0}};

    return {rice_dish, lentil_dish};
}

#endif // NUTRISOLVE_MOCK_DATA_HPP
