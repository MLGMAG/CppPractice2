#include <iostream>

int main() {
  int x1 = 7.8;

  int x2{7.8};

  int x3 = {7.8};

  int x4(7.8);

  std::cout << "x1 == " << x1 << "\n"
            << "x2 == " << x2 << "\n"
            << "x3 == " << x3 << "\n"
            << "x4 == " << x4 << "\n";

  return 0;
}
