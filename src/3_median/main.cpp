#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter number sequence:\n";

  std::vector<double> values;

  for (double temp; std::cin >> temp;) {
    values.push_back(temp);
  }

  if (values.empty()) {
    std::cout << "Input sequence is empty\n";
  } else {
    std::sort(values.begin(), values.end());

    double median = 0.0;

    bool is_size_even = values.size() % 2 == 0;

    if (is_size_even) {
      size_t val1_index = values.size() / 2;
      size_t val2_index = val1_index - 1;
      double val1 = values[val1_index];
      double val2 = values[val2_index];
      median = (val1 + val2) / 2;
    } else {
      size_t middle_val = values.size() / 2;
      median = values[middle_val];
    }

    std::cout << "Median: " << median << "\n";
  }

  return 0;
}

