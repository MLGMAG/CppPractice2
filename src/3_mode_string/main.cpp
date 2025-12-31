#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cctype>

std::string sanitize(const std::string& input,
                     const std::set<std::string>& ban_chars) {
  std::string result;
  for (size_t i = 0; i < input.size(); i++) {
    char current_char = std::tolower(input[i]);
    int current_int = static_cast<int>(current_char);
    if (current_int > 0) {
      std::string string_representation{current_char};
      if (!ban_chars.contains(string_representation)) {
        result.append(string_representation);
      }
    }
  }

  return result;
}

int main() {
  std::cout << "Enter sequence of words:\n";

  std::map<std::string, int> word_count_map;

  std::set<std::string> ban_chars;
  ban_chars.insert(",");
  ban_chars.insert(".");
  ban_chars.insert(";");
  ban_chars.insert("!");
  ban_chars.insert("?");
  ban_chars.insert("'");
  ban_chars.insert("\"");
  ban_chars.insert("—");
  ban_chars.insert(":");
  ban_chars.insert("(");
  ban_chars.insert(")");

  std::string min_string = "";
  std::string max_string = "";
  std::string mode_string = "";

  for (std::string tmp; std::cin >> tmp;) {
    std::string sanitized_input = sanitize(tmp, ban_chars);
    if (sanitized_input.size() > 0) {
      if (mode_string == "") {
        mode_string = sanitized_input;
      }

      if (max_string == "") {
        max_string = sanitized_input;
      }

      if (min_string == "") {
        min_string = sanitized_input;
      }

      if (sanitized_input.size() > max_string.size()) {
        max_string = sanitized_input;
      }

      if (sanitized_input.size() < min_string.size()) {
        min_string = sanitized_input;
      }

      if (!word_count_map.count(sanitized_input)) {
        word_count_map[sanitized_input] = 0;
      }

      word_count_map[sanitized_input]++;

      if (word_count_map[sanitized_input] > word_count_map[mode_string]) {
        mode_string = sanitized_input;
      }
    }
  }

  std::cout << "Min: '" << min_string << "'\n"
            << "Max: '" << max_string << "'\n"
            << "Mode: '" << mode_string << "'"
            << ", count: " << word_count_map[mode_string] << "\n";
  return 0;
}
