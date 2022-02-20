#include "Soundex.hpp"
#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Start gtest" << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  Soundex soundex;
  auto encoded = soundex.encode("A");
  EXPECT_EQ(encoded, "A");
  EXPECT_EQ(soundex.encode("B"), "B");
  EXPECT_EQ(soundex.encode("E"), "E");
  EXPECT_EQ(soundex.encode("G"), "G");
  EXPECT_EQ(soundex.encode("ö"), "ö");
  EXPECT_EQ(soundex.encode("z"), "z");
}

TEST(SoundexEncoding, PattedSoleLetterOfOneLetterWord) {
  Soundex soundex;
  EXPECT_EQ(soundex.encode("G"), "G000");
  EXPECT_EQ(soundex.encode("A"), "A000");
}