// uf
#include "QuickUnionWithPathHalving.h"

// testing
#include <gtest/gtest.h>

namespace uf
{
  namespace quickunionwithpathhalvingtesting
  {

    TEST(QuickUnionWithPathHalvingTests, Constructor1Parameter)
    {
      QuickUnionWithPathHalving qu(10);
      ASSERT_STREQ(qu.toString().c_str(), "0 1 2 3 4 5 6 7 8 9 ");
    }

    TEST(QuickUnionWithPathHalvingTests, Unify)
    {
      QuickUnionWithPathHalving qu(10);
      qu.unify(0, 1);
      qu.unify(1, 2);
      qu.unify(2, 3);

      ASSERT_STREQ(qu.toString().c_str(), "1 2 3 3 4 5 6 7 8 9 ");

      ASSERT_EQ(qu.find(0), 3);

      ASSERT_STREQ(qu.toString().c_str(), "2 3 3 3 4 5 6 7 8 9 ");
    }

  } // ! namespace quickunionwithpathhalvingtesting
} // ! namespace uf
