#ifndef OPTIMIZATION_ENGINE_HPP
#define OPTIMIZATION_ENGINE_HPP

#include <vector>
#include <string>
#include "config_models.hpp"
#include "data_models.hpp"
#include "result_models.hpp"

class OptimizationEngine {
public:
    // Multi-day entry point
    static std::vector<SolveResult> generate_weekly_plan(
        const UserConfig& config, 
        const std::vector<Recipe>& recipes
    );

    // Single-day entry point (matches your friend's PR API)
    SolveResult solve(
        const std::vector<Recipe>& recipes,
        const UserConfig& config
    ) const;

private:
    static SolveResult solve_single_day(
        const UserConfig& config, 
        const std::vector<Recipe>& recipes,
        const std::vector<std::string>& banned_dishes
    );
};

#endif // OPTIMIZATION_ENGINE_HPP