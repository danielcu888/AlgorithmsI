// iq
#include "StackWithMax.h"

// Testing
#include <gtest/gtest.h>

// C++
#include <string>
#include <stdexcept>

namespace iq
{
  namespace stacktesting
  {
    TEST(StackWithMaxTests, ConstructorOneParameter)
    {
      StackWithMax<int> st;
    }

    TEST(StackWithMaxTests, EmptyTrue)
    {
      StackWithMax<int> st;
      ASSERT_TRUE(st.empty());
    }

    TEST(StackWithMaxTests, EmptyFalse)
    {
      StackWithMax<int> st;
      st.push(4);
      ASSERT_FALSE(st.empty());      
    }

    TEST(StackWithMaxTests, SizeEmpty)
    {
      StackWithMax<int> st;
      ASSERT_EQ(st.size(), 0);
    }

    TEST(StackWithMaxTests, SizeNonEmpty)
    {
      StackWithMax<int> st;
      st.push(4);
      ASSERT_EQ(st.size(), 1);
    }

    TEST(StackWithMaxTests, TopThrowsIfEmpty)
    {
      StackWithMax<int> st;
      ASSERT_THROW(st.top(), std::logic_error);
    }

    TEST(StackWithMaxTests, TopNonEmpty)
    {
      StackWithMax<int> st;
      st.push(5645);
      ASSERT_EQ(st.top(), 5645);
    }

    TEST(StackWithMaxTests, PushNonFull)
    {
      StackWithMax<int> st;
      st.push(1);
      ASSERT_EQ(st.top(), 1);
      ASSERT_EQ(st.size(), 1);
      ASSERT_FALSE(st.empty());
    }

    TEST(StackWithMaxTests, PushToReallocate)
    {
      StackWithMax<int> st;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st.push(1);
	st.push(2);
      }
    }

    TEST(StackWithMaxTests, PopThrowsIfEmpty)
    {
      StackWithMax<double> st;
      ASSERT_THROW(st.pop(), std::logic_error);
    }

    TEST(StackWithMaxTests, PopNonEmpty)
    {
      StackWithMax<double> st;
      st.push(2);
      st.pop();
    }
    
    TEST(StackWithMaxTests, PushPopGeneric)
    {
      StackWithMax<int> st;
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
    
    TEST(StackWithMaxTests, CopyConstructor)
    {
      StackWithMax<int> st1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      StackWithMax<int> st2(st1);

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

    TEST(StackWithMaxTests, CopyAssignmentOperator)
    {
      StackWithMax<int> st1;
      for (std::size_t i = 0; i < 10; ++i)
      {
	st1.push(i);
      }

      StackWithMax<int> st2 = st1;

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


    TEST(StackWithMaxTests, MaxThrowsWhenEmpty)
    {
      StackWithMax<int> s;
      ASSERT_THROW(s.max(), std::logic_error);
    }

    TEST(StackWithMaxTests, Max)
    {
      StackWithMax<int> s;
      s.push(1);
      ASSERT_EQ(s.max(), 1);
      s.push(4);
      ASSERT_EQ(s.max(), 4);
      s.push(3);
      ASSERT_EQ(s.max(), 4);
      s.push(3);
      ASSERT_EQ(s.max(), 4);
      s.push(4);
      ASSERT_EQ(s.max(), 4);
      s.push(1);
      ASSERT_EQ(s.max(), 4);
      
      s.pop();
      ASSERT_EQ(s.max(), 4);
      s.pop();
      ASSERT_EQ(s.max(), 4);
      s.pop();
      ASSERT_EQ(s.max(), 4);
      s.pop();
      ASSERT_EQ(s.max(), 4);
      s.pop();
      ASSERT_EQ(s.max(), 1);
      s.pop();
    }

  } // ! namespace stacktesting
} // ! namespace stack
