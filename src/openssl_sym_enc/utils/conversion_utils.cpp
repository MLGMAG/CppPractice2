#include "conversion_utils.hpp"

#include <string>
#include <sstream>

namespace utils {

std::string convert_to_numbers(const unsigned char *value, const size_t size) {
  std::stringstream ss;

  for (size_t i = 0; i < size; i++) {
    int current = value[i];
    int converted = static_cast<unsigned int>(current);

    ss << converted;

    if (i != size - 1) {
      ss << " ";
    }
  }

  return ss.str();
}

std::string to_string(const unsigned char *value, const size_t size) {
  std::stringstream ss;

  for (size_t i = 0; i < size; i++) {
    ss << value[i];
  }

  return ss.str();
}

}  // namespace utils
