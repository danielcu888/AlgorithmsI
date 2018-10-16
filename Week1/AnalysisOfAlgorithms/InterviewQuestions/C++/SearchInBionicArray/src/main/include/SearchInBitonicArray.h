#ifndef SRC_MAIN_INCLUDE_SEARCHINBITONICARRAY_H_
#define SRC_MAIN_INCLUDE_SEARCHINBITONICARRAY_H_

// C++
#include <deque>

// boost
#include <boost/optional.hpp>

namespace sba
{
  class SearchInBitonicArray final
  {
   public:
    explicit SearchInBitonicArray(const std::deque<int>& v);
    SearchInBitonicArray(const SearchInBitonicArray&) = delete;
    SearchInBitonicArray& operator=(const SearchInBitonicArray&) = delete;
    ~SearchInBitonicArray() = default;

    bool contains(int x) const;
    
   private:

    static boost::optional<std::deque<int>::size_type>
      findMaximum(const std::deque<int>& v);
    static boost::optional<std::deque<int>::size_type>
      binarySearch( const std::deque<int>& v
		  , int x
		  , std::deque<int>::size_type lo
		  , std::deque<int>::size_type hi
		  );
    static boost::optional<std::deque<int>::size_type>
      binarySearchReversed( const std::deque<int>& v
		          , int x
			  , std::deque<int>::size_type lo
			  , std::deque<int>::size_type hi
			  );

    const std::deque<int> m_v;
    const std::deque<int>::size_type m_max_idx;

  }; // ! namespace SearchInBitonicArray

} // ! namespace sba

#endif // ! SRC_MAIN_INCLUDE_SEARCHINBITONICARRAY_H_
