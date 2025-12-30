#include <iostream>

int main() {
  std::cout << "Enter number of grains:\n";

  int limit = 0;
  while (std::cin >> limit) {
    double result = 1.0;
    int counter = 1;
    std::cout << counter << " squares - " << result << " grains\n";

    while (result < limit) {
      result *= 2.0;
      counter++;
      std::cout << counter << " squares - " << result << " grains\n";
    }

    std::cout << counter << " squares is enough for " << limit << "\n\n";
  }

  return 0;
}
