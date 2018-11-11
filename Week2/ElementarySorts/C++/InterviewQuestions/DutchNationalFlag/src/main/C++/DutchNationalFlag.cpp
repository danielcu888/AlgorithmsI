// dnf
#include "DutchNationalFlag.h"

// C++
#include <iostream>
#include <stdexcept>

namespace dnf
{
  DutchNationalFlag::DutchNationalFlag(const std::deque<Colour>& buckets)
    : m_buckets(buckets)
  {
    if (buckets.empty())
    {
      throw std::logic_error("No buckets in supplied container.");
    }
  }

  const Colour& DutchNationalFlag::colour(sz i) const
  {
    return this->m_buckets[i];
  }

  void DutchNationalFlag::swap(sz i, sz j)
  {
    const Colour c = this->colour(i);
    this->m_buckets[i] = this->m_buckets[j];
    this->m_buckets[j] = c;
  }

  void DutchNationalFlag::sort()
  {
    const sz N = this->m_buckets.size();
    sz i = 0;
    sz j = 0;
    sz k = N-1;

    while (j < k)
    {
      while (this->colour(i) == Colour::BLUE && i < N)
      {
	++i;
	++j;
      }
      
      if (i == N)
      {
	break;
      }

      while (this->colour(k) == Colour::RED && k > j)
      {
	--k;
      }

      if (k == j)
      {
	break;
      }

      switch (this->colour(j))
      {
      case Colour::WHITE:
	break;
      case Colour::RED:
	this->swap(j, k);
	--k;
	break;
      case Colour::BLUE:
	this->swap(i, j);
	++i;
	break;
      default:
	throw std::out_of_range("Unrecognised dnf::Colour.");
      }

      ++j;
    }
  }

  std::string DutchNationalFlag::to_string() const
  {
    std::string s;
    for (const auto& c : this->m_buckets)
    {
      if (c == Colour::BLUE)
      {
	s += "B";
      }
      else if (c == Colour::WHITE)
      {
	s += "W";
      }
      else
      {
	s += "R";
      }
    }

    return s;
  }

  std::ostream& operator<<(std::ostream& os, const DutchNationalFlag& d)
  {
    os << d.to_string();
    return os;
  }

} // ! namespace dnf
