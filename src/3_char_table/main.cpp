#include <iostream>

int main() {

  for (int i = 48; i < 123; i++) {
    char c = static_cast<char>(i);
    std::cout << c << "\t" << i << "\n";
  }

  return 0;
}

