#include <iostream>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    std::cout << "No arguments passed" << std::endl;
  } else {
    int argumentsCount = argc - 1;
    std::cout << "Arguments count: " << argumentsCount << "\n";
    for (int i = 1; i < argc; i++) {
      std::cout << "Argument #" << i << " value: '" << argv[i] << "'" << "\n";
    }
  }

  return 0;
}
