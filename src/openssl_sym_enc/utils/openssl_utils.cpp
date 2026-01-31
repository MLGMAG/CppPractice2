#include "openssl_utils.hpp"

#include <stdexcept>
#include <sstream>
#include "openssl/evp.h"


namespace utils {

int encrypt(const unsigned char *plaintext, const int plaintext_len,
            const unsigned char *key, const unsigned char *iv,
            unsigned char *ciphertext) {
  EVP_CIPHER_CTX *ctx;
  int len;

  if (!(ctx = EVP_CIPHER_CTX_new())) {
    throw std::runtime_error("Could not allocate cipher context");
  }

  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key, iv)) {
    throw std::runtime_error("Could not setup cipher context");
  }

  if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
    throw std::runtime_error("Could not encrypt input text");
  }
  int ciphertext_len = len;

  if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
    throw std::runtime_error("Could not encrypt 'final' data");
  }

  ciphertext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
  EVP_CIPHER_CTX *ctx;
  int len;
  int plaintext_len;

  if (!(ctx = EVP_CIPHER_CTX_new())) {
    throw std::runtime_error("Could not allocate cipher context");
  }

  if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    throw std::runtime_error("Could not setup cipher context");
  }

  if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
    throw std::runtime_error("Could not decrypt input text");
  }
  plaintext_len = len;

  if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
    throw std::runtime_error("Could not decrypt 'final' data");
  }

  plaintext_len += len;

  EVP_CIPHER_CTX_free(ctx);

  return plaintext_len;
}

void validate_password(const std::string &password) {
  if (password.length() > MAX_PASSWORD_SIZE) {
    std::stringstream ss;
    ss << "Password length '" << password.length() << "'"
       << " is greater than limit '" << MAX_PASSWORD_SIZE << "'";
    throw std::runtime_error(ss.str());
  }
}

void init_key(const std::string &password, unsigned char *key,
              const size_t key_size, const unsigned char fillUpValue) {
  for (size_t i = 0; i < password.length(); i++) {
    char current = password[i];
    unsigned char converted = static_cast<unsigned char>(current);
    key[i] = converted;
  }

  for (size_t i = password.length(); i < key_size; i++) {
    key[i] = fillUpValue;
  }
}

void init_iv(unsigned char *iv, const size_t iv_size) {
  for (size_t i = 0; i < iv_size; i++) {
    int generated = rand() % 256;
    unsigned char converted = static_cast<unsigned char>(generated);
    iv[i] = converted;
  }
}

}  // namespace utils

