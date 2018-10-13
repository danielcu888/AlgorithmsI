#ifndef QUICKUNION_H_
#define QUICKUNION_H_

// C++
#include <cstdlib>
#include <deque>
#include <string>
#include <iosfwd>

namespace uf
{
  class QuickUnion final
  {
    public:

      using size_type = std::deque<std::size_t>::size_type;

      explicit QuickUnion(size_type sz);
      QuickUnion(const QuickUnion&) = delete;
      QuickUnion& operator=(const QuickUnion&) = delete;
      QuickUnion(QuickUnion&&) = delete;
      QuickUnion& operator=(QuickUnion&&) = delete;
      ~QuickUnion() = default;

      void unify(size_type i, size_type j);
      size_type find(size_type i) const;
      std::string toString() const;

    private:
      void check(size_type i) const;

      size_type m_sz;
      std::deque<std::size_t> m_a;

  }; // ! class QuickUnion

  std::ostream& operator<<(std::ostream& os, const QuickUnion& qf);

} // ! namespace uf

#endif /* QUICKUNION_H_ */
