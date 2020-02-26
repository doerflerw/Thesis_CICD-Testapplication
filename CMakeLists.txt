# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CICD_Example")

# Set the output folder where your program and libraries will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# CMakeLists.txt of the following folders will be included
#add_subdirectory(cmake)       # has to be the first include because of common CMake functions and macros

include_directories(${PROJECT_SOURCE_DIR}/test)
include_directories(${PROJECT_SOURCE_DIR}/unittest)
include_directories(${PROJECT_SOURCE_DIR}/app)
include_directories(${PROJECT_SOURCE_DIR}/lib/googletest)
include_directories(${PROJECT_SOURCE_DIR}/lib/googletest/include)

#include_directories("${PROJECT_SOURCE_DIR}")
# Include sub-projects.
add_subdirectory ("app")
add_subdirectory ("lib")
add_subdirectory ("test")
add_subdirectory ("unittest")


