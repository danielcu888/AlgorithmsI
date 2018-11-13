#ifndef SRC_MAIN_INCLUDE_PERMUTATION_H_
#define SRC_MAIN_INCLUDE_PERMUTATION_H_

// C++
#include <cstddef>

namespace permutation
{
  void insertion_sort(int a[], std::size_t n);
  bool is_permutation(int a[], int b[], std::size_t n);

} // ! namespace perrmutation

#endif // ! SRC_MAIN_INCLUDE_PERMUTATION_H_
