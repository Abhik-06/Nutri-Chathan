# NutriSolve 🥗

NutriSolve is a C++ command-line application that utilizes Mixed-Integer Linear Programming (MILP) to generate highly optimized, cost-effective meal plans. By leveraging the Google OR-Tools CBC solver, NutriSolve evaluates nutritional data, budget constraints, and dietary preferences to mathematically prove and construct the optimal weekly diet.

## 🌟 Features

* **Nutritional Optimization:** Enforces hard floors for macronutrients (protein, calories, etc.) while minimizing the overall financial cost.

* **Dietary Exclusions:** Safely removes specific allergens, spicy ingredients, or user-disliked foods from the mathematical model.

* **Smart Budgeting:** Caps daily spending while still satisfying all biological constraints.

* **Menu Variety:** Configurable variety flags prevent the solver from suggesting the same meal on consecutive days.

* **Multi-Day Planning:** Generates full 7-day meal plans in milliseconds.

## 🏗️ Architecture

NutriSolve is built on a strictly decoupled 3-tier architecture to allow parallel development across a 6-member team:

1. **Data Layer (Team A):** Parses raw nutritional CSV data using `rapidcsv` into immutable C++ structs.

2. **Engine Layer (Team B):** Translates the data structs into linear algebraic constraints and solves them using Google OR-Tools.

3. **Interface Layer (Team C):** Manages user inputs and terminal outputs using `CLI11`.

## 📦 Dependencies

To prioritize stability and build speed, NutriSolve avoids complex source-build package managers (like `vcpkg`).

* **CLI11** (UI) and **rapidcsv** (Data): Managed as header-only files located in `include/`.

* **Google OR-Tools** (Math Engine): Linked manually via a pre-compiled Linux binary.

## 🚀 Setup & Build Instructions

### 1. Fetch the OR-Tools Binary

Because Google OR-Tools is a massive industrial library, we use the pre-compiled Ubuntu binary. You must download and extract it into a local `lib/` folder before compiling.

Run this from the root of the project:

```
mkdir -p lib
wget https://github.com/google/or-tools/releases/download/v9.11/or-tools_amd64_ubuntu-24.04_cpp_v9.11.4210.tar.gz -O ortools.tar.gz
mkdir -p lib/ortools_install
tar -xzf ortools.tar.gz -C lib/ortools_install --strip-components=1
rm ortools.tar.gz

```

*(Note: The `lib/` directory is ignored by Git to prevent pushing 400MB of machine code to the repository. Every developer must run this step once on their local machine).*

### 2. Compile the Project

We use CMake to link the local dependencies and build the executables.

```
# Generate the build system
cmake -B build

# Compile the executables
cmake --build build

```

### 3. Run the Tests

Verify that the solver and data structures are functioning correctly by running the engine test:

```
./build/engine_test

```

## 🤝 Contributing

* **Single Source of Truth:** Do not modify the data contracts in `include/data_models.hpp` or `include/result_models.hpp` without team consensus, as all three layers depend on them.

* **Commit Etiquette:** Ensure your working directory is clean and that `build/` and `lib/` are never committed to the repository.

*Built with C++17 and Google OR-Tools.*