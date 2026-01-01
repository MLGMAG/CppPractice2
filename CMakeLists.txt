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
  "2_number_sort"
  "2_polish_notation"

  "3_currency_converter"
  "3_char_table"
  "3_square_root"
  "3_bleeps"
  "3_drill"
  "3_string_analysis"
  "3_median"
  "3_distance"
  "3_guessing"
  "3_simple_calculator"
  "3_number_to_word"
  "3_word_to_number"
  "3_simple_calculator_v2"
  "3_rice_and_chess"
  "3_rock_paper_scissors"
  "3_prime_numbers"
  "3_sieve_of_eratosthenes"
  "3_n_primes"
  "3_mode"
  "3_mode_string"
  "3_quadratic_equation"
)

foreach(current_project ${PROJECTS})
  add_executable("${current_project}" "src/${current_project}/main.cpp")
endforeach()

