# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(FuzzyLogicController VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(include)

# Source files
set(SOURCES
    src/FuzzySet.cpp
    src/FuzzyRule.cpp
    src/FuzzyController.cpp
    main.cpp
)

# Create an executable from the source files
add_executable(fuzzy_controller ${SOURCES})

# Optionally, you can add include directories here as well
# target_include_directories(fuzzy_controller PRIVATE include)
