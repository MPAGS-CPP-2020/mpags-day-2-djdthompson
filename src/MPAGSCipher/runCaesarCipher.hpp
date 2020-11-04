#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP //this must be unique

#include <string>

//Convert input string into desired user output: decrypt an encrypted phrase or encrypt a phrase (of pre-filtered, upper-case, alphabetical characters) according to given key.
std::string runCaesarCipher(const std::string& inpText, const size_t key, const bool encrypt);

#endif //MPAGSCIPHER_CAESARCIPHER_HPP container to prevent code being included multiple times