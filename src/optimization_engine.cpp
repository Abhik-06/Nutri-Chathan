
#include "optimization_engine.hpp"

SolveResult OptimizationEngine::solve(
    const std::vector<Recipe> &recipes,
    const UserConfig &config)
{
    SolveResult result;

    if (recipes.empty())
    {
        result.status_message = "No recipes provided.";
        return result;
    }

    if (config.days < 1 || config.days > 7)
    {
        result.status_message = "Number of days must be between 1 and 7.";
        return result;
    }

    if (config.max_budget <= 0)
    {
        result.status_message = "Budget must be greater than zero.";
        return result;
    }

    result.status_message =
        "Inputs validated. Optimization is not implemented yet.";

    return result;
}
