// uf
#include "WeightedQuickUnion.h"

// boost
#include <boost/lexical_cast.hpp>

namespace uf
{

  WeightedQuickUnion::WeightedQuickUnion(size_type sz)
    : m_sz(sz)
    , m_height(this->m_sz, 1)
    , m_id(this->m_sz, 0)
  {
    for (size_type i = 0; i < this->m_sz; ++i)
    {
      m_id[i] = i;
    }
  }

  void WeightedQuickUnion::unify(size_type i, size_type j)
  {
    this->check(i);
    this->check(j);

    const size_type iroot = this->find(i);
    const size_type jroot = this->find(j);

    if (i != j)
    {
      const size_type iheight = this->m_height[iroot];
      const size_type jheight = this->m_height[jroot];

      if (iheight < jheight)
      {
        this->m_id[iroot] = jroot;
      }
      else if (iheight > jheight)
      {
        this->m_id[jroot] = iroot;
      }
      else
      {
        this->m_id[iroot] = jroot;
        ++this->m_height[jroot];
      }
    }
  }

  WeightedQuickUnion::size_type
  WeightedQuickUnion::find(size_type i) const
  {
    this->check(i);

    while (this->m_id[i] != i)
    {
      i = this->m_id[i];
    }

    return i;
  }

  void WeightedQuickUnion::check(size_type i) const
  {
    if (i >= this->m_id.size())
    {
      throw std::out_of_range( "Index "
                             + boost::lexical_cast<std::string>(i)
                             + " is out of range"
                             );
    }
  }

  std::string WeightedQuickUnion::toString() const
  {
    std::string s;

    for (const auto& id : this->m_id)
    {
      s += boost::lexical_cast<std::string>(id) + " ";
    }

    return s;
  }

  std::ostream& operator<<(std::ostream& os, const WeightedQuickUnion& wqu)
  {
    return os << wqu.toString();
  }

} /* namespace uf */
