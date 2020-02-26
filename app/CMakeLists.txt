# CMakeList.txt : CMake project for CICD_Example, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Project's name
project(cicd_exampleapp)

# Add source to this project's executable.
add_executable (app "app.cpp" "app.h")

# TODO: Add tests and install targets if needed.
