#include <cstddef>
#include <iostream>
#include <vector>
#include <cmath>

int main() {

  std::cout << "Enter primary numbers count:\n";

  size_t primary_numbers_count = 0;
  std::vector<int> primary_numbers;

  std::cin >> primary_numbers_count;

  int pointer = 2;
  while (primary_numbers.size() < primary_numbers_count) {
    double limit = sqrt(pointer);

    bool is_end = false;
    bool is_primary = true;
    for (size_t i = 0; i < primary_numbers.size() && !is_end; i++) {
      int current_prime = primary_numbers[i];
      if (current_prime > limit) {
        is_end = true;
      } else if (pointer % current_prime == 0) {
        is_end = true;
        is_primary = false;
      }
    }

    if (is_primary) {
      primary_numbers.push_back(pointer);
    }

    pointer++;
  }

  std::cout << "Primary numbers: ";
  for (int i : primary_numbers) {
    std::cout << i << " ";
  }

  std::cout << "\n";

  return 0;
}

