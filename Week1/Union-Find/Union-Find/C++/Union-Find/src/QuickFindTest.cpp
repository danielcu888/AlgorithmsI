// uf
#include "QuickFind.h"

// testing
#include <gtest/gtest.h>

// C++
#include <iostream>
#include <cstdlib>

namespace uf
{
  namespace qftesting
  {
    TEST(QuickFindTests, Constructor1Parameter)
    {
      uf::QuickFind qf(10);
    }

    TEST(QuickFindTests, Find)
    {
      uf::QuickFind qf(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
        ASSERT_EQ(qf.find(i), i);
      }
    }

    TEST(QuickFindTests, Unify)
    {
      uf::QuickFind qf(10);
      qf.unify(5,6);
      ASSERT_EQ(qf.find(5), 6);
      ASSERT_EQ(qf.find(6), 6);
    }

  } // ! namespace qftesting
} // ! namespace uf
