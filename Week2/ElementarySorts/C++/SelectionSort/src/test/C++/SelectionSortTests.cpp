// selectionsort
#include "Selection.h"

// Testing
#include <gtest/gtest.h>

namespace selectionsort
{
  namespace selectionsorttesting
  {
    TEST(SelectionSortTests, SortThrowsNullArray)
    {
      ASSERT_THROW(selectionsort::sort<int>(nullptr, 0), std::logic_error);
    }

    TEST(SelectionSortTests, SortTypical)
    {
      int a[] = {1,3,4,2,1,4,5};
      const std::size_t N = 7;
      selectionsort::sort<int>(a, N);
      const int expected[] = {1,1,2,3,4,4,5};
      for (std::size_t i = 0; i < N; ++i)
      {
	ASSERT_EQ(expected[i], a[i]);
      }
    }

  } // ! selectionsorttesting
} // ! selectionsort
