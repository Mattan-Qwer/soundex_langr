#ifndef SOUNDEX_H_
#define SOUNDEX_H_
#include <string>

class Soundex {
public:
  std::string encode(const std::string &word);
};
#endif