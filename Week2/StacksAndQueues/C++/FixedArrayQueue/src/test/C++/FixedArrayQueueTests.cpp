// queues
#include "FixedArrayQueue.h"

// Testing
#include <gtest/gtest.h>

namespace queues
{
  namespace queuetesting
  {
    TEST(FixedArrayQueue, ConstructorOneParameter)
    {
      FixedArrayQueue<int> q(10);
    }

    TEST(FixedArrayQueue, Empty)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_TRUE(q.empty());
    }

    TEST(FixedArrayQueue, Size)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_EQ(q.size(), 0);
    }

    TEST(FixedArrayQueue, Capacity)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_EQ(q.capacity(), 10);
    }

    TEST(FixedArrayQueue, FrontThrowsIfEmpty)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_THROW(q.front(), std::logic_error);
    }

    TEST(FixedArrayQueue, BackThrowsIfEmpty)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_THROW(q.back(), std::logic_error);
    }

    TEST(FixedArrayQueue, EnqueueSingleItem)
    {
      FixedArrayQueue<int> q(10);
      q.enqueue(2);
      ASSERT_FALSE(q.empty());
      ASSERT_EQ(q.size(), 1);
      ASSERT_EQ(q.front(), 2);
      ASSERT_EQ(q.back(), 2);
    }

    TEST(FixedArrayQueue, EnqueueThrowsIfFull)
    {
      FixedArrayQueue<int> q(1);
      q.enqueue(2);
      ASSERT_THROW(q.enqueue(3), std::logic_error);
    }

    TEST(FixedArrayQueue, DequeueSingleItem)
    {
      FixedArrayQueue<int> q(10);
      q.enqueue(2);
      q.dequeue();
    }

    TEST(FixedArrayQueue, DequeueThrowsIfEmpty)
    {
      FixedArrayQueue<int> q(10);
      ASSERT_THROW(q.dequeue(), std::logic_error);
    }

    TEST(FixedArrayQueue, EnqueueMultipleElements)
    {
      FixedArrayQueue<int> q(10);
      for (int i = 0; i < 10; ++i)
      {
	q.enqueue(i);
	ASSERT_FALSE(q.empty());
	ASSERT_EQ(q.size(), i+1);
	ASSERT_EQ(q.front(), 0);
	ASSERT_EQ(q.back(), i);
      }

      ASSERT_EQ(q.capacity(), 10);
      ASSERT_EQ(q.size(), 10);
    }

    TEST(FixedArrayQueue, DequeueMultipleElements)
    {
      FixedArrayQueue<int> q(10);

      for (int i = 0; i < 10; ++i)
      {
	q.enqueue(i);
      }

      while (!q.empty())
      {
	ASSERT_EQ(q.size(), q.capacity()); 
	ASSERT_EQ(q.front(), 10-q.size());
	ASSERT_EQ(q.back(), 9);
	q.dequeue();
      }

      ASSERT_TRUE(q.empty());
      ASSERT_EQ(q.size(), 0);
      ASSERT_EQ(q.capacity(), 0);
    }

  } // ! namespace queuetesting
} // ! namespace queues
