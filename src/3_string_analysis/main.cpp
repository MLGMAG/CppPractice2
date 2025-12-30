#include <iostream>
#include <string>

int main() {
  std::string input = "";

  std::cout << "Enter a word:\n";
  std::cin >> input;

  for (char character : input) {
    int number = static_cast<int>(character);
    std::cout << character << " - " << number << "\n";
  }

  return 0;
}

