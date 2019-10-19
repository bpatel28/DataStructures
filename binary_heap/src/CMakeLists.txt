# CMakeList.txt : CMake project for binary_heap, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(binary_heap_lib)

file(GLOB HEADER "*.hpp")

file(GLOB SOURCE "*.cpp")

add_library(binary_heap_lib STATIC ${SOURCE} ${HEADER})