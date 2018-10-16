// ts
#include "ThreeSumInQuadraticTime.h"

// C++
#include <algorithm>
#include <limits>

namespace ts
{
  ThreeSumInQuadraticTime::ThreeSumInQuadraticTime(const std::deque<int>& v)
    : m_v(v)
    , m_tss()
  {
    using size_type = std::deque<int>::size_type;

    const size_type sz = v.size();

    if (sz < 3)
    {
      // No 3-sum possible.
      return;
    }

    // Sort the integers into ascending order.
    std::sort(this->m_v.begin(), this->m_v.end());

    // Iterate over integers.
    for (size_type i = 0; i < sz; ++i)
    {
      
      // Target sum for desired pair.
      const int target = -1 * v[i];

      // Initialize indices of desired pair.
      size_type l = i+1;
      size_type h = sz-1;

      // Initialize sum of desired pair.
      int sum = std::numeric_limits<int>::min();
      while (l < h && ((sum = v[l] + v[h]) != target))
      {
	if (sum > target)
	{
	  --h;
	}
	else
	{
	  ++l;
	}
      }

      if (sum == target)
      {
	this->m_tss.push_back({i, l, h});
      }
    }
  }

  const std::deque<std::tuple<int, int, int>>&
  ThreeSumInQuadraticTime::threeSums() const
  {
    return this->m_tss;
  }

} // ! namespace ThreeSumInQuadraticTime
