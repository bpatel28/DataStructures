# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (proj_array_list)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE main.cpp)

add_executable(proj_array_list ${SOURCE})

include_directories(src)

add_subdirectory(src)

add_subdirectory(tests)

target_link_libraries(proj_array_list array_list_lib)