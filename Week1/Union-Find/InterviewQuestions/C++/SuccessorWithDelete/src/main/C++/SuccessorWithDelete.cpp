// swd
#include "SuccessorWithDelete.h"

// Boost
#include <boost/lexical_cast.hpp>

// C++
#include <stdexcept>
#include <string>

namespace swd
{
  SuccessorWithDelete::SuccessorWithDelete(size_type N)
    : m_N(N)
    , m_uf(N)
    , m_removed(N, false)
  {}

  void SuccessorWithDelete::remove(size_type x)
  {
    this->check(x);

    if (!this->m_removed[x])
    {
      this->m_removed[x] = true;

      if (x > 0)
      {
	// check x-1
	if (this->m_removed[x-1])
	{
	  // x-1 has been removed, join to it.
	  this->m_uf.join(x, x-1);
	}
      }

      if (x < this->m_N-1)
      {
	// check x+1
	if (this->m_removed[x+1])
	{
	  // x+1 has been removed. join to it.
	  this->m_uf.join(x, x+1);
	}
      }
    }
  }

  SuccessorWithDelete::size_type SuccessorWithDelete::successor(size_type x)
  {
    this->check(x);
    
    if (x == this->m_N-1)
    {
      // x is the last element.
      return SuccessorWithDelete::INVALID_INDEX;
    }

    if (!this->m_removed[x])
    {
      // x hasn't been removed.
      return x;
    }
    
    if (this->m_N == 1)
    {
      // Only one element, x, which has been removed.
      return SuccessorWithDelete::INVALID_INDEX;
    }

    // Retrieve largest element of connected component
    // involving removed element, x. The successor, if any,
    // will be the next largest integer.
    const size_type y = 1 + this->m_uf.find(x);

    return y < this->m_N ? y : SuccessorWithDelete::INVALID_INDEX;
  }

  const SuccessorWithDelete::size_type SuccessorWithDelete::INVALID_INDEX = -1;

  void SuccessorWithDelete::check(size_type i) const
  {
    if (i >= this->m_N)
    {
      throw std::out_of_range("Invalid index: " + boost::lexical_cast<std::string>(i));
    }
  }

} // ! namespace swd
