#ifndef SRC_MAIN_INCLUDE_THREESUMINQUADRATICTIME_H_
#define SRC_MAIN_INCLUDE_THREESUMINQUADRATICTIME_H_

// C++
#include <deque>
#include <tuple>

namespace ts
{
  class ThreeSumInQuadraticTime final
  {
   public:
    explicit ThreeSumInQuadraticTime(const std::deque<int>& v);
    ThreeSumInQuadraticTime(const ThreeSumInQuadraticTime&) = delete;
    ThreeSumInQuadraticTime& operator=(const ThreeSumInQuadraticTime&) = delete;
    ThreeSumInQuadraticTime(ThreeSumInQuadraticTime&&) = delete;
    ThreeSumInQuadraticTime& operator=(ThreeSumInQuadraticTime&&) = delete;
    ~ThreeSumInQuadraticTime() = default;

    const std::deque<std::tuple<int, int, int>>&
    threeSums() const;

   private:
    std::deque<int> m_v;
    std::deque<std::tuple<int, int, int>> m_tss;

  }; // ! class ThreeSumInQuadraticTime

} // ! namespace ts

#endif // ! SRC_MAIN_INCLUDE_THREESUMINQUADRATICTIME_H_
