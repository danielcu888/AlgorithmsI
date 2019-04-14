#ifndef SRC_MAIN_INCLUDE_STACKWITHMAX_H_
#define SRC_MAIN_INCLUDE_STACKWITHMAX_H_

// stack
#include "LinkedListStack.h"

// C++
#include <cstdlib>

namespace iq
{
  template<typename T>
  class StackWithMax final
  {
   public:

    // Public member functions

    StackWithMax() = default;
    StackWithMax(const StackWithMax& other) = default;
    StackWithMax& operator=(const StackWithMax& other) = default;
    StackWithMax(StackWithMax&&) = default;
    StackWithMax& operator=(StackWithMax&&) = default;
    ~StackWithMax() = default;

    bool empty() const;
    std::size_t size() const;
    const T& top() const;
    void push(const T& val);
    void pop();
    const T& max() const;

   private:

    stack::LinkedListStack<T> m_s;
    stack::LinkedListStack<T> m_max_s;
     
  }; // ! class StackWithMax

  template<typename T>
  bool StackWithMax<T>::empty() const
  {
    return this->m_s.empty();
  }

  template<typename T>
  std::size_t StackWithMax<T>::size() const
  {
    return this->m_s.size();
  }

  template<typename T>
  const T& StackWithMax<T>::top() const
  {
    return this->m_s.top();
  }

  template<typename T>
  void StackWithMax<T>::push(const T& val)
  {
    this->m_s.push(val);
    if (this->m_max_s.empty())
    {
      this->m_max_s.push(val);
    }
    else
    {
      if (this->m_max_s.top() <= val)
      {
	this->m_max_s.push(val);
      }
    }
  }

  template<typename T>
  void StackWithMax<T>::pop()
  {
    if (!this->m_max_s.empty())
    {
      if (this->m_max_s.top() == this->m_s.top())
      {
	this->m_max_s.pop();
      }
    }

    this->m_s.pop();
  }

  template<typename T>
  const T& StackWithMax<T>::max() const
  {
    return this->m_max_s.top();
  }

} // ! namespace iq

#endif // ! SRC_MAIN_INCLUDE_STACKWITHMAX_H_
