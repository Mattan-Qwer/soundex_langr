#include "Soundex.hpp"
#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Start gtest" << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class SoundexEncoding : public ::testing::Test {

public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, PattedSoleLetterOfOneLetterWord) {
  EXPECT_EQ(soundex.encode("G"), "G000");
  EXPECT_EQ(soundex.encode("A"), "A000");
}

TEST_F(SoundexEncoding, PattedTwoLetterOfGroupOne) {
  EXPECT_EQ(soundex.encode("Gb"), "G100");
  EXPECT_EQ(soundex.encode("Ab"), "A100");
}

TEST_F(SoundexEncoding, PattedTwoLetterOfGroup2) {
  EXPECT_EQ(soundex.encode("Gj"), "G200");
  EXPECT_EQ(soundex.encode("Ac"), "A200");
}