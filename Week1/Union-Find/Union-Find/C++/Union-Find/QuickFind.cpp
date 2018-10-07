// uf
#include "QuickFind.h"

// boost
#include <boost/lexical_cast.hpp>

// C++
#include <stdexcept>
#include <string>
#include <iostream>

namespace uf
{
  QuickFind::QuickFind(std::size_t sz)
    : m_a(sz, 0)
  {
    for (std::deque<std::size_t>::size_type i = 0; i < sz; ++i)
    {
      this->m_a[i] = i;
    }
  }

  void QuickFind::unify(std::size_t a, std::size_t b)
  {
    this->check(a);
    this->check(b);

    const std::size_t aVal = this->m_a[a];
    const std::size_t bVal = this->m_a[b];
    const std::deque<std::size_t>::size_type sz = this->m_a.size();
    for (std::deque<std::size_t>::size_type i = 0; i < sz; ++i)
    {
      if (this->m_a[i] == aVal)
      {
        this->m_a[i] = bVal;
      }
    }
  }

  std::size_t QuickFind::find(std::size_t a) const
  {
    this->check(a);
    return this->m_a[a];
  }

  void QuickFind::check(std::size_t a) const
  {
    if (a >= this->m_a.size())
    {
      throw std::out_of_range( "index "
                             + boost::lexical_cast<std::string>(a)
                             + " is out of range."
                             );
    }
  }

  std::string QuickFind::toString() const
  {
    std::string s;
    for (std::size_t i = 0; i < this->m_a.size(); ++i)
    {
      s += boost::lexical_cast<std::string>(this->find(i)) + " ";
    }
    return s;
  }

  std::ostream& operator<<(std::ostream& os, const QuickFind& qf)
  {
    return os << qf.toString();
  }

} /* ! namespace uf */
