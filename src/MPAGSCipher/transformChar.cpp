#include<string>

#include "transformChar.hpp"

std::string transformChar(const char in_char){
  /*  
    transform an input character into an upper case alphabetical, ignoring non alphanumerical
    and converting numerical into corresponding string

    const char in_char input charachter

    returns a string because sometimes a single letter will return sometimes a whole word

    special return case where character is non-alphanumeric, return empty string

  */

  // Uppercase alphabetic characters
    if (std::isalpha(in_char)) {
      return std::string(1,std::toupper(in_char));
      
    }

    // Transliterate digits to English words
    switch (in_char) {
      case '0':
        return "ZERO";
      case '1':
        return "ONE";
      case '2':
        return "TWO";
      case '3':
        return "THREE";
      case '4':
        return "FOUR";
      case '5':
        return "FIVE";
      case '6':
        return "SIX";
      case '7':
        return "SEVEN";
      case '8':
        return "EIGHT";
      case '9':
        return "NINE";
      default:
        return "";
    }
    // If the character isn't alphabetic or numeric, DONT add it,return an empty string.
    // Our ciphers can only operate on alphabetic characters.
}
