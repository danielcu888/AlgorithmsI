#ifndef QUICKFIND_H_
#define QUICKFIND_H_

// C++
#include <cstdlib>
#include <deque>
#include <string>
#include <iosfwd>

namespace uf
{
  class QuickFind final
  {
    public:
      explicit QuickFind(std::size_t sz);
      ~QuickFind() = default;
      QuickFind(const QuickFind&) = delete;
      QuickFind& operator=(const QuickFind&) = delete;
      QuickFind(QuickFind&&) = delete;
      QuickFind& operator=(QuickFind&&) = delete;

      void unify(std::size_t a, std::size_t b);
      std::size_t find(std::size_t a) const;
      std::string toString() const;

    private:
      void check(std::size_t a) const;

      std::deque<std::size_t> m_a;

  }; // ! class Quickfind

  std::ostream& operator<<(std::ostream& os, const QuickFind& qf);

} // ! namespace uf

#endif // ! QUICKFIND_H_
