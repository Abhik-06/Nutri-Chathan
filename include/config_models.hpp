
#ifndef NUTRISOLVE_CONFIG_MODELS_HPP
#define NUTRISOLVE_CONFIG_MODELS_HPP

#include <string>
#include <vector>

struct UserConfig
{
    double max_budget = 0.0;

    double min_protein = 0.0;
    double min_calories = 0.0;

    int days = 1;

    // Optimality gap expressed as a percentage.
    double margin = 2.0;

    bool require_variety = false;
    bool avoid_spicy = false;

    std::string allergy;
    std::vector<std::string> dislikes;
};

#endif // NUTRISOLVE_CONFIG_MODELS_HPP
