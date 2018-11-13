// Permutation
#include "Permutation.h"

// Testing
#include <gtest/gtest.h>

namespace permutationtesting
{
  TEST(PermutationTests, example1)
  {
    int a[6] = {1,9,2,4,5,6};
    int b[6] = {2,9,1,4,5,6};

    ASSERT_TRUE(permutation::is_permutation(a,b,6));
  }

  TEST(PermutationTests, example2)
  {
    int a[6] = {1,9,2,4,5,6};
    int b[6] = {2,9,1,4,5,7};

    ASSERT_FALSE(permutation::is_permutation(a,b,6));
  }

} // ! namespace permutationtesting
