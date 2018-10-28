#ifndef SRC_MAIN_INCLUDE_INSERTION_SORT_H_
#define SRC_MAIN_INCLUDE_INSERTION_SORT_H_

// C++
#include <cstdlib>
#include <stdexcept>

namespace insertionsort
{
  template<typename T>
  void exch(T a[], std::size_t i, std::size_t j)
  {
    const T tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

  template<typename T>
  bool less(T a[], std::size_t i, std::size_t j)
  {
    return a[i] < a[j];
  }

  template<typename T>
  void sort(T a[], std::size_t N)
  {
    if (a == nullptr)
    {
      throw std::logic_error("Invalid argument - null array.");
    }

    for (std::size_t i = 0; i < N-1; ++i)
    {
      for (std::size_t j = i+1; j > 0; --j)
      {
	if (insertionsort::less(a, j, j-1))
	{
	  insertionsort::exch(a, j, j-1);
	}
      }
    }
  }

} // ! namespace insertionsort

#endif // ! SRC_MAIN_INCLUDE_INSERTION_SORT_H_
