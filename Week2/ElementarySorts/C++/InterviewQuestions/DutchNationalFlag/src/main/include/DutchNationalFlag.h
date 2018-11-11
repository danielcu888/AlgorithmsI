#ifndef SRC_MAIN_INCLUDE_DUTCH_NATIONAL_FLAG_H_
#define SRC_MAIN_INCLUDE_DUTCH_NATIONAL_FLAG_H_

// C++
#include <deque>
#include <iosfwd>
#include <string>

namespace dnf
{
  enum class Colour
  {
    BLUE = 0,
    WHITE = 2,
    RED = 1
  }; // ! enum class Colour

  class DutchNationalFlag final
  {
  public:

    using sz = std::deque<Colour>::size_type;

    DutchNationalFlag(const std::deque<Colour>& buckets);
    DutchNationalFlag(const DutchNationalFlag&) = delete;
    DutchNationalFlag& operator=(const DutchNationalFlag&) = delete;
    DutchNationalFlag(DutchNationalFlag&&) = delete;
    DutchNationalFlag& operator=(DutchNationalFlag&&) = delete;
    ~DutchNationalFlag() = default;

    const Colour& colour(sz i) const;
    void swap(sz i, sz j);
    void sort();

    std::string to_string() const;

   private:
    std::deque<Colour> m_buckets;

  }; // ! class DutchNationalFlag

  std::ostream& operator<<(std::ostream& os, const DutchNationalFlag& d);

} // ! namespace dnf

#endif // ! SRC_MAIN_INCLUDE_DUTCH_NATIONAL_FLAG_H_
