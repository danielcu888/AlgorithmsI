// permutation
#include "Permutation.h"

namespace permutation
{
  void insertion_sort(int a[], std::size_t n)
  {
    for (std::size_t i = 0; i < n; ++i)
    {
      for (std::size_t j = i; j > 0; --j)
      {
	if (a[j] < a[j-1])
	{
	  const int tmp = a[j];
	  a[j] = a[j-1];
	  a[j-1] = tmp;
	}
      }
    }
  }

  bool is_permutation(int a[], int b[], std::size_t n)
  {
    insertion_sort(a, n);
    insertion_sort(b, n);
    for (std::size_t i = 0; i < n; ++i)
    {
      if (a[i] != b[i])
      {
	return false;
      }
    }
    return true;
  }
} // ! namespace perrmutation
