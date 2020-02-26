# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.12)

add_library(gtest
    src/gtest-all.cc
    src/gtest_main.cc
)

# The following folder will be included
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")



# debug output
# print_CMake_variables()
