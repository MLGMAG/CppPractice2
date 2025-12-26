#include <iostream>

int main() {

  std::cout << "Enter number of miles:\n";

  double miles = 0;

  std::cin >> miles;

  double kilometers = miles * 1.609;

  std::cout << miles << " miles is " << kilometers << " killometers.\n";

  return 0;
}

