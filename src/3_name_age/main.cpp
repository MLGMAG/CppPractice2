#include <string>
#include <iostream>


int main() {
  std::string name = "";
  double age = 0;

  std::cout << "Please enter your first name and age:\n";

  std::cin >> name >> age;

  int years = static_cast<int>(age);

  int months = (age - years) * 12;

  std::cout << "Hello " << name << " your age is " << years << " years and " << months << " months" << "!\n";

  return 0;
}

