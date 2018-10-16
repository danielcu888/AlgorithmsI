// sba
#include "SearchInBitonicArray.h"

// testing
#include <gtest/gtest.h>

namespace sba
{
  namespace sbatesting
  {
    TEST(SearchInBitonicArray, ConstructorOneParameter)
    {
      const std::deque<int> ba {2,4,6,8,5,3,1};
      sba::SearchInBitonicArray s(ba);
    }

    TEST(SearchInBitonicArray, ContainsSequential)
    {
      const std::deque<int> ba {1,2,3,6,5,4};
      const sba::SearchInBitonicArray s(ba);

      ASSERT_TRUE(s.contains(1));
      ASSERT_TRUE(s.contains(2));
      ASSERT_TRUE(s.contains(3));
      ASSERT_TRUE(s.contains(4));
      ASSERT_TRUE(s.contains(5));
      ASSERT_TRUE(s.contains(6));
    }

    TEST(SearchInBitonicArray, ContainsNonSequential)
    {
      const std::deque<int> ba {1,56,1901,333,21,4};
      const sba::SearchInBitonicArray s(ba);

      ASSERT_FALSE(s.contains(0));
      ASSERT_TRUE(s.contains(1));
      ASSERT_FALSE(s.contains(28));
      ASSERT_TRUE(s.contains(56));
      ASSERT_FALSE(s.contains(129));
      ASSERT_TRUE(s.contains(1901));
      ASSERT_FALSE(s.contains(2313));
      ASSERT_FALSE(s.contains(1000));
      ASSERT_TRUE(s.contains(333));
      ASSERT_FALSE(s.contains(77));
      ASSERT_TRUE(s.contains(21));
      ASSERT_FALSE(s.contains(8));
      ASSERT_TRUE(s.contains(4));
      ASSERT_FALSE(s.contains(-9));
    }

    TEST(SearchInBitonicArray, ContainsMonoTonic)
    {
      const std::deque<int> ba {1,4,21,56,333,1901};
      const sba::SearchInBitonicArray s(ba);

      ASSERT_FALSE(s.contains(0));
      ASSERT_TRUE(s.contains(1));
      ASSERT_FALSE(s.contains(28));
      ASSERT_TRUE(s.contains(56));
      ASSERT_FALSE(s.contains(129));
      ASSERT_TRUE(s.contains(1901));
      ASSERT_FALSE(s.contains(2313));
      ASSERT_FALSE(s.contains(1000));
      ASSERT_TRUE(s.contains(333));
      ASSERT_FALSE(s.contains(77));
      ASSERT_TRUE(s.contains(21));
      ASSERT_FALSE(s.contains(8));
      ASSERT_TRUE(s.contains(4));
      ASSERT_FALSE(s.contains(-9));
    }

    TEST(SearchInBitonicArray, ContainsMonoTonicReversed)
    {
      const std::deque<int> ba {1901,333,56,21,4,1};
      const sba::SearchInBitonicArray s(ba);

      ASSERT_FALSE(s.contains(0));
      ASSERT_TRUE(s.contains(1));
      ASSERT_FALSE(s.contains(28));
      ASSERT_TRUE(s.contains(56));
      ASSERT_FALSE(s.contains(129));
      ASSERT_TRUE(s.contains(1901));
      ASSERT_FALSE(s.contains(2313));
      ASSERT_FALSE(s.contains(1000));
      ASSERT_TRUE(s.contains(333));
      ASSERT_FALSE(s.contains(77));
      ASSERT_TRUE(s.contains(21));
      ASSERT_FALSE(s.contains(8));
      ASSERT_TRUE(s.contains(4));
      ASSERT_FALSE(s.contains(-9));
    }
    
  } // ! namespace sbatesting
} // ! namespace sba
