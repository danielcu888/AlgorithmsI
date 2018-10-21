#ifndef SRC_MAIN_INCLUDE_RESIZINGARRAYSTACK_H_
#define SRC_MAIN_INCLUDE_RESIZINGARRAYSTACK_H_

// C++
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <iostream>

namespace stack
{
  template<typename T>
  class ResizingArrayStack final
  {
   public:

    // Public member functions

    ResizingArrayStack();
    ResizingArrayStack(const ResizingArrayStack& other);
    ResizingArrayStack& operator=(const ResizingArrayStack& other);
    ResizingArrayStack(ResizingArrayStack&&) = default;
    ResizingArrayStack& operator=(ResizingArrayStack&&) = default;
    ~ResizingArrayStack();
    
    bool empty() const;
    std::size_t size() const;
    const T& top() const;
    void push(const T& t);
    void pop();

   private:

    // Private data members

    std::size_t m_sz;
    std::size_t m_N;
    T *m_a;

  }; // ! class ResizingArrayStack

  // Public member function definitions.

  template<typename T>
  ResizingArrayStack<T>::ResizingArrayStack()
    : m_sz(0)
    , m_N(1)
    , m_a(new T[this->m_N])
  {}

  template<typename T>
  ResizingArrayStack<T>::ResizingArrayStack(const ResizingArrayStack& other)
    : m_sz(other.m_sz)
    , m_N(other.m_N)
    , m_a(new T[other.m_N])
  {
    std::copy(other.m_a, other.m_a+other.m_sz, this->m_a);
  }

  template<typename T>
  ResizingArrayStack<T>& ResizingArrayStack<T>::operator=(const ResizingArrayStack& other)
  {
    if (&other != this)
    {
      const ResizingArrayStack tmp(other);
      std::swap(this->m_sz, tmp.m_sz);
      std::swap(this->m_N, tmp.m_N);
      std::swap(this->m_a, tmp.m_a);
    }
    
    return *this;
  }

  template<typename T>
  ResizingArrayStack<T>::~ResizingArrayStack()
  {
    delete [] this->m_a;
  }

  template<typename T>
  bool ResizingArrayStack<T>::empty() const
  {
    return this->m_sz == 0;
  }

  template<typename T>
  std::size_t ResizingArrayStack<T>::size() const
  {
    return this->m_sz;
  }

  template<typename T>
  const T& ResizingArrayStack<T>::top() const
  {
    if (this->empty())
    {
      throw std::logic_error("top: Empty ResizingArrayStack.");
    }

    return this->m_a[this->m_sz-1];
  }

  template<typename T>
  void ResizingArrayStack<T>::push(const T& t)
  {
    if (this->m_sz == this->m_N)
    {
      // Stack is at capacity. Double capacity.
      const std::size_t c = std::max<std::size_t>(2*this->m_N, 1);
      T *a = new T[c];
      std::copy(this->m_a, this->m_a + this->m_sz, a);
      this->m_N = c;
      delete [] this->m_a;
      this->m_a = a;
    }

    this->m_a[this->m_sz++] = t;
  }

  template<typename T>
  void ResizingArrayStack<T>::pop() 
  {
    if (this->empty())
    {
      throw std::logic_error("pop: Empty ResizingArrayStack.");
    }

    if (this->m_sz == this->m_N/4)
    {
      // Stack is at 1/4 capacity. Halve capacity.
      const std::size_t c = std::max<std::size_t>(this->m_N/2, 1);
      T *a = new T[c];
      std::copy(this->m_a, this->m_a + this->m_sz, a);
      this->m_N = c;
      delete [] this->m_a;
      this->m_a = a;
    }

    --this->m_sz;
  }

} // ! namespace stack

#endif // ! SRC_MAIN_INCLUDE_RESIZINGARRAYSTACK_H_
