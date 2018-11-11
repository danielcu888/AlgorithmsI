// dnf
#include "DutchNationalFlag.h"

// testing
#include <gtest/gtest.h>

namespace dnf
{
  TEST(DutchNationalFlagTests, example2)
  {
    const std::deque<dnf::Colour> buckets{Colour::RED, Colour::WHITE, Colour::BLUE, Colour::RED, Colour::WHITE, Colour::BLUE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "BBWWRR";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, example1)
  {
    const std::deque<dnf::Colour> buckets{Colour::WHITE, Colour::RED, Colour::BLUE, Colour::BLUE, Colour::WHITE, Colour::WHITE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "BBWWWR";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, singleW)
  {
    const std::deque<dnf::Colour> buckets{Colour::WHITE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "W";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, singleB)
  {
    const std::deque<dnf::Colour> buckets{Colour::BLUE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "B";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, singleR)
  {
    const std::deque<dnf::Colour> buckets{Colour::RED};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "R";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, allB)
  {
    const std::deque<dnf::Colour> buckets{Colour::BLUE, Colour::BLUE,Colour::BLUE,Colour::BLUE,Colour::BLUE,Colour::BLUE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "BBBBBB";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, allW)
  {
    const std::deque<dnf::Colour> buckets{Colour::WHITE, Colour::WHITE,Colour::WHITE,Colour::WHITE,Colour::WHITE,Colour::WHITE};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "WWWWWW";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }

  TEST(DutchNationalFlagTests, allR)
  {
    const std::deque<dnf::Colour> buckets{Colour::RED, Colour::RED,Colour::RED,Colour::RED,Colour::RED,Colour::RED};
    
    DutchNationalFlag d(buckets);
    d.sort();

    const std::string expected_str = "RRRRRR";
    const std::string actual_str = d.to_string();

    ASSERT_STREQ(expected_str.c_str(), actual_str.c_str());
  }
} // ! namespace dnf
