#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::cout << "Enter name and score in sequence: (like James 10 Mike 18)\n";
  std::cout << "Terminate sequence with NoName 0\n";

  std::string name = "";
  int score = 0;
  bool is_end = false;

  std::map<std::string, int> name_score_map;
  std::map<int, std::vector<std::string>> score_names_map;

  while (!is_end) {
    if (!(std::cin >> name >> score)) {
      is_end = true;
    } else if (name == "NoName" && score == 0) {
      is_end = true;
    } else if (name_score_map.count(name)) {
      std::cout << "Name '" << name << "' is already present\n";
    } else {
      name_score_map[name] = score;

      if (!score_names_map.count(score)) {
        score_names_map[score] = std::vector<std::string>();
      }

      score_names_map[score].push_back(name);
    }
  }

  std::cout << "\nNames:\n";
  for (const auto& pair : name_score_map) {
    std::cout << pair.first << " - " << pair.second << "\n";
  }

//  std::string user_input = "";
//  std::cout << "\nEnter name:\n";
//
//  while (std::cin >> user_input) {
//    if (name_score_map.count(user_input)) {
//      std::cout << user_input << " has " << name_score_map[user_input]
//                << " scores\n";
//    } else {
//      std::cout << "'" << user_input << "' is not found\n";
//    }
//  }

  int user_input = 0;
  std::cout << "\nEnter score:\n";
  while (std::cin >> user_input) {
    if (score_names_map.contains(user_input)) {
      std::vector<std::string> names = score_names_map[user_input];
      std::cout << "\nNames with score " << user_input << ":\n";
      for (std::string name : names) {
        std::cout << name << "\n";
      }
      std::cout << "\n";
    } else {
      std::cout << "\nNo names with score " << user_input << "\n\n";
    }
  }

  return 0;
}
