// stack
#include "LinkedListStack.h"

// Testing
#include <gtest/gtest.h>

// C++
#include <string>

namespace stack
{
  namespace stacktesting
  {
    TEST(StackTests, ConstructorOneParameter)
    {
      LinkedListStack<int> st;
    }

    TEST(StackTests, EmptyTrue)
    {
      LinkedListStack<int> st;
      ASSERT_TRUE(st.empty());
    }

    TEST(StackTests, EmptyFalse)
    {
      LinkedListStack<int> st;
      st.push(4);
      ASSERT_FALSE(st.empty());      
    }

    TEST(StackTests, SizeEmpty)
    {
      LinkedListStack<int> st;
      ASSERT_EQ(st.size(), 0);
    }

    TEST(StackTests, SizeNonEmpty)
    {
      LinkedListStack<int> st;
      st.push(4);
      ASSERT_EQ(st.size(), 1);
    }

    TEST(StackTests, TopThrowsIfEmpty)
    {
      LinkedListStack<int> st;
      ASSERT_THROW(st.top(), std::logic_error);
    }

    TEST(StackTests, TopNonEmpty)
    {
      LinkedListStack<int> st;
      st.push(5645);
      ASSERT_EQ(st.top(), 5645);
    }

    TEST(StackTests, PushNonFull)
    {
      LinkedListStack<int> st;
      st.push(1);
      ASSERT_EQ(st.top(), 1);
      ASSERT_EQ(st.size(), 1);
      ASSERT_FALSE(st.empty());
    }

    TEST(StackTetsts, PushToReallocate)
    {
      LinkedListStack<int> st;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st.push(1);
	st.push(2);
      }
    }

    TEST(StackTests, PopThrowsIfEmpty)
    {
      LinkedListStack<double> st;
      ASSERT_THROW(st.pop(), std::logic_error);
    }

    TEST(StackTests, PopNonEmpty)
    {
      LinkedListStack<double> st;
      st.push(2);
      st.pop();
    }
    
    TEST(StackTests, PushPopGeneric)
    {
      LinkedListStack<int> st;
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
      LinkedListStack<int> st1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      LinkedListStack<int> st2(st1);

      ASSERT_FALSE(st1.empty());
      ASSERT_EQ(st1.size(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);

      std::string s1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s1 += std::to_string(st1.top());
	st1.pop();
      }

      ASSERT_TRUE(st1.empty());
      ASSERT_EQ(st1.size(), 0);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);

      std::string s2;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s2 += std::to_string(st2.top());
	st2.pop();
      }

      ASSERT_TRUE(st2.empty());
      ASSERT_EQ(st2.size(), 0);

      const std::string expected_str = "9876543210";
      
      ASSERT_STREQ(expected_str.c_str(), s1.c_str());
      ASSERT_STREQ(expected_str.c_str(), s2.c_str());
    }

    TEST(StackTests, CopyAssignmentOperator)
    {
      LinkedListStack<int> st1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      LinkedListStack<int> st2 = st1;

      ASSERT_FALSE(st1.empty());
      ASSERT_EQ(st1.size(), 10);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);

      std::string s1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s1 += std::to_string(st1.top());
	st1.pop();
      }

      ASSERT_TRUE(st1.empty());
      ASSERT_EQ(st1.size(), 0);

      ASSERT_FALSE(st2.empty());
      ASSERT_EQ(st2.size(), 10);

      std::string s2;
      for (std::size_t i = 0; i < 10; ++i)
      {
	s2 += std::to_string(st2.top());
	st2.pop();
      }

      ASSERT_TRUE(st2.empty());
      ASSERT_EQ(st2.size(), 0);

      const std::string expected_str = "9876543210";
      
      ASSERT_STREQ(expected_str.c_str(), s1.c_str());
      ASSERT_STREQ(expected_str.c_str(), s2.c_str());
    }

  } // ! namespace stacktesting
} // ! namespace stack
