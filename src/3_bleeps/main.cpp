#include <iostream>
#include <set>
#include <string>

int main() {

  std::cout << "Enter words:\n";

  std::set<std::string> bleep_words;
  bleep_words.insert("broccoli");
  bleep_words.insert("vassabi");
  bleep_words.insert("gpt");

  std::string current_word = "";
  while (std::cin >> current_word) {
    if (!bleep_words.contains(current_word)) {
      std::cout << current_word << "\n";
    } else {
      std::cout << "BLEEP\n";
    }
  }

  return 0;
}

