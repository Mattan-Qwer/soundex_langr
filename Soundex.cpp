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
  std::string returnValue;
  if ('c' == letter or 'j' == letter) {
    returnValue = "2";
  } else {
    returnValue = "1";
  }

  return returnValue;
}
