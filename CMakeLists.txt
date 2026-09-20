cmake_minimum_required(VERSION 3.15)
project(NutriSolve CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To find vcpkg packages
find_package(ortools CONFIG REQUIRED)
find_package(cli11 CONFIG REQUIRED)

# RapidCSV
add_executable(nutrisolve src/main.cpp)
target_include_directories(nutrisolve PRIVATE include)
target_link_libraries(nutrisolve PRIVATE ortools::ortools CLI11:CLI11)