#include <cmath>
#include <iostream>

int main() {
  double a_parameter = 0;
  double b_parameter = 0;
  double c_parameter = 0;

  std::cout << "Enter a, b and c parameters of quadratic equation:\n";

  std::cin >> a_parameter >> b_parameter >> c_parameter;

  if (a_parameter != 0) {
    double discriminant_left_part = std::pow(b_parameter, 2);
    double discriminant_right_part = 4 * a_parameter * c_parameter;
    double discriminant = discriminant_left_part - discriminant_right_part;

    std::cout << "The discriminant is " << discriminant << "\n";

    if (discriminant < 0) {
      std::cout << "No roots\n";
    } else if (discriminant == 0) {
      double root = -1 * b_parameter / 2 * a_parameter;
      std::cout << "One root: " << root << "\n";
    } else {
      double root1 = (-1 * b_parameter + std::sqrt(discriminant)) / 2 * a_parameter;
      double root2 = (-1 * b_parameter - std::sqrt(discriminant)) / 2 * a_parameter;
      std::cout << "Two roots: " << root1 << " " << root2 << "\n";
    }
  } else {
    std::cout << "The 'a' parameter could not be 0\n";
  }
}
