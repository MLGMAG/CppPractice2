#include <iostream>
#include <cmath>

int main() {

  std::cout << "Please enter integer value: ";

  int a = 0;
  std::cin >> a;

  std::cout << "a == " << a << "\n"
            << "a + 1 == " << a + 1 << "\n"
            << "three times a == " << 3 * a << "\n"
            << "twice a == " << a + a << "\n"
            << "a squared == " << a * a << "\n"
            << "half of a == " << a / 2 << "\n"
            << "a % 2 == " << a % 2 << "\n"
            << "square root of a == " << sqrt(a) << "\n";

    return 0;
}

