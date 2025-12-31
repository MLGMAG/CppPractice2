#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>


int main() {
  std::srand(std::time({}));

  std::set<char> input_options;
  input_options.insert('r');
  input_options.insert('p');
  input_options.insert('s');

  std::vector<char> options;
  options.push_back('r');
  options.push_back('p');
  options.push_back('s');

  std::map<char, char> finish_option_map;
  finish_option_map['r'] = 's';
  finish_option_map['p'] = 'r';
  finish_option_map['s'] = 'p';

  std::map<char, std::string> option_words_map;
  option_words_map['r'] = "Rock";
  option_words_map['p'] = "Paper";
  option_words_map['s'] = "Scissors";

  std::cout << "Rock, paper or scissors? Press r, p or s:\n";

  char input = ' ';
  int win_streak = 0;
  bool end = false;

  while (!end && std::cin >> input) {
    if (input_options.count(input)) {
      int random_value = std::rand();
      int random_option_index = random_value % 3;
      char random_option = options[random_option_index];

      std::string input_word = option_words_map[input];
      std::string random_option_word = option_words_map[random_option];
      std::cout << "'" << input_word << "' vs '" << random_option_word << "'\n";

      char finish_option1 = finish_option_map[input];
      char finish_option2 = finish_option_map[random_option];

      if (finish_option1 == random_option) {
        win_streak++;
        std::cout << "Result: You win!\n"
                  << "Win streak: " << win_streak << "\n\n"
                  << "Try one more time:\n";
      } else if (finish_option2 == input) {
        std::cout << "Result: You lost! Hahaha!\n";
        end = true;
      } else {
        std::cout << "Result: Draw!\n\nTry one more time:\n";
      }

    } else {
      std::cout << "Input options '" << input
                << "' is invalid. Try one more time:\n";
    }
  }

  return 0;
}
