#include <cstdio>
#include <iostream>

void print_cast_deep_chain_static_cast(unsigned char number) {
  char c_cast = static_cast<char>(number);
  unsigned char i_cast_back = static_cast<int>(c_cast);

  std::cout << "Static cast deep chain:\n"
            << "Input: " << static_cast<int>(number) << "\n"
            << "(unsigned char -> char -> unsigned char): " << static_cast<int>(i_cast_back)
            << "\n\n";
}

void print_cast_chain_static_cast(int number) {
  char c_cast = static_cast<char>(number);
  int c_cast_back = static_cast<int>(c_cast);
  unsigned char uc_cast = static_cast<unsigned char>(number);
  int uc_cast_back = static_cast<int>(uc_cast);

  std::cout << "Static cast chain:\n"
            << "Input: " << number << "\n"
            << "(int -> char -> int): " << c_cast_back << "\n"
            << "(int -> unsigned char -> int): " << uc_cast_back
            << "\n\n";
}

int main() {

  int normal_bound_number = 0;
  print_cast_deep_chain_static_cast(normal_bound_number);

  int out_bound_number = 225;
  print_cast_deep_chain_static_cast(out_bound_number);

  return 0;
}

