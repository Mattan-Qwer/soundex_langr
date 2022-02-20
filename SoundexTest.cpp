#include "Soundex.hpp"
#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Start gtest" << std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(SoundexEncoding, PattedSoleLetterOfOneLetterWord) {
  Soundex soundex;
  EXPECT_EQ(soundex.encode("G"), "G000");
  EXPECT_EQ(soundex.encode("A"), "A000");
}