#include "Soundex.hpp"
std::string Soundex::encode(const std::string &word) {
  return zeroPad(head(word) + encodeDigits(word));
};

std::string Soundex::head(const std::string &word) { return word.substr(0, 1); }

std::string Soundex::zeroPad(const std::string &word) {
  auto zeroNeeded = 4 - word.length();
  return {word + std::string(zeroNeeded, '0')};
}

std::string Soundex::encodeDigits(const std::string &word) {
  std::string encodedDigits = "";
  if (word.length() > 1) {
    encodedDigits = encodeDigit(word[1]);
  }
  return encodedDigits;
}

std::string Soundex::encodeDigit(char letter) {
  std::string returnValue = "";
  switch (letter) {
  case 'b':
  case 'f':
  case 'p':
  case 'v':
    returnValue = "1";
    break;
  case 'c':
  case 'j':
  case 'k':
  case 'q':
  case 's':
  case 'x':
  case 'z':
    returnValue = "2";
    break;
  case 'd':
  case 't':
    returnValue = "3";
    break;
  case 'l':
    return "4";
    break;
  case 'm':
  case 'n':
    returnValue = "5";
    break;
  case 'r':
    returnValue = "6";
    break;
  default:
    break;
  }

  return returnValue;
}
