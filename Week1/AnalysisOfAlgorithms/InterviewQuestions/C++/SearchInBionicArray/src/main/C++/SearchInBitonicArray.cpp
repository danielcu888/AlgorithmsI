// sba
#include "SearchInBitonicArray.h"

// C++
#include <deque>

namespace sba
{
  SearchInBitonicArray::SearchInBitonicArray(const std::deque<int>& v)
    : m_v(v)
    , m_max_idx(SearchInBitonicArray::findMaximum(this->m_v).get())
  {}
  
  bool SearchInBitonicArray::contains(int x) const
  {
    if (x > this->m_v[this->m_max_idx])
    {
      return false;
    }

    if (x < this->m_v.front() && x < this->m_v.back())
    {
      return false;
    }

    // Conduct binary search.

    const bool is_monotonic =
      (this->m_max_idx == 0) || (this->m_max_idx == this->m_v.size()-1);

    boost::optional<std::deque<int>::size_type> idx = boost::none;

    if (is_monotonic)
    {
      if (this->m_max_idx == this->m_v.size()-1)
      {
	// ascending monotonic.
	idx = SearchInBitonicArray::binarySearch( this->m_v
						, x
						, 0
						, this->m_v.size()-1
						);
      }
      else
      {
	// descending monotonic.
	idx = SearchInBitonicArray::binarySearchReversed( this->m_v
							, x
							, 0
							, this->m_v.size()-1
							);
      }
    }
    else
    {
      // bitonic.

      // Search ascending sub-array.
      idx = SearchInBitonicArray::binarySearch( this->m_v
					      , x
					      , 0
					      , this->m_max_idx
					      );

      if (idx == boost::none && this->m_max_idx != this->m_v.size()-1)
      {
	// Search descending sub-array.
	idx = SearchInBitonicArray::binarySearchReversed( this->m_v
							, x
							, this->m_max_idx+1
							, this->m_v.size()-1
							);
      }
    }

    return idx != boost::none;
  }

  boost::optional<std::deque<int>::size_type>
  SearchInBitonicArray::findMaximum(const std::deque<int>& v)
  {
    std::deque<int>::size_type N = v.size();

    // check array of size < 3
    if (N == 0)
    {
      throw std::out_of_range("Empty array's are invalid.");
    }
    
    if (N == 1)
    {
      return 0;
    }

    if (N == 2)
    {
      return v.front() > v.back() ? 0 : 1;
    }
    
    // check endpoints

    if (v.front() > v[1] && v.front() > v.back())
    {
      return 0;
    }

    if (v.back() > v.front() && v.back() > v[N-2])
    {
      return N-1;
    }

    std::deque<int>::size_type lo = 0;
    std::deque<int>::size_type hi = N-1;

    while (lo <= hi)
    {
      const std::deque<int>::size_type mid = (lo+hi)/2;

      if (v[mid-1] > v[mid])
      {
	hi = mid-1;
      }
      else if (v[mid+1] > v[mid])
      {
	lo = mid+1;
      }
      else
      {
	return mid;
      }
    }

    return boost::none;
  }
  
  boost::optional<std::deque<int>::size_type>
  SearchInBitonicArray::binarySearch( const std::deque<int>& v
				    , int x
				    , std::deque<int>::size_type lo
				    , std::deque<int>::size_type hi
				    )
  {
    while (lo <= hi)
    {
      const std::deque<int>::size_type mid = (lo+hi)/2;

      if (x < v[mid])
      {
	hi = mid-1;
      }
      else if (x > v[mid])
      {
	lo = mid+1;
      }
      else
      {
	return mid;
      }
    }

    return boost::none;
  }

  boost::optional<std::deque<int>::size_type>
  SearchInBitonicArray::binarySearchReversed( const std::deque<int>& v
				            , int x
				            , std::deque<int>::size_type lo
				            , std::deque<int>::size_type hi
				            )
  {
    while (lo <= hi)
    {
      const std::deque<int>::size_type mid = (lo+hi)/2;

      if (x > v[mid])
      {
	hi = mid-1;
      }
      else if (x < v[mid])
      {
	lo = mid+1;
      }
      else
      {
	return mid;
      }
    }

    return boost::none;
  }

} // ! namespace sba
