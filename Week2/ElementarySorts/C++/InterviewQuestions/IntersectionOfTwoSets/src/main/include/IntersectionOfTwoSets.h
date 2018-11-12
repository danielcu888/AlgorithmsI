#ifndef SRC_MAIN_INCLUDE_INTERSECTIONOFTWOSETS_H_
#define SRC_MAIN_INCLUDE_INTERSECTIONOFTWOSETS_H_

// C++
#include <cstddef>
#include <deque>

namespace its
{
  struct Point2D
  {
    Point2D(const double x_, const double y_);

    double x;
    double y;

  }; // ! struct Point2D

  std::deque<its::Point2D> intersection( its::Point2D* a
				       , std::size_t aN
				       , its::Point2D* b
				       , std::size_t bN
				       );
} // ! namespace its

#endif // ! SRC_MAIN_INCLUDE_INTERSECTIONOFTWOSETS_H_
