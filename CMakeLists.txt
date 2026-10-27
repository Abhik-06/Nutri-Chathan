cmake_minimum_required(VERSION 3.16)
project(NutriSolve)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Map the local pre-compiled OR-Tools binary
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/ortools_install" ${CMAKE_PREFIX_PATH})
find_package(ortools REQUIRED)

# Map the local header-only UI and Data libraries
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Main CLI Application
add_executable(nutrisolve src/main.cpp src/optimization_engine.cpp)
target_link_libraries(nutrisolve PRIVATE ortools::ortools)

# Team Testing Binaries
add_executable(engine_test src/engine_test.cpp src/optimization_engine.cpp)
target_link_libraries(engine_test PRIVATE ortools::ortools)

add_executable(interface_test src/interface_test.cpp)