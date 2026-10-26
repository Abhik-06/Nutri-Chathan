# NutriSolve — Team B Optimization Model

## 1. Decision variables

For each recipe \(j\) and ingredient \(i\):

- \(x_{ij}\): grams of ingredient \(i\) used in recipe \(j\).
- \(y_j\): binary variable; 1 if recipe \(j\) is selected, otherwise 0.

## 2. Objective function

Minimize the total ingredient cost:

\[
\min \sum_j \sum_i c_{ij}x_{ij}
\]

where \(c_{ij}\) is the cost per gram of ingredient \(i\) in recipe \(j\).

## 3. Ingredient quantity bounds

For every ingredient:

\[
L_{ij}y_j \le x_{ij} \le U_{ij}y_j
\]

Here, \(L_{ij}\) and \(U_{ij}\) are the minimum and maximum quantities. These constraints force ingredient quantities to zero when the recipe is not selected.

## 4. Nutrition constraints

Minimum protein:

\[
\sum_j\sum_i p_{ij}x_{ij} \ge P_{\min}
\]

Minimum calories:

\[
\sum_j\sum_i k_{ij}x_{ij} \ge K_{\min}
\]

Here, \(p_{ij}\) and \(k_{ij}\) are protein and calories per gram.

## 5. Budget constraint

If the user provides a maximum budget:

\[
\sum_j\sum_i c_{ij}x_{ij} \le B_{\max}
\]

## 6. Important implementation note

The current project has a `days` field, but a multi-day meal plan requires additional day-indexed variables and constraints. We will first implement and test the single-day model, then extend it to multiple days.
