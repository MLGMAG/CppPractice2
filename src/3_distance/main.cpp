#include <iostream>
#include <vector>
#include <algorithm>


double sum(std::vector<double> values) {

  double result = 0.0;
  for (double value : values) {
    result += value;
  }

  return result;
}


int main() {
  std::cout << "Enter distances in sequence:\n";

  std::vector<double> distances;

  for (double temp; std::cin >> temp;) {
    distances.push_back(temp);
  }

  if (!distances.empty()) {
    std::sort(distances.begin(), distances.end());

    double smallest = distances[0];
    double longest = distances[distances.size() - 1];
    double total_distance = sum(distances);
    double mean = total_distance / distances.size();

    std::cout << "Total distance: " << total_distance << "\n"
              << "Smallest: " << smallest << "\n"
              << "Longest: " << longest << "\n"
              << "Mean: " << mean << "\n";
  } else {
    std::cout << "Distances sequence is empty";
  }

  return 0;
}

