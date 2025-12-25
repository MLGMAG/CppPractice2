cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(practice)

add_executable(1_input_args src/1_input_args/main.cpp)
add_executable(1_hello_world src/1_hello_world/main.cpp)
add_executable(2_name_age src/2_name_age/main.cpp)

