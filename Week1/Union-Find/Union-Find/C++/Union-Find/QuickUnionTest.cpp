// uf
#include "QuickUnion.h"

// testing
#include <gtest/gtest.h>

namespace uf
{
  namespace quickuniontesting
  {

    TEST(QuickUnionTests, Constructor1Parameter)
    {
      QuickUnion qu(10);
    }

    TEST(QuickUnionTests, Find)
    {
      QuickUnion qu(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
        ASSERT_EQ(qu.find(i), i);
      }
    }

    TEST(QuickUnionTests, Unify)
    {
      QuickUnion qu(10);
      qu.unify(5,6);
      ASSERT_EQ(qu.find(5), 6);
      ASSERT_EQ(qu.find(6), 6);
    }

  } // ! namespace quickuniontesting
} // ! namespace uf
