#ifndef SOUNDEX_H_
#define SOUNDEX_H_
#include <string>

class Soundex {
public:
  std::string encode(const std::string &word);

private:
  std::string head(const std::string &word);
  std::string zeroPad(const std::string &word);
  std::string encodeDigits(const std::string &word);
  std::string encodeDigit(char letter);
};
#endif