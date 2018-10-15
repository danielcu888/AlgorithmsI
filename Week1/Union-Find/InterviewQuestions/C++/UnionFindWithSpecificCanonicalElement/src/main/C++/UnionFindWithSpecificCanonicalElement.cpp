// uf
#include "UnionFindWithSpecificCanonicalElement.h"

// boost
#include <boost/lexical_cast.hpp>

// C++
#include <stdexcept>

namespace uf
{
  UnionFindWithSpecificCanonicalElement::UnionFindWithSpecificCanonicalElement(size_type N)
    : m_N(N)
    , m_max_id(this->m_N, 0)
    , m_sz(this->m_N, 1)
    , m_id(this->m_N, 0)
  {
    for (size_type i = 0; i < this->m_N; ++i)
    {
      this->m_max_id[i] = this->m_id[i] = i;
    }
  }

  bool UnionFindWithSpecificCanonicalElement::connected(size_type i, size_type j)
  {
    this->check(i);
    this->check(j);

    return this->root(i) == this->root(j);
  }

  void UnionFindWithSpecificCanonicalElement::join(size_type i, size_type j)
  {
    this->check(i);
    this->check(j);

    const size_type iroot = this->root(i);
    const size_type jroot = this->root(j);

    const size_type imax_sz = this->find(iroot);
    const size_type jmax_sz = this->find(jroot);

    if (this->m_sz[iroot] < this->m_sz[jroot])
    {
      this->m_id[iroot] = jroot;
      this->m_sz[jroot] += this->m_sz[iroot];
      this->m_max_id[jroot] = std::max(this->m_max_id[iroot], this->m_max_id[jroot]);
    }
    else
    {
      this->m_id[jroot] = iroot;
      this->m_sz[iroot] += this->m_sz[jroot];
      this->m_max_id[iroot] = std::max(this->m_max_id[iroot], this->m_max_id[jroot]);      
    }
  }

  UnionFindWithSpecificCanonicalElement::size_type
  UnionFindWithSpecificCanonicalElement::find(size_type i)
  {
    this->check(i);

    return this->m_max_id[i];
  }

  std::string UnionFindWithSpecificCanonicalElement::to_string() const
  {
    std::string s;
    for (size_type i = 0; i < this->m_N; ++i)
    {
      s += boost::lexical_cast<std::string>(i)
	+ ": "
	+ boost::lexical_cast<std::string>(this->m_id[i])
	+ " "
	+ boost::lexical_cast<std::string>(this->m_sz[i])
	+ " "
	+ boost::lexical_cast<std::string>(this->m_max_id[i]);

      if (i < this->m_N-1)
      {
	s += ", ";
      }
    }

    return s;
  }

  UnionFindWithSpecificCanonicalElement::size_type
  UnionFindWithSpecificCanonicalElement::root(size_type i)
  {
    this->check(i);

    while (i != this->m_id[i])
    {
      const size_type j = this->m_id[i];
      this->m_id[i] = this->m_id[j];
      i = j;
    }

    return i;
  }

  void UnionFindWithSpecificCanonicalElement::check(size_type i) const
  {
    if (i >= this->m_N)
    {
      throw std::out_of_range("Invalid index: " + boost::lexical_cast<std::string>(i));
    }
  }

} // ! namespace uf
