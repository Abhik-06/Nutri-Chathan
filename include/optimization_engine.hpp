
#ifndef NUTRISOLVE_OPTIMIZATION_ENGINE_HPP
#define NUTRISOLVE_OPTIMIZATION_ENGINE_HPP

#include <vector>

#include "data_models.hpp"
#include "config_models.hpp"
#include "result_models.hpp"

class OptimizationEngine
{
public:
    SolveResult solve(
        const std::vector<Recipe> &recipes,
        const UserConfig &config);
};

#endif
