#ifndef QUICKUNIONWITHPATHHALVING_H_
#define QUICKUNIONWITHPATHHALVING_H_

// C++
#include <cstdlib>
#include <deque>
#include <string>
#include <iosfwd>

namespace uf
{
  class QuickUnionWithPathHalving final
  {
    public:

      using size_type = std::deque<std::size_t>::size_type;

      explicit QuickUnionWithPathHalving(size_type sz);
      QuickUnionWithPathHalving(const QuickUnionWithPathHalving&) = delete;
      QuickUnionWithPathHalving& operator=(const QuickUnionWithPathHalving&) = delete;
      QuickUnionWithPathHalving(QuickUnionWithPathHalving&&) = delete;
      QuickUnionWithPathHalving& operator=(QuickUnionWithPathHalving&&) = delete;
      ~QuickUnionWithPathHalving() = default;

      void unify(size_type i, size_type j);
      size_type find(size_type i);
      std::string toString() const;

    private:
      void check(size_type i) const;

      size_type m_sz;
      std::deque<std::size_t> m_id;

  }; // ! class QuickUnionWithPathHalving

  std::ostream& operator<<(std::ostream& os, const QuickUnionWithPathHalving& qf);

} // ! namespace uf

#endif // ! QUICKUNIONWITHPATHHALVING_H_
