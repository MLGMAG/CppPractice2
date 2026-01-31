#include "base64_utils.hpp"

#include "libbase64.h"
#include <vector>
#include <stdexcept>
#include <sstream>

namespace utils {

std::string base64_encode(const unsigned char *value, const size_t size) {

  const char *data = reinterpret_cast<const char*> (value);
  size_t result_len = (size + 2) / 3 * 4;
  std::vector<unsigned char> out(result_len);

  size_t actual_result_len = 0;

  ::base64_encode(data, size, reinterpret_cast<char *>(out.data()),
                  &actual_result_len, 0);

  if (actual_result_len != result_len) {
    std::stringstream ss;
    ss << "Error in base64 encode, actual result len did not match prediction: "
       << "expected " << result_len << " but got " << actual_result_len;
    throw std::runtime_error(ss.str());
  }

  return std::string(reinterpret_cast<const char *>(out.data()), out.size());
}

std::string base64_encode(const std::string &value) {
  return base64_encode(reinterpret_cast<const unsigned char *>(value.c_str()), value.size());
}

}  // namespace utils

