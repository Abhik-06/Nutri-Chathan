
#include <iostream>

#include "optimization_engine.hpp"
#include "mock_data.hpp"

int main()
{
    OptimizationEngine engine;
    UserConfig config;

    config.max_budget = 200.0;
    config.min_protein = 50.0;
    config.min_calories = 1800.0;
    config.days = 1;

    auto recipes = create_mock_recipes();
    SolveResult result = engine.solve(recipes, config);

    std::cout << "Status: " << result.status_message << "\n";

    return 0;
}
