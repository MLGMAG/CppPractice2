#include <iostream>

int main() {

  double d = 0;

  while (std::cin >> d) {
    int i = d;
    char c = i;
    std::cout << "d == " << d << "\n"
              << "i == " << i << "\n"
              << "c == " << c << "\n"
              << "char(" << c << ")\n";
  }

  return 0;
}

