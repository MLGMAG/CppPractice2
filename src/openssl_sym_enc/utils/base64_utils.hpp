#pragma once

#include <string>
#include <span>

namespace utils {

std::string base64_encode(std::span<const unsigned char> value);

std::string base64_encode(const std::string &value);

}  // namespace utils

