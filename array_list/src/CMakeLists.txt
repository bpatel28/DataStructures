# CMakeList.txt : CMake project for array_lists, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(array_list_lib)

file(GLOB HEADER "*.hpp")

file(GLOB SOURCE "*.cpp")

add_library(array_list_lib STATIC ${SOURCE} ${HEADER})