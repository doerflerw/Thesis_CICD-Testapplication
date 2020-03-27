cmake_minimum_required (VERSION 3.8)

# Project's name
project(regressiontest)

enable_testing()

# Add source to this project's executable.
add_executable (run_regressiontest "regressiontest.cpp" "regressiontest.h")

target_link_libraries (run_regressiontest gtest)
add_dependencies(run_regressiontest gtest)


# TODO: Add tests and install targets if needed.
