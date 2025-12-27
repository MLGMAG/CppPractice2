#include <iostream>
#include <string>

int main() {
  std::cout << "Enter polish notaion:\n";

  std::string operator_type = "";
  double val1 = 0;
  double val2 = 0;

  while (std::cin >> operator_type >> val1 >> val2) {
    if (operator_type == "") {
      std::cout << "Invalid operator!\n";
    }

    if (operator_type == "+" || operator_type == "plus") {
      std::cout << val1 + val2 << "\n";
    }

    if (operator_type == "-" || operator_type == "minus") {
      std::cout << val1 - val2 << "\n";
    }

    if (operator_type == "*" || operator_type == "mul") {
      std::cout << val1 * val2 << "\n";
    }

    if (operator_type == "/" || operator_type == "div") {
      std::cout << val1 / val2 << "\n";
    }

    operator_type = "";
  }

  return 0;
}
