cmake_minimum_required(VERSION 3.21)
project(Laboratory_work_5bV C)

set(CMAKE_C_STANDARD 23)

add_executable(Laboratory_work_5bV main.c)

add_subdirectory(includes)

target_link_libraries(Laboratory_work_5bV includes)
