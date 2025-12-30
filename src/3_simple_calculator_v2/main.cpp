#include <iostream>
#include <string>
#include <set>
#include <map>

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

double to_double(std::string word, std::map<std::string, double> dictionary) {
  double result = 0.0;
  if (dictionary.count(word)) {
    result = dictionary[word];
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

std::map<std::string, double> get_dictionary() {
  std::map<std::string, double> word_to_number_map;

  word_to_number_map["zero"] = 0.0;
  word_to_number_map["one"] = 1.0;
  word_to_number_map["two"] = 2.0;
  word_to_number_map["three"] = 3.0;
  word_to_number_map["four"] = 4.0;
  word_to_number_map["five"] = 5.0;
  word_to_number_map["six"] = 6.0;
  word_to_number_map["seven"] = 7.0;
  word_to_number_map["eight"] = 8.0;
  word_to_number_map["nine"] = 9.0;

  word_to_number_map["0"] = 0;
  word_to_number_map["1"] = 1.0;
  word_to_number_map["2"] = 2.0;
  word_to_number_map["3"] = 3.0;
  word_to_number_map["4"] = 4.0;
  word_to_number_map["5"] = 5.0;
  word_to_number_map["6"] = 6.0;
  word_to_number_map["7"] = 7.0;
  word_to_number_map["8"] = 8.0;
  word_to_number_map["9"] = 9.0;

  return word_to_number_map;
}

int main() {

  std::set<char> operations = get_available_operations();
  std::map<std::string, double> dictionary = get_dictionary();

  std::string val1_raw = "";
  std::string val2_raw = "";

  char operation = ' ';

  while (std::cin >> val1_raw >> val2_raw >> operation) {
    if (!operations.count(operation)) {
      std::cout << "Invalid operation '" << operation << "'\n";
    } else if (!dictionary.count(val1_raw)) {
      std::cout << "Input number is unsupported or invalid '" << val1_raw << "'\n";
    } else if (!dictionary.count(val2_raw)) {
      std::cout << "Input number is unsupported or invalid '" << val2_raw << "'\n";
    } else {
      double val1 = to_double(val1_raw, dictionary);
      double val2 = to_double(val2_raw, dictionary);
      double result = execute(val1, val2, operation);
      std::string operation_string = to_string(operation);
      std::cout << "The " << operation_string << " of " << val1_raw << " and " << val2_raw << " is " << result << "\n";
    }
  }

  return 0;
}

