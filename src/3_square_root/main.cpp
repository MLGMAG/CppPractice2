#include <iostream>

int square(int input) {
  int result = 0;
  for (int i = 0; i < input; i++) {
    result += input;
  }

  return result;
}


int main() {
  for (int i = 0; i < 10; i++) {
    std::cout << i << "\t" << square(i) << "\n";
  }
  return 0;
}


