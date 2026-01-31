#pragma once

#include <cstddef>
#include <string>

namespace utils {

const size_t KEY_SIZE = 32;
const size_t IV_SIZE = 16;
const size_t MAX_PASSWORD_SIZE = utils::KEY_SIZE;

int encrypt(const unsigned char *plaintext, const int plaintext_len,
            const unsigned char *key, const unsigned char *iv,
            unsigned char *ciphertext);

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext);

void validate_password(const std::string &password);

void init_key(const std::string &password, unsigned char *key,
              const size_t key_size, const unsigned char fillUpValue = ' ');

void init_iv(unsigned char *iv, const size_t iv_size);

}  // namespace utils

