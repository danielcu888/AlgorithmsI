// ts
#include "ThreeSumInQuadraticTime.h"

// Testing
#include <gtest/gtest.h>

namespace ts
{
  namespace tstesting
  {
    TEST(ThreeSumInQuadraticTimeTests, ConstructorOneParamNoValues)
    {
      std::deque<int> v;
      ts::ThreeSumInQuadraticTime t(v);
      ASSERT_TRUE(t.threeSums().empty());
    }

    TEST(ThreeSumInQuadraticTimeTests, ConstructorOneParamThreeValuesNoSum)
    {
      std::deque<int> v {1,2,3};
      ts::ThreeSumInQuadraticTime t(v);
      ASSERT_TRUE(t.threeSums().empty());
    }

    TEST(ThreeSumInQuadraticTimeTests, ConstructorOneParamThreeValues)
    {
      std::deque<int> v {1,2,-3};
      ts::ThreeSumInQuadraticTime t(v);
      const std::deque<std::tuple<int, int, int>> tss = t.threeSums();
      ASSERT_EQ(tss.size(), 1);
      const std::tuple<int,int,int> s = tss[0];
      ASSERT_EQ(std::get<0>(s), 0);
      ASSERT_EQ(std::get<1>(s), 1);
      ASSERT_EQ(std::get<2>(s), 2);
    }

    TEST(ThreeSumInQuadraticTimeTests, ConstructorOneParamTwoSums)
    {
      std::deque<int> v {-6,-2,0,2,8};
      ts::ThreeSumInQuadraticTime t(v);
      const std::deque<std::tuple<int, int, int>> tss = t.threeSums();
      ASSERT_EQ(tss.size(), 2);

      // First 3-sum.
      std::tuple<int,int,int> s = tss[0];
      ASSERT_EQ(std::get<0>(s), 0);
      ASSERT_EQ(std::get<1>(s), 1);
      ASSERT_EQ(std::get<2>(s), 4);

      // Second 3-sum.
      s = tss[1];
      ASSERT_EQ(std::get<0>(s), 1);
      ASSERT_EQ(std::get<1>(s), 2);
      ASSERT_EQ(std::get<2>(s), 3);
    }
  } // ! namespace tstesting
} // ! namespace ts
