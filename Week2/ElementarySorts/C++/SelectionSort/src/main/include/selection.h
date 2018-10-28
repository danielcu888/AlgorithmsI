#ifndef SRC_MAIN_INCLUDE_SELECTION_H_
#define SRC_MAIN_INCLUDE_SELECTION_H_

// C++
#include <cstdlib>
#include <stdexcept>

namespace selectionsort
{
  template<typename T>
  bool less(const T& a, const T& b)
  {
    return a < b;
  }

  template<typename T>
  void exch(T a[], std::size_t i, std::size_t j)
  {
    const T tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

  template<typename T>
  void sort(T a[], std::size_t N)
  {
    if (a == nullptr)
    {
      throw std::logic_error("Illegal Argument - null pointer to array.");
    }

    for (std::size_t i = 0; i < N; ++i)
    {
      std::size_t min = i;
      for (std::size_t j = i; j < N; ++j)
      {
	if (selectionsort::less(a[j], a[min]))
	{
	  min = j;
	}
      }

      selectionsort::exch(a, min, i);
    }
  }

} // ! namespace selectionsort

#endif // ! SRC_MAIN_INCLUDE_SELECTION_H_
