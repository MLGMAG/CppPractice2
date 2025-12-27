#include <iostream>

int main() {

  int start_index = 97;
  int end_index = 123;
  int current_index = start_index;

  while (current_index < end_index) {
    char c = static_cast<char>(current_index);
    std::cout << c << "\t" << current_index << "\n";
    current_index++;
  }

  return 0;
}

