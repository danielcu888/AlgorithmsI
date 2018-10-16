#ifndef SRC_MAIN_INCLUDE_SUCCESSORWITHDELETE_H_
#define SRC_MAIN_INCLUDE_SUCCESSORWITHDELETE_H_

// uf
#include "UnionfindWithSpecificCanonicalElement.h"

// C++
#include <deque>
#include <cstdlib>

namespace swd
{
  class SuccessorWithDelete final
  {
   public:

    using size_type = std::deque<std::size_t>::size_type;

    explicit SuccessorWithDelete(size_type N);
    SuccessorWithDelete(const SuccessorWithDelete&) = delete;
    SuccessorWithDelete& operator=(const SuccessorWithDelete&) = delete;
    SuccessorWithDelete(SuccessorWithDelete&&) = delete;
    SuccessorWithDelete& operator=(SuccessorWithDelete&&) = delete;
    ~SuccessorWithDelete() = default;

    void remove(size_type x);
    size_type successor(size_type x);

    static const size_type INVALID_INDEX;

   private:

    void check(size_type i) const;

    size_type m_N;
    uf::UnionFindWithSpecificCanonicalElement m_uf;
    std::deque<bool> m_removed;

  }; // ! class SuccessorWithDelete

} // ! namespace swd

#endif // ! SRC_MAIN_INCLUDE_SUCCESSORWITHDELETE_H_
