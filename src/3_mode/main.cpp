#include <iostream>
#include <map>

int main() {
  std::cout << "Enter sequence of positive numbers:\n";

  std::map<int, int> number_count_map;

  int mode = -1;

  for (int tmp; std::cin >> tmp;) {
    if (tmp >= 0) {
      if (mode == -1) {
        mode = tmp;
      }

      if (!number_count_map.count(tmp)) {
        number_count_map[tmp] = 0;
      }
      number_count_map[tmp] += 1;

      if (number_count_map[tmp] > number_count_map[mode]) {
        mode = tmp;
      }
    }
  }

  if (mode != -1) {
    std::cout << "Mode: " << mode << ", count: " << number_count_map[mode]
              << "\n";
  } else {
    std::cout << "Input sequence is empty\n";
  }

  return 0;
}
