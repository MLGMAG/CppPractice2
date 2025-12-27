#include <iostream>

int main() {

  std::cout << "Enter 3 integers:\n";

  int val1 = 0;
  int val2 = 0;
  int val3 = 0;

  std::cin >> val1 >> val2 >> val3;

  if (val1 > val2) {
    int tmp = val2;
    val2 = val1;
    val1 = tmp;
  }

  if (val2 > val3) {
    int tmp = val3;
    val3 = val2;
    val2 = tmp;
  }

  if (val1 > val2) {
    int tmp = val2;
    val2 = val1;
    val1 = tmp;
  }

  std::cout << "Ordered sequence: " << val1 << " " << val2 << " " << val3 << "\n";

  return 0;
}

