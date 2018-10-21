// stack
#include "FixedArrayStack.h"

// Testing
#include <gtest/gtest.h>

namespace stack
{
  namespace stacktesting
  {
    TEST(StackTests, ConstructorOneParameter)
    {
      FixedArrayStack<int> st(10);
    }

  } // ! namespace stacktesting
} // ! namespace stack
