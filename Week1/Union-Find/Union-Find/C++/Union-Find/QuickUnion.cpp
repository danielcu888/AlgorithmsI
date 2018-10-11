// uf
#include "QuickUnion.h"

// boost
#include <boost/lexical_cast.hpp>

namespace uf
{

  QuickUnion::QuickUnion(std::size_t sz)
    : m_sz(sz)
    , m_a(sz, 0)
  {
    for (size_type i = 0; i < this->m_sz; ++i)
    {
      this->m_a[i] = i;
    }
  }

  void QuickUnion::unify(size_type i, size_type j)
  {
    this->check(i);
    this->check(j);

    const size_type ri = this->find(i);
    const size_type rj = this->find(j);

    this->m_a[ri] = rj;
  }

  QuickUnion::size_type QuickUnion::find(size_type i) const
  {
    this->check(i);

    while (this->m_a[i] != i)
    {
      i = this->m_a[i];
    }

    return i;
  }

  std::string QuickUnion::toString() const
  {
    std::string s;

    for (std::size_t i = 0; i < this->m_a.size(); ++i)
    {
      s += boost::lexical_cast<std::string>(this->m_a[i]) + " ";
    }

    return s;
  }

  void QuickUnion::check(size_type i) const
  {
    if (i >= this->m_a.size())
    {
      throw std::out_of_range( "index "
                             + boost::lexical_cast<std::string>(i)
                             + " is out of range."
                             );
    }
  }

  std::ostream& operator<<(std::ostream& os, const QuickUnion& qu)
  {
    return os << qu.toString();
  }

} // ! namespace uf
