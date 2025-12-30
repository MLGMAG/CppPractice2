#include <iostream>

int main() {
  constexpr int max_number = 101;

  std::cout << "Imagine a number from 0 to 100. I will gues it!\n";

  char answer = ' ';
  int left_index = 0;
  int right_index = max_number;
  int iteration = 0;
  int pointer = left_index + (right_index - left_index) / 2;
  bool guessed = false;
  bool exit = false;

  while (!guessed && !exit) {
    iteration += 1;

    std::cout << iteration << ". Your number is more, less or equal to "
              << pointer << "? (m, l or e)\n";

    if (std::cin >> answer) {
      switch (answer) {
        case 'm':
          left_index = pointer;
          break;
        case 'l':
          right_index = pointer;
          break;
        case 'e':
          guessed = true;
          break;
        default:
          std::cout << "Input is wrong, try again.\n";
          iteration -= 1;
      }

      double diff = right_index - left_index;
      if (diff <= 2) {
        guessed = true;
      }
      pointer = left_index + (right_index - left_index) / 2;
    } else {
      exit = true;
    }
  }

  if (guessed) {
    std::cout << "Your number is " << pointer << "!\n";
  }

  return 0;
}
