// stack
#include "FixedArrayStack.h"

// Testing
#include <gtest/gtest.h>

// Boost
#include <boost/lexical_cast.hpp>

// C++
#include <string>

namespace stack
{
  namespace stacktesting
  {
    TEST(StackTests, ConstructorOneParameter)
    {
      FixedArrayStack<int> st(10);
    }

    TEST(StackTests, EmptyTrue)
    {
      FixedArrayStack<int> st(10);
      ASSERT_TRUE(st.empty());
    }

    TEST(StackTests, EmptyFalse)
    {
      FixedArrayStack<int> st(10);
      st.push(4);
      ASSERT_FALSE(st.empty());      
    }

    TEST(StackTests, SizeEmpty)
    {
      FixedArrayStack<int> st(10);
      ASSERT_EQ(st.size(), 0);
    }

    TEST(StackTests, SizeNonEmpty)
    {
      FixedArrayStack<int> st(10);
      st.push(4);
      ASSERT_EQ(st.size(), 1);
    }

    TEST(StackTests, Capacity)
    {
      FixedArrayStack<int> st(10);
      ASSERT_EQ(st.capacity(), 10);
    }

    TEST(StackTests, TopThrowsIfEmpty)
    {
      FixedArrayStack<int> st(10);
      ASSERT_THROW(st.top(), std::logic_error);
    }

    TEST(StackTests, TopNonEmpty)
    {
      FixedArrayStack<int> st(10);
      st.push(5645);
      ASSERT_EQ(st.top(), 5645);
    }

    TEST(StackTests, PushNonFull)
    {
      FixedArrayStack<int> st(10);
      st.push(1);
      ASSERT_EQ(st.top(), 1);
      ASSERT_EQ(st.size(), 1);
      ASSERT_FALSE(st.empty());
    }

    TEST(StackTetsts, PushThrowsIfFull)
    {
      FixedArrayStack<int> st(1);
      st.push(1);
      ASSERT_THROW(st.push(2), std::logic_error);
    }

    TEST(StackTests, PopThrowsIfEmpty)
    {
      FixedArrayStack<double> st(10);
      ASSERT_THROW(st.pop(), std::logic_error);
    }

    TEST(StackTests, PopNonEmpty)
    {
      FixedArrayStack<double> st(10);
      st.push(2);
      st.pop();
    }

    TEST(StackTests, PushPopGeneric)
    {
      FixedArrayStack<int> st(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
	st.push(i);
      }

      std::string s;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s += std::to_string(st.top());
	st.pop();
      }

      const std::string expected_str = "9876543210";

      ASSERT_STREQ(expected_str.c_str(), s.c_str());
    }

    TEST(StackTests, CopyConstructor)
    {
      FixedArrayStack<int> st1(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      FixedArrayStack<int> st2(st1);

      ASSERT_FALSE(st1.empty());
      ASSERT_EQ(st1.size(), 10);
      ASSERT_EQ(st1.capacity(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);
      ASSERT_EQ(st2.capacity(), 10);

      std::string s1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s1 += std::to_string(st1.top());
	st1.pop();
      }

      ASSERT_TRUE(st1.empty());
      ASSERT_EQ(st1.size(), 0);
      ASSERT_EQ(st1.capacity(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);
      ASSERT_EQ(st2.capacity(), 10);

      std::string s2;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s2 += std::to_string(st2.top());
	st2.pop();
      }

      ASSERT_TRUE(st2.empty());
      ASSERT_EQ(st2.size(), 0);
      ASSERT_EQ(st2.capacity(), 10);

      const std::string expected_str = "9876543210";
      
      ASSERT_STREQ(expected_str.c_str(), s1.c_str());
      ASSERT_STREQ(expected_str.c_str(), s2.c_str());
    }

    TEST(StackTests, CopyAssignmentOperator)
    {
      FixedArrayStack<int> st1(10);
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      FixedArrayStack<int> st2 = st1;

      ASSERT_FALSE(st1.empty());
      ASSERT_EQ(st1.size(), 10);
      ASSERT_EQ(st1.capacity(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);
      ASSERT_EQ(st2.capacity(), 10);

      std::string s1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s1 += std::to_string(st1.top());
	st1.pop();
      }

      ASSERT_TRUE(st1.empty());
      ASSERT_EQ(st1.size(), 0);
      ASSERT_EQ(st1.capacity(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);
      ASSERT_EQ(st2.capacity(), 10);

      std::string s2;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s2 += std::to_string(st2.top());
	st2.pop();
      }

      ASSERT_TRUE(st2.empty());
      ASSERT_EQ(st2.size(), 0);
      ASSERT_EQ(st2.capacity(), 10);

      const std::string expected_str = "9876543210";
      
      ASSERT_STREQ(expected_str.c_str(), s1.c_str());
      ASSERT_STREQ(expected_str.c_str(), s2.c_str());
    }

  } // ! namespace stacktesting
} // ! namespace stack
