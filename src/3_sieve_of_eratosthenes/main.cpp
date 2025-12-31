#include <iostream>
#include <vector>

int main() {
  constexpr int start_number = 2;
  constexpr int end_number = 121;

  std::vector<int> primes_vector(end_number + 1);
  primes_vector[0] = 1;
  primes_vector[1] = 1;

  for (size_t i = start_number; i < end_number; i++) {
    int current_prime_status = primes_vector[i];
    if (current_prime_status == 0) {
      primes_vector[i] = 1;
      for (size_t j = i + i; j < primes_vector.size(); j += i) {
        primes_vector[j] = 2;
      }
    }
  }

  std::cout << "Prime numbers: ";
  for (size_t i = 2; i < primes_vector.size(); i++) {
    int value = primes_vector[i];
    if (value == 1) {
      std::cout << i << " ";
    }
  }

  std::cout << "\n";

  return 0;
}

