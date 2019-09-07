#CMake Project Configurations
cmake_minimum_required (VERSION 3.8)

project(linked_list_lib)

set(CMAKE_BUILD_TYPE Release)

#add headers files
file(GLOB HEADER "*.hpp")

file(GLOB SOURCE "*.cpp")

add_library(linked_list_lib STATIC ${SOURCE} ${HEADER})
