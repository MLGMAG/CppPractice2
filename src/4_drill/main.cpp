#include <iostream>
#include <exception>

int main() {
  try {

    int x = 2;
    double d = 5.0 / x + 2;
    if (d == 2*x + 0.5) std::cout << "Success!\n";

    return 0;
  } catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << "Oops: unknown exception!\n";
    return 2;
  }
}
