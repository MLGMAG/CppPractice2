#include "utils/openssl_utils.hpp"
#include "utils/base64_utils.hpp"
#include "utils/conversion_utils.hpp"
#include <cstdlib>
#include <iostream>
#include <span>
#include <string>


int main() {
  srand(time(nullptr));

  const std::string password = "hello1234";
  std::cout << "Password: " << password << "\n";
  std::cout << "Key size: " << utils::KEY_SIZE << "\n";
  std::cout << "IV size: " << utils::IV_SIZE << "\n";

  utils::validate_password(password);

  unsigned char key[utils::KEY_SIZE];
  utils::init_key(password, key, utils::KEY_SIZE, ' ');

  std::cout << "Key base64: "
            << utils::base64_encode(std::span{key, utils::KEY_SIZE}) << "\n";
  std::cout << "Key numbers: " << utils::convert_to_numbers(key, utils::KEY_SIZE) << "\n\n";

  unsigned char iv[utils::IV_SIZE];
  utils::init_iv(iv, utils::IV_SIZE);

  std::cout << "IV base64: "
            << utils::base64_encode(std::span{iv, utils::IV_SIZE}) << "\n";
  std::cout << "IV numbers: " << utils::convert_to_numbers(iv, utils::IV_SIZE) << "\n\n";

  const std::string input_text = "The quick brown fox jumps over the lazy dog";
  std::cout << "Input text: " << input_text << "\n";
  std::cout << "Chars count: " << input_text.length() << "\n";
  std::cout << "Input text base64: " << utils::base64_encode(input_text) << "\n\n";

  // Encryption
  const unsigned char *input_text_converted =
      reinterpret_cast<const unsigned char *>(input_text.data());

  const int cipher_text_size = 128;
  unsigned char cipher_text[cipher_text_size];
  std::cout << "Initial cipher array base64: "
            << utils::base64_encode(std::span{cipher_text, cipher_text_size})
            << "\n";
  std::cout << "Initial cipher array numbers: "
            << utils::convert_to_numbers(cipher_text, cipher_text_size) << "\n\n";

  const int encrypted_length =
      utils::encrypt(input_text_converted, input_text.length(), key, iv, cipher_text);

  std::cout << "Encrypted length: " << encrypted_length << "\n";
  std::cout << "Encrypted base64: "
            << utils::base64_encode(std::span{cipher_text, cipher_text_size}) << "\n";
  std::cout << "Encrypted numbers: "
            << utils::convert_to_numbers(cipher_text, cipher_text_size) << "\n\n";

  // decryption
  const int decrypted_text_size = 128;
  unsigned char decrypted_text[decrypted_text_size];
  std::cout << "Initial decrypted array base64: "
            << utils::base64_encode(std::span{decrypted_text, decrypted_text_size}) << "\n";
  std::cout << "Initial decrypted array numbers: "
            << utils::convert_to_numbers(decrypted_text, decrypted_text_size) << "\n\n";

  const int decrypted_length =
      utils::decrypt(cipher_text, encrypted_length, key, iv, decrypted_text);

  std::cout << "Decrypted length: " << decrypted_length << "\n";
  std::cout << "Decrypted base64: "
            << utils::base64_encode(std::span{decrypted_text, decrypted_text_size}) << "\n";
  std::cout << "Decrypted numbers: "
            << utils::convert_to_numbers(decrypted_text, decrypted_text_size) << "\n";

  std::cout << "Decrypted text: " << utils::to_string(decrypted_text, decrypted_length) << "\n\n";

  return 0;
}

