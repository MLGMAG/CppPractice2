#pragma once

#include <cstddef>
#include <string>

namespace utils {

std::string base64_encode(const unsigned char *value, const size_t size);

std::string base64_encode(const std::string &value);

}  // namespace utils

