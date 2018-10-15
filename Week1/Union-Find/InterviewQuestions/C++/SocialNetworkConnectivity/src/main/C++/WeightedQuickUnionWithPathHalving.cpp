// uf
#include "WeightedQuickUnionWithPathHalving.h"

// boost
#include <boost/lexical_cast.hpp>

namespace uf
{
  WeightedQuickUnionWithPathHalving::WeightedQuickUnionWithPathHalving(size_type N)
    : m_N(N)
    , m_id(new std::size_t[this->m_N])
    , m_sz(new std::size_t[this->m_N])
  {
    for (size_type i = 0; i < this->m_N; ++i)
      {
	this->m_id[i] = i;
	this->m_sz[i] = 1;
      }
  }

  WeightedQuickUnionWithPathHalving::~WeightedQuickUnionWithPathHalving()
  {
    delete [] this->m_id;
    delete [] this->m_sz;
  }

  bool WeightedQuickUnionWithPathHalving::connected(size_type i, size_type j)
  {
    return this->find(i) == this->find(j);
  }

  void WeightedQuickUnionWithPathHalving::join(size_type i, size_type j)
  {
    const size_type iroot = this->find(i);
    const size_type jroot = this->find(j);

    if (this->m_sz[iroot] < this->m_sz[jroot])
      {
	this->m_id[iroot] = jroot;
	this->m_sz[jroot] += this->m_sz[iroot];
      }
    else
      {
	this->m_id[jroot] = iroot;
	this->m_sz[iroot] += this->m_sz[jroot];
      }
  }

  WeightedQuickUnionWithPathHalving::size_type
  WeightedQuickUnionWithPathHalving::find(size_type i)
  {
    while (this->m_id[i] != i)
      {
	const size_type j = this->m_id[i];
	this->m_id[i] = this->m_id[j];
	i = j;
      }

    return i;
  }

  std::string WeightedQuickUnionWithPathHalving::toString() const
  {
    std::string s;
    for (size_type i = 0; i < this->m_N; ++i)
      {
	s += boost::lexical_cast<std::string>(i) + ": " +
	  boost::lexical_cast<std::string>(this->m_id[i]) + " " +
	  boost::lexical_cast<std::string>(this->m_sz[i]);

	if (i < this->m_N - 1)
	  {
	    s += ", ";
	  }
      }

    return s;
  }

} // ! namespace uf
