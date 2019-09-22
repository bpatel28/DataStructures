# CMakeList.txt : CMake project for tree, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(trees_lib)

file(GLOB HEADER "*/*.hpp")

file(GLOB SOURCE "*/*.cpp")

add_library(trees_lib STATIC ${SOURCE} ${HEADER})