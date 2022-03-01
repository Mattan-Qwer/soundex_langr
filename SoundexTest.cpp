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
  EXPECT_EQ(soundex.encode("Zl"), "Z400");
  EXPECT_EQ(soundex.encode("pt"), "p300");
  EXPECT_EQ(soundex.encode("tr"), "t600");
  EXPECT_EQ(soundex.encode("Rm"), "R500");
}

TEST_F(SoundexEncoding, TotalWords) {
  EXPECT_EQ(soundex.encode("Helpw"), "H410");
  EXPECT_EQ(soundex.encode("tragisch"), "t622");
}

TEST_F(SoundexEncoding, DoubleConsonats) {
  EXPECT_EQ(soundex.encode("Affen"), "A150");
  EXPECT_EQ(soundex.encode("Zimmerplanze"), "Z561");
}