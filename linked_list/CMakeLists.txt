cmake_minimum_required (VERSION 3.8)

project(proj_linked_list)

set(SOURCE main.cpp)
add_executable(proj_linked_list ${SOURCE})

include_directories(src)

add_subdirectory(src)

target_link_libraries(proj_linked_list linked_list_lib)