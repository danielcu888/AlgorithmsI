#ifndef SRC_MAIN_INCLUDE_UNIONFINDWITHSPECIFICCANONICALELEMENT_H_
#define SRC_MAIN_INCLUDE_UNIONFINDWITHSPECIFICCANONICALELEMENT_H_

// C++
#include <deque>
#include <cstdlib>
#include <string>

namespace uf
{
  class UnionFindWithSpecificCanonicalElement final
  {
   public:

    using size_type = std::deque<std::size_t>::size_type;

    explicit UnionFindWithSpecificCanonicalElement(size_type N);
    UnionFindWithSpecificCanonicalElement(const UnionFindWithSpecificCanonicalElement&) = delete;
    UnionFindWithSpecificCanonicalElement& operator=(const UnionFindWithSpecificCanonicalElement&) = delete;
    UnionFindWithSpecificCanonicalElement(const UnionFindWithSpecificCanonicalElement&&) = delete;
    UnionFindWithSpecificCanonicalElement& operator=(UnionFindWithSpecificCanonicalElement&&) = delete;
    ~UnionFindWithSpecificCanonicalElement() = default;

    size_type find(size_type i);
    bool connected(size_type i, size_type j);
    void join(size_type i, size_type j);
    std::string to_string() const;

   private:

    UnionFindWithSpecificCanonicalElement::size_type root(size_type i);
    void check(size_type i) const;

    const size_type m_N;
    std::deque<std::size_t> m_max_id;
    std::deque<std::size_t> m_sz;
    std::deque<std::size_t> m_id;

  }; // ! class UnionFindWithSpecificCanonicalElement

} // ! namespace uf

#endif // ! SRC_MAIN_INCLUDE_UNIONFINDWITHSPECIFICCANONICALELEMENT_H_
