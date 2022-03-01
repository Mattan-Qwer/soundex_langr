#ifndef SOUNDEX_H_
#define SOUNDEX_H_
#include <string>

class Soundex {
public:
  std::string encode(const std::string &word) const;

private:
  static const size_t MaxCodeLength{4};

  std::string head(const std::string &word) const;
  std::string zeroPad(const std::string &word) const;
  std::string encodeDigits(const std::string &word) const;
  std::string encodeDigit(char letter) const;
};
#endif