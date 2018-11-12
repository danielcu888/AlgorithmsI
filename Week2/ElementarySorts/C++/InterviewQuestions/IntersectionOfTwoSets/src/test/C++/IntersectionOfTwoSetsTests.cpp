// its
#include "IntersectionOfTwoSets.h"

// Testing
#include <gtest/gtest.h>

namespace its
{
  TEST(IntersectionOfTwoSetsTests, example1)
  {
    its::Point2D a[4] = {its::Point2D(1.0, 2.0), its::Point2D(-3.0, -4.0), its::Point2D(-5.0, 6.0), its::Point2D(7.0, -8.0)};
    its::Point2D b[3] = {a[0], a[1], a[3]};

    std::deque<its::Point2D> inx = its::intersection(a, 4, b, 3);
    ASSERT_EQ(inx.size(), 3);

    ASSERT_DOUBLE_EQ(inx[0].x, 1.0);
    ASSERT_DOUBLE_EQ(inx[0].y, 2.0);

    ASSERT_DOUBLE_EQ(inx[1].x, -3.0);
    ASSERT_DOUBLE_EQ(inx[1].y, -4.0);

    ASSERT_DOUBLE_EQ(inx[2].x, 7.0);
    ASSERT_DOUBLE_EQ(inx[2].y, -8.0);
  }

} // ! namespace its
