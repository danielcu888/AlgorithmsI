// queues
#include "CircularArrayQueue.h"

// Testing
#include <gtest/gtest.h>

namespace queues
{
  namespace queuetesting
  {
    TEST(CircularArrayQueue, ConstructorOneParameter)
    {
      CircularArrayQueue<int> q(10);
    }

    TEST(CircularArrayQueue, Empty)
    {
      CircularArrayQueue<int> q(10);
      ASSERT_TRUE(q.empty());
    }

    TEST(CircularArrayQueue, Size)
    {
      CircularArrayQueue<int> q(10);
      ASSERT_EQ(q.size(), 0);
    }

    TEST(CircularArrayQueue, FrontThrowsIfEmpty)
    {
      CircularArrayQueue<int> q(10);
      ASSERT_THROW(q.front(), std::logic_error);
    }

    TEST(CircularArrayQueue, BackThrowsIfEmpty)
    {
      CircularArrayQueue<int> q(10);
      ASSERT_THROW(q.back(), std::logic_error);
    }

    TEST(CircularArrayQueue, EnqueueSingleItem)
    {
      CircularArrayQueue<int> q(10);
      q.enqueue(2);
      ASSERT_FALSE(q.empty());
      ASSERT_EQ(q.size(), 1);
      ASSERT_EQ(q.front(), 2);
      ASSERT_EQ(q.back(), 2);
    }

    TEST(CircularArrayQueue, DequeueSingleItem)
    {
      CircularArrayQueue<int> q(10);
      q.enqueue(2);
      q.dequeue();
    }

    TEST(CircularArrayQueue, DequeueThrowsIfEmpty)
    {
      CircularArrayQueue<int> q(10);
      ASSERT_THROW(q.dequeue(), std::logic_error);
    }

    TEST(CircularArrayQueue, EnqueueMultipleElements)
    {
      CircularArrayQueue<int> q(10);
      for (int i = 0; i < 9; ++i)
      {
	q.enqueue(i);
	ASSERT_FALSE(q.empty());
	ASSERT_EQ(q.size(), i+1);
	ASSERT_EQ(q.front(), 0);
	ASSERT_EQ(q.back(), i);
      }

      // Saturate capacity.
      q.enqueue(9);
      ASSERT_TRUE(q.empty());
      ASSERT_EQ(q.size(), 0);
    }

    TEST(CircularArrayQueue, DequeueMultipleElements)
    {
      CircularArrayQueue<int> q(10);

      for (int i = 0; i < 10; ++i)
      {
	q.enqueue(i);
      }

      while (!q.empty())
      {
	ASSERT_EQ(q.front(), 10-q.size());
	ASSERT_EQ(q.back(), 9);
	q.dequeue();
      }

      ASSERT_TRUE(q.empty());
      ASSERT_EQ(q.size(), 0);
    }

    TEST(CircularArrayQueue, CopyConstrutor)
    {
      CircularArrayQueue<int> q1(11);

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      CircularArrayQueue<int> q2(q1);

      while (!q1.empty())
      {
	ASSERT_EQ(q1.front(), 10-q1.size());
	ASSERT_EQ(q1.back(), 9);
	q1.dequeue();
      }

      ASSERT_TRUE(q1.empty());
      ASSERT_EQ(q1.size(), 0);

      ASSERT_FALSE(q2.empty());
      ASSERT_EQ(q2.size(), 10);

      while (!q2.empty())
      {
	ASSERT_EQ(q2.front(), 10-q2.size());
	ASSERT_EQ(q2.back(), 9);
	q2.dequeue();
      }

      ASSERT_TRUE(q2.empty());
      ASSERT_EQ(q2.size(), 0);
    }

    TEST(CircularArrayQueue, CopyAssignment)
    {
      CircularArrayQueue<int> q1(11);

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      CircularArrayQueue<int> q2 = q1;

      while (!q1.empty())
      {
	ASSERT_EQ(q1.front(), 10-q1.size());
	ASSERT_EQ(q1.back(), 9);
	q1.dequeue();
      }

      ASSERT_TRUE(q1.empty());
      ASSERT_EQ(q1.size(), 0);

      ASSERT_FALSE(q2.empty());
      ASSERT_EQ(q2.size(), 10);

      while (!q2.empty())
      {
	ASSERT_EQ(q2.front(), 10-q2.size());
	ASSERT_EQ(q2.back(), 9);
	q2.dequeue();
      }

      ASSERT_TRUE(q2.empty());
      ASSERT_EQ(q2.size(), 0);
    }

  } // ! namespace queuetesting
} // ! namespace queues
