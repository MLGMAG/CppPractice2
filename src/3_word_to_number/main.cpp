#include <iostream>
#include <string>
#include <map>

int main() {

  std::map<std::string, int> word_to_number_map;

  word_to_number_map["zero"] = 0;
  word_to_number_map["one"] = 1;
  word_to_number_map["two"] = 2;
  word_to_number_map["three"] = 3;
  word_to_number_map["four"] = 4;
  word_to_number_map["five"] = 5;
  word_to_number_map["six"] = 6;
  word_to_number_map["seven"] = 7;
  word_to_number_map["eight"] = 8;
  word_to_number_map["nine"] = 9;

  std::cout << "Enter number from 0 to 9 with help of letters: (like 'nine']\n";

  std::string input;

  while (std::cin >> input) {
    if (word_to_number_map.count(input)) {
      int number = word_to_number_map[input];
      std::cout << input << " - " << number << "\n";
    } else {
      std::cout << "Input number '" << input << "' is unsupported or invalid.\n";
    }
  }

}

