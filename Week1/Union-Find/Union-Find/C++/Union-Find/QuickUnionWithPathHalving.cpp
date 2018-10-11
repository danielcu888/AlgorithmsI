// uf
#include "QuickUnionWithPathHalving.h"

// boost
#include <boost/lexical_cast.hpp>

namespace uf
{

  QuickUnionWithPathHalving::QuickUnionWithPathHalving(std::size_t sz)
    : m_sz(sz)
    , m_id(sz, 0)
  {
    for (size_type i = 0; i < this->m_sz; ++i)
    {
      this->m_id[i] = i;
    }
  }

  void QuickUnionWithPathHalving::unify(size_type i, size_type j)
  {
    this->check(i);
    this->check(j);

    const size_type ri = this->find(i);
    const size_type rj = this->find(j);

    this->m_id[ri] = rj;
  }

  QuickUnionWithPathHalving::size_type QuickUnionWithPathHalving::find(size_type i)
  {
    this->check(i);

    while (this->m_id[i] != i)
    {
      const size_type j = this->m_id[i];
      this->m_id[i] = this->m_id[j];
      i = j;
    }

    return i;
  }

  std::string QuickUnionWithPathHalving::toString() const
  {
    std::string s;

    for (std::size_t i = 0; i < this->m_id.size(); ++i)
    {
      s += boost::lexical_cast<std::string>(this->m_id[i]) + " ";
    }

    return s;
  }

  void QuickUnionWithPathHalving::check(size_type i) const
  {
    if (i >= this->m_id.size())
    {
      throw std::out_of_range( "index "
                             + boost::lexical_cast<std::string>(i)
                             + " is out of range."
                             );
    }
  }

  std::ostream& operator<<(std::ostream& os, const QuickUnionWithPathHalving& qu)
  {
    return os << qu.toString();
  }

} // ! namespace uf
