#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>



double get_smaller(double lhs, double rhs) {
  if (lhs > rhs) {
    return rhs;
  }
  return lhs;
}

double get_larger(double lhs, double rhs) {
  if (lhs > rhs) {
    return lhs;
  }
  return rhs;
}

void print_vector(std::vector<double> values) {
  std::cout << "[";

  for (size_t i = 0; i < values.size(); i++) {
    std::cout << values[i];
    if (i != values.size() - 1) {
      std::cout << ", ";
    }
  }

  std::cout << "]\n";
}

int main() {
  constexpr double m_to_cm_koefficient = 100.0;
  constexpr double in_to_cm_koefficient = 2.54;
  constexpr double ft_to_cm_koefficient = 12 * in_to_cm_koefficient;
  constexpr double cm_to_cm_koefficient = 1;

  double largest = 0.0;
  double smallest = 0.0;
  double total_distance = 0.0;
  int numbers_count = 0;

  std::vector<double> values;

  std::map<std::string, double> metrics_map;
  metrics_map["m"] = m_to_cm_koefficient;
  metrics_map["in"] = in_to_cm_koefficient;
  metrics_map["ft"] = ft_to_cm_koefficient;
  metrics_map["cm"] = cm_to_cm_koefficient;

  std::string unit = "";

  for (double tmp; std::cin >> tmp >> unit;) {
    if (metrics_map.count(unit)) {
      double koefficient = metrics_map[unit];
      double cm_value = tmp * koefficient;
      double m_value = cm_value / m_to_cm_koefficient;

      std::cout << "Input value " << m_value << "m ";

      double current_smaller = get_smaller(smallest, m_value);
      double current_largest = get_larger(largest, m_value);

      if (m_value == current_smaller) {
        std::cout << "the smallest so far";
        smallest = m_value;
      } else if (m_value == current_largest) {
        std::cout << "the largest so far";
        largest = m_value;
      }

      std::cout << "\n";

      total_distance += m_value;
      numbers_count++;
      values.push_back(m_value);

    } else {
      std::cout << "Input unit '" << unit << "' is unsupported\n";
    }
  }

  std::cout << "The smallest number: " << smallest << "m\n"
            << "The largest number: " << largest << "m\n"
            << "Number of values: " << numbers_count << "\n"
            << "Total distance: " << total_distance << "m\n";

  std::sort(values.begin(), values.end());
  print_vector(values);

  return 0;
}

