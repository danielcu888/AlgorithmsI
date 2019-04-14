// queues
#include "LinkedListQueue.h"

// Testing
#include <gtest/gtest.h>

namespace queues
{
  namespace queuetesting
  {
    TEST(LinkedListQueue, ConstructorOneParameter)
    {
      LinkedListQueue<int> q;
    }

    TEST(LinkedListQueue, Empty)
    {
      LinkedListQueue<int> q;
      ASSERT_TRUE(q.empty());
    }

    TEST(LinkedListQueue, Size)
    {
      LinkedListQueue<int> q;
      ASSERT_EQ(q.size(), 0);
    }

    TEST(LinkedListQueue, FrontThrowsIfEmpty)
    {
      LinkedListQueue<int> q;
      ASSERT_THROW(q.front(), std::logic_error);
    }

    TEST(LinkedListQueue, BackThrowsIfEmpty)
    {
      LinkedListQueue<int> q;
      ASSERT_THROW(q.back(), std::logic_error);
    }

    TEST(LinkedListQueue, EnqueueSingleItem)
    {
      LinkedListQueue<int> q;
      q.enqueue(2);
      ASSERT_FALSE(q.empty());
      ASSERT_EQ(q.size(), 1);
      ASSERT_EQ(q.front(), 2);
      ASSERT_EQ(q.back(), 2);
    }

    TEST(LinkedListQueue, DequeueSingleItem)
    {
      LinkedListQueue<int> q;
      q.enqueue(2);
      q.dequeue();
    }

    TEST(LinkedListQueue, DequeueThrowsIfEmpty)
    {
      LinkedListQueue<int> q;
      ASSERT_THROW(q.dequeue(), std::logic_error);
    }

    TEST(LinkedListQueue, EnqueueMultipleElements)
    {
      LinkedListQueue<int> q;
      for (int i = 0; i < 10; ++i)
      {
	q.enqueue(i);
	ASSERT_FALSE(q.empty());
	ASSERT_EQ(q.size(), i+1);
	ASSERT_EQ(q.front(), 0);
	ASSERT_EQ(q.back(), i);
      }

      ASSERT_EQ(q.size(), 10);
    }

    TEST(LinkedListQueue, DequeueMultipleElements)
    {
      LinkedListQueue<int> q;

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

    TEST(LinkedListQueue, CopyConstrutor)
    {
      LinkedListQueue<int> q1;

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      LinkedListQueue<int> q2(q1);

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

    TEST(LinkedListQueue, CopyAssignment)
    {
      LinkedListQueue<int> q1;

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      LinkedListQueue<int> q2 = q1;

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
