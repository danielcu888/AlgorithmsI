// its
#include "IntersectionOfTwoSets.h"

namespace its
{
  Point2D::Point2D(const double x_, const double y_)
    : x(x_)
    , y(y_)
  {}

  static int compare(const its::Point2D& p1, const its::Point2D& p2)
  {
    if (p1.x < p2.x)
    {
      return -1;
    }
    else if (p1.x > p2.x)
    {
      return 1;
    }
    else if (p1.y < p2.y)
    {
      return -1;
    }
    else if (p1.y > p2.y)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }

  static bool less(const its::Point2D& p1, const its::Point2D& p2)
  {
    return its::compare(p1, p2) < 0;
  }

  static bool binary_search(const its::Point2D& p, its::Point2D* points, int lo, int hi)
  {
    while (lo <= hi)
    {
      const int mid = (lo+hi)/2;
      const int cmp = its::compare(p, points[mid]);
      if (cmp == 0)
      {
	return true;
      }
      else if (cmp < 0)
      {
	hi = mid - 1;	
      }
      else
      {
	lo = mid + 1;
      }
    }

    return false;
  }

  static bool binary_search(const its::Point2D& p, its::Point2D* points, std::size_t N)
  {
    return its::binary_search(p, points, 0, N-1);
  }

  static void sort(its::Point2D* points, std::size_t N)
  {
    for (int i = 0; i < N; ++i)
    {
      int min = i;
      for (int j = i+1; j < N; ++j)
      {
	if (its::less(points[j], points[min]))
	{
	  min = j;
	}
      }

      const its::Point2D p = points[i];
      points[i] = points[min];
      points[min] = p;
    }
  }

  std::deque<its::Point2D> intersection( its::Point2D* a
				       , std::size_t aN
				       , its::Point2D* b
				       , std::size_t bN
				       )
  {
    std::deque<its::Point2D> inx;
    its::Point2D* c = nullptr;
    its::Point2D* d = nullptr;
    std::size_t cN = 0;
    std::size_t dN = 0;
    if (aN < bN)
    {
      c = a;
      d = b;
      cN = aN;
      dN = bN;
    }
    else
    {
      c = b;
      d = a;
      cN = bN;
      dN = aN;
    }

    its::sort(d, dN);
    for (std::size_t i = 0; i < cN; ++i)
    {
      if (its::binary_search(c[i], d, dN))
      {
	inx.push_back(c[i]);
      }
    }      

    return inx;
  }

} // ! namespace its
