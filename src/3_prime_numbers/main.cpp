#include <iostream>
#include <vector>



int main() {
  constexpr int min_number = 2;
  constexpr int max_number = 1000000;

  std::vector<int> primes;

  for (int i = min_number; i < max_number; i++) {
    bool is_prime = true;
    bool is_end = false;

    for (size_t j = 0; j < primes.size() && !is_end; j++) {
      int current_prime = primes[j];
      int reminder = i % current_prime;
      if (reminder == 0) {
        is_prime = false;
        is_end = true;
      }

      int half = i / 2;
      if (current_prime > half) {
        is_end = true;
      }
    }

    if (is_prime) {
      primes.push_back(i);
    }
  }

  std::cout << "Primes: [";
  for (size_t i = 0; i < primes.size(); i++) {
    int number = primes[i];
    if (i == primes.size() - 1) {
      std::cout << number;
    } else {
      std::cout << number << ", ";
    }
  }

  std::cout << "]\n";

  return 0;
}

