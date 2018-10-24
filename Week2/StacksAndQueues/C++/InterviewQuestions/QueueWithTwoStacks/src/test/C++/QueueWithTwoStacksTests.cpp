// queues
#include "QueueWithTwoStacks.h"

// Testing
#include <gtest/gtest.h>

namespace iq
{
  namespace iqtesting
  {
    TEST(QueueWithTwoStacks, ConstructorOneParameter)
    {
      QueueWithTwoStacks<int> q;
    }

    TEST(QueueWithTwoStacks, Empty)
    {
      QueueWithTwoStacks<int> q;
      ASSERT_TRUE(q.empty());
    }

    TEST(QueueWithTwoStacks, Size)
    {
      QueueWithTwoStacks<int> q;
      ASSERT_EQ(q.size(), 0);
    }

    TEST(QueueWithTwoStacks, FrontThrowsIfEmpty)
    {
      QueueWithTwoStacks<int> q;
      ASSERT_THROW(q.front(), std::logic_error);
    }

    TEST(QueueWithTwoStacks, BackThrowsIfEmpty)
    {
      QueueWithTwoStacks<int> q;
      ASSERT_THROW(q.back(), std::logic_error);
    }

    TEST(QueueWithTwoStacks, EnqueueSingleItem)
    {
      QueueWithTwoStacks<int> q;
      q.enqueue(2);
      ASSERT_FALSE(q.empty());
      ASSERT_EQ(q.size(), 1);
      ASSERT_EQ(q.front(), 2);
      ASSERT_EQ(q.back(), 2);
    }

    TEST(QueueWithTwoStacks, DequeueSingleItem)
    {
      QueueWithTwoStacks<int> q;
      q.enqueue(2);
      q.dequeue();
    }

    TEST(QueueWithTwoStacks, DequeueThrowsIfEmpty)
    {
      QueueWithTwoStacks<int> q;
      ASSERT_THROW(q.dequeue(), std::logic_error);
    }

    TEST(QueueWithTwoStacks, EnqueueMultipleElements)
    {
      QueueWithTwoStacks<int> q;
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

    TEST(QueueWithTwoStacks, DequeueMultipleElements)
    {
      QueueWithTwoStacks<int> q;

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

    TEST(QueueWithTwoStacks, CopyConstrutor)
    {
      QueueWithTwoStacks<int> q1;

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      QueueWithTwoStacks<int> q2(q1);

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

    TEST(QueueWithTwoStacks, CopyAssignment)
    {
      QueueWithTwoStacks<int> q1;

      for (int i = 0; i < 10; ++i)
      {
	q1.enqueue(i);
      }

      QueueWithTwoStacks<int> q2 = q1;

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

  } // ! namespace iqtesting
} // ! namespace iq
