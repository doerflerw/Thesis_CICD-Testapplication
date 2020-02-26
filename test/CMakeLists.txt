cmake_minimum_required (VERSION 3.8)

# Project's name
project(test)

# Add source to this project's executable.
add_executable (test "test.cpp" "pch.h")

# TODO: Add tests and install targets if needed.
target_link_libraries (test
    gtest
)

add_dependencies(test
    gtest
)