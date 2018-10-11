#ifndef WEIGHTEDQUICKUNION_H_
#define WEIGHTEDQUICKUNION_H_

// C++
#include <deque>
#include <cstdlib>
#include <iosfwd>
#include <string>

namespace uf
{

  class WeightedQuickUnion
  {
    public:

      using size_type = std::deque<int>::size_type;

      explicit WeightedQuickUnion(size_type sz);
      WeightedQuickUnion(const WeightedQuickUnion&) = delete;
      WeightedQuickUnion& operator=(const WeightedQuickUnion&) = delete;
      WeightedQuickUnion(WeightedQuickUnion&&) = delete;
      WeightedQuickUnion& operator=(WeightedQuickUnion&&) = delete;
      virtual ~WeightedQuickUnion() = default;

      void unify(size_type i, size_type j);
      size_type find(size_type i) const;
      std::string toString() const;

    private:

      void check(size_type i) const;

      size_type m_sz;
      std::deque<std::size_t> m_height;
      std::deque<int> m_id;
  };

  std::ostream& operator<<(std::ostream& os, const WeightedQuickUnion& wqu);

} /* namespace uf */

#endif /* WEIGHTEDQUICKUNION_H_ */
