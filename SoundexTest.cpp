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
  EXPECT_EQ(soundex.encode("tragisch"), "t620");
}

TEST_F(SoundexEncoding, DoubleConsonats) {
  EXPECT_EQ(soundex.encode("Affen"), "A150");
  EXPECT_EQ(soundex.encode("Zimmerplanze"), "Z561");
}

TEST_F(SoundexEncoding, DoubleCodedLetters) {
  EXPECT_EQ(soundex.encode("Alcjr"), "A426");
  EXPECT_EQ(soundex.encode("Zimnerplanze"), "Z561");
}

TEST_F(SoundexEncoding, DoubleCodedLettersSeperatedBySilentLetter) {
  EXPECT_EQ(soundex.encode("Alchjr"), "A426");
  EXPECT_EQ(soundex.encode("Zimwnerplanze"), "Z561");
}

TEST_F(SoundexEncoding, DoubleCodedLettersSeperatedByVocal) {
  EXPECT_EQ(soundex.encode("Alcajr"), "A422");
  EXPECT_EQ(soundex.encode("Zimanerplanze"), "Z556");
}

TEST_F(SoundexEncoding, DoNotCareAboutCapitalLetters) {
  EXPECT_EQ(soundex.encode("AlCajR"), "A422");
  EXPECT_EQ(soundex.encode("ZimaNerPlanze"), "Z556");
}

TEST_F(SoundexEncoding, UseNoneLetterChars) {
  EXPECT_EQ(soundex.encode("AlC/jR"), "A422");
  EXPECT_EQ(soundex.encode("Z#maNerPl#nze"), "Z556");
}