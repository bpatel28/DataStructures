﻿# CMakeList.txt : CMake project for tree, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(tries_lib)

file(GLOB HEADER "*.hpp")

file(GLOB SOURCE "*.cpp")

add_library(tries_lib STATIC ${SOURCE} ${HEADER})