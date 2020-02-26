# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.12)

# CMakeLists.txt of the following folders will be included
add_subdirectory("googletest")
include_directories(${PROJECT_SOURCE_DIR}/app)
include_directories(${PROJECT_SOURCE_DIR}/test)
include_directories(${PROJECT_SOURCE_DIR}/lib/googletest)
include_directories(${PROJECT_SOURCE_DIR}/lib/googletest/include)