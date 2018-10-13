// uf
#include "WeightedQuickUnion.h"

// testing
#include <gtest/gtest.h>

namespace uf
{
  namespace weightedquickuniontesting
  {
    TEST(WeightedQuickUnionTests, Constructor1Parameter)
    {
      WeightedQuickUnion wqu(10);
    }

    TEST(WeightedQuickUnionTests, Find)
    {
      WeightedQuickUnion wqu(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
        ASSERT_EQ(wqu.find(i), i);
      }
    }

    TEST(WeightedQuickUnionTests, Unify)
    {
      WeightedQuickUnion wqu(10);
      wqu.unify(5,6);
      ASSERT_EQ(wqu.find(5), 6);
      ASSERT_EQ(wqu.find(6), 6);
    }

    TEST(WeightedQuickUnionTests, UnifyEquallyHeightedTrees)
    {
      WeightedQuickUnion wqu(8);

      wqu.unify(0,1);
      wqu.unify(2,3);
      wqu.unify(4,5);
      wqu.unify(6,7);

      ASSERT_EQ(wqu.find(0), 1);
      ASSERT_EQ(wqu.find(1), 1);
      ASSERT_EQ(wqu.find(2), 3);
      ASSERT_EQ(wqu.find(3), 3);
      ASSERT_EQ(wqu.find(4), 5);
      ASSERT_EQ(wqu.find(5), 5);
      ASSERT_EQ(wqu.find(6), 7);
      ASSERT_EQ(wqu.find(7), 7);

      wqu.unify(1,3);
      wqu.unify(5,7);

      ASSERT_EQ(wqu.find(0), 3);
      ASSERT_EQ(wqu.find(1), 3);
      ASSERT_EQ(wqu.find(2), 3);
      ASSERT_EQ(wqu.find(3), 3);
      ASSERT_EQ(wqu.find(4), 7);
      ASSERT_EQ(wqu.find(5), 7);
      ASSERT_EQ(wqu.find(6), 7);
      ASSERT_EQ(wqu.find(7), 7);

      wqu.unify(3, 7);

      ASSERT_EQ(wqu.find(0), 7);
      ASSERT_EQ(wqu.find(1), 7);
      ASSERT_EQ(wqu.find(2), 7);
      ASSERT_EQ(wqu.find(3), 7);
      ASSERT_EQ(wqu.find(4), 7);
      ASSERT_EQ(wqu.find(5), 7);
      ASSERT_EQ(wqu.find(6), 7);
      ASSERT_EQ(wqu.find(7), 7);
    }

    TEST(WeightedQuickUnionTests, UnifyUnequalHeightedTrees)
    {
      WeightedQuickUnion wqu(8);

      wqu.unify(0,1);
      wqu.unify(1,2);
      wqu.unify(2,3);

      ASSERT_EQ(wqu.find(0), 1);
      ASSERT_EQ(wqu.find(1), 1);
      ASSERT_EQ(wqu.find(2), 1);
      ASSERT_EQ(wqu.find(3), 1);
    }

  } // ! namespace weightedquickuniontesting
} // ! namespace uf
