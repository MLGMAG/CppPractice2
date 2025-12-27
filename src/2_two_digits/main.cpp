#include <iostream>

int main() {
  std::cout << "Enter two integers:\n";

  int val1 = 0;
  int val2 = 0;

  std::cin >> val1 >> val2;

  if (val1 > val2) {
    std::cout << val1 << " is greater than " << val2 << "\n";
    std::cout << val2 << " is smaller than " << val1 << "\n";
  }

  if (val1 < val2) {
    std::cout << val2 << " is greater than " << val1 << "\n";
    std::cout << val1 << " is smaller than " << val2 << "\n";
  }

  if (val1 == val2) {
    std::cout << val1 << " is qualt to " << val2 << "\n";
  }

  std::cout << val1 << " + " << val2 << " == " << val1 + val2 << "\n";
  std::cout << val1 << " - " << val2 << " == " << val1 - val2 << "\n";
  std::cout << val2 << " - " << val1 << " == " << val2 - val1 << "\n";
  std::cout << val1 << " * " << val2 << " == " << val1 * val2 << "\n";

  double floating_val1 = val1;
  double floating_val2 = val2;

  double val1_ratio = floating_val1 / floating_val2;
  double val2_ratio = floating_val2 / floating_val1;

  std::cout << val1 << " / " << val2 << " == " << val1_ratio << "\n";
  std::cout << val2 << " / " << val1 << " == " << val2_ratio << "\n";

  return 0;
}

