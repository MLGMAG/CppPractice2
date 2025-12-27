#include <iostream>

int main() {

  constexpr double yen_koefficient = 0.0064;
  constexpr double kroner_koefficient = 0.100;
  constexpr double pounds_koefficient = 1.35;

  double amount = 0;
  char unit = ' ';

  std::cout
      << "Please enter a amount followed by a currency unit (y, k or p):\n";

  std::cin >> amount >> unit;

  if (unit == 'y') {
    std::cout << amount << " yen is " << amount * yen_koefficient
              << " dollars\n";
  } else if (unit == 'k') {
    std::cout << amount << " kronner is " << amount * kroner_koefficient
              << " dollars\n";
  } else if (unit == 'p') {
    std::cout << amount << " pounds is " << amount * pounds_koefficient
              << " dollars\n";
  } else {
    std::cout << "The unit '" << unit << "' is not supported\n";
  }

  return 0;
}

