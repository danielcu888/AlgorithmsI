// swd
#include "SuccessorWithDelete.h"

// testing
#include <gtest/gtest.h>

namespace swd
{
  namespace swdtesting
  {
    TEST(SuccessorWithDeleteTests, ConstructorOneParam)
    {
      swd::SuccessorWithDelete s(10);
    }

    TEST(SuccessorWithDeleteTests, RemoveOneElement)
    {
      swd::SuccessorWithDelete s(10);
      s.remove(5);
    }

    TEST(SuccessorWithDeleteTests, SuccessorNoneRemoved)
    {
      const swd::SuccessorWithDelete::size_type N = 10;
      swd::SuccessorWithDelete s(N);
      for (swd::SuccessorWithDelete::size_type x = 0; x < N-1; ++x)
      {
	ASSERT_EQ(s.successor(x), x);
      }

      ASSERT_EQ(s.successor(N-1), swd::SuccessorWithDelete::INVALID_INDEX);
    }

    TEST(SuccessorWithDeleteTests, SuccessorOneRemoved)
    {
      const swd::SuccessorWithDelete::size_type N = 10;
      swd::SuccessorWithDelete s(N);
      s.remove(5);
      for (swd::SuccessorWithDelete::size_type x = 0; x < N-1; ++x)
      {
	if (x == 5)
	{
	  ASSERT_EQ(s.successor(5), 6);	  
	}
	else
	{
	  ASSERT_EQ(s.successor(x), x);
	}
      }
      ASSERT_EQ(s.successor(N-1), swd::SuccessorWithDelete::INVALID_INDEX);
    }

    TEST(SuccessorWithDeleteTests, SuccessorManyRemoved)
    {
      const swd::SuccessorWithDelete::size_type N = 9;
      swd::SuccessorWithDelete s(N);
      s.remove(2);
      s.remove(3);
      s.remove(5);
      s.remove(8);
      ASSERT_EQ(s.successor(0), 0);
      ASSERT_EQ(s.successor(1), 1);
      ASSERT_EQ(s.successor(2), 4);
      ASSERT_EQ(s.successor(3), 4);
      ASSERT_EQ(s.successor(4), 4);
      ASSERT_EQ(s.successor(5), 6);
      ASSERT_EQ(s.successor(6), 6);
      ASSERT_EQ(s.successor(7), 7);
      ASSERT_EQ(s.successor(8), swd::SuccessorWithDelete::INVALID_INDEX);
    }

  } // ! namespace swdtesting
} // ! namespace swd
