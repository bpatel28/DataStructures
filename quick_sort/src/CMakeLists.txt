# CMakeList.txt : CMake project for binary_heap, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(quick_sort_lib)

file(GLOB HEADER "*.hpp")

file(GLOB SOURCE "*.cpp")

add_library(quick_sort_lib STATIC ${SOURCE} ${HEADER})