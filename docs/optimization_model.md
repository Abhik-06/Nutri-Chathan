# NutriSolve — Team B Optimization Model

## 1. Decision variables

For each recipe _j_ and ingredient _i_:

- _xᵢⱼ_: grams of ingredient \(i\) used in recipe \(j\).
- _yⱼ_: binary variable; 1 if recipe \(j\) is selected, otherwise 0.

## 2. Objective function

Minimize the total ingredient cost:

min ∑ᵢ∑ⱼ cᵢⱼxᵢⱼ

where cᵢⱼ is the cost per gram of ingredient _i_ in recipe _j_.

## 3. Ingredient quantity bounds

For every ingredient:

Lᵢⱼyⱼ ≤ xᵢⱼ ≤ Uᵢⱼyⱼ


Here, Lᵢⱼ and Uᵢⱼ are the minimum and maximum quantities. These constraints force ingredient quantities to zero when the recipe is not selected.

## 4. Nutrition constraints

Minimum protein:

∑ⱼ∑ᵢ pᵢⱼxᵢⱼ ≥ Pₘᵢₙ

Minimum calories:

∑ⱼ∑ᵢ kᵢⱼxᵢⱼ ≥ Kₘᵢₙ

Here, pᵢⱼ and kᵢⱼ are protein and calories per gram.

## 5. Budget constraint

If the user provides a maximum budget:

∑ⱼ∑ᵢ cᵢⱼxᵢⱼ ≤ Bₘₐₓ


## 6. Important implementation note

The current project has a `days` field, but a multi-day meal plan requires additional day-indexed variables and constraints. We will first implement and test the single-day model, then extend it to multiple days.
