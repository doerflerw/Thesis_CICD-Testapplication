cmake_minimum_required (VERSION 3.8)

# Project's name
project(integrationtest)

enable_testing()

# Add source to this project's executable.
add_executable (run_integrationtest "integrationtest.cpp" "integrationtest.h")

target_link_libraries (run_integrationtest gtest)
add_dependencies(run_integrationtest gtest)


# TODO: Add tests and install targets if needed.
