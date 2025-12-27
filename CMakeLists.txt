cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(practice)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(
  PROJECTS
  "1_input_args"
  "1_hello_world"

  "2_name_age"
  "2_int_operations"
  "2_repeated_words"
  "2_type_conversion"
  "2_variable_initialization"
  "2_miles_kilometers_converter"
  "2_two_digits"
)

foreach(current_project ${PROJECTS})
  add_executable("${current_project}" "src/${current_project}/main.cpp")
endforeach()

