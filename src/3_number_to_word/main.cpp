#include <iostream>
#include <vector>
#include <string>

int main() {
  std::cout << "Enter number from 0 to 9:\n";

  std::vector<std::string> number_to_word;

  number_to_word.push_back("zero");
  number_to_word.push_back("one");
  number_to_word.push_back("two");
  number_to_word.push_back("three");
  number_to_word.push_back("four");
  number_to_word.push_back("five");
  number_to_word.push_back("six");
  number_to_word.push_back("seven");
  number_to_word.push_back("eight");
  number_to_word.push_back("nine");

  for (int temp; std::cin >> temp;) {
    if (temp > -1 && temp < 10) {
      std::string number_string = number_to_word[temp];
      std::cout << temp << " - " << number_string << "\n";
    } else {
      std::cout << "Number is unsupported: '" << temp << "'\n";
    }
  }

}

