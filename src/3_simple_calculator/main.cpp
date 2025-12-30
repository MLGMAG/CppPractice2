#include <iostream>
#include <string>
#include <set>

std::string to_string(char operation) {
  std::string result = "";

  switch (operation) {
    case '+':
      result = "sum";
      break;
    case '-':
      result = "sub";
      break;
    case '*':
      result = "multiply";
      break;
    case '/':
      result = "division";
      break;
    default:
      break;
  }

  return result;
}

double execute(double lhs, double rhs, char operation) {
  double result = 0.0;
  switch (operation) {
    case '+':
      result = lhs + rhs;
      break;
    case '-':
      result = lhs - rhs;
      break;
    case '*':
      result = lhs * rhs;
      break;
    case '/':
      result = lhs / rhs;
      break;
    default:
      break;
  }

  return result;
}

std::set<char> get_available_operations() {
  std::set<char> operations;

  operations.insert('+');
  operations.insert('-');
  operations.insert('*');
  operations.insert('/');

  return operations;
}

int main() {

  std::set<char> operations = get_available_operations();
  double val1 = 0.0;
  double val2 = 0.0;
  char operation = ' ';

  while (std::cin >> val1 >> val2 >> operation) {
    if (operations.count(operation)) {
      double result = execute(val1, val2, operation);
      std::string operation_string = to_string(operation);
      std::cout << "The " << operation_string << " of " << val1 << " and " << val2 << " is " << result << "\n";
    } else {
      std::cout << "Invalid operation '" << operation << "'\n";
    }
  }

  return 0;
}

