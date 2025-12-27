#include <iostream>

int main() {
  constexpr double yen_koefficient = 0.0064;
  constexpr double kroner_koefficient = 0.100;
  constexpr double pounds_koefficient = 1.35;
  constexpr double swiss_francs_koefficient = 1.27;

  double amount = 0;
  char unit = ' ';

  std::cout
      << "Please enter a amount followed by a currency unit (y, k, p or f):\n";

  std::cin >> amount >> unit;

  switch (unit) {
    case 'y': {
      std::cout << amount << " yen is " << amount * yen_koefficient
                << " dollars\n";
      break;
    }
    case 'k': {
      std::cout << amount << " kronner is " << amount * kroner_koefficient
                << " dollars\n";
      break;
    }
    case 'p': {
      std::cout << amount << " pounds is " << amount * pounds_koefficient
                << " dollars\n";
      break;
    }
    case 'f': {
      std::cout << amount << " swiss francs is "
                << amount * swiss_francs_koefficient << " dollars\n";
      break;
    }
    default: {
      std::cout << "The unit '" << unit << "' is not supported\n";
      break;
    }
  }

  return 0;
}

