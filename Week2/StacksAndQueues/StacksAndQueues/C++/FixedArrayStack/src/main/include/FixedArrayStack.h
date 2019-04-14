#ifndef SRC_MAIN_INCLUDE_FIXEDARRAYSTACK_H_
#define SRC_MAIN_INCLUDE_FIXEDARRAYSTACK_H_

// C++
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

namespace stack
{
  template<typename T>
  class FixedArrayStack final
  {
   public:

    // Public member functions

    explicit FixedArrayStack(std::size_t N);
    FixedArrayStack(const FixedArrayStack& other);
    FixedArrayStack& operator=(const FixedArrayStack& other);
    FixedArrayStack(FixedArrayStack&&) = default;
    FixedArrayStack& operator=(FixedArrayStack&&) = default;
    ~FixedArrayStack();
    
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    const T& top() const;
    void push(const T& t);
    void pop();

   private:

    // Private data members

    std::size_t m_sz;
    std::size_t m_N;
    T *m_a;

  }; // ! class FixedArrayStack

  // Public member function definitions.

  template<typename T>
  FixedArrayStack<T>::FixedArrayStack(std::size_t N)
    : m_sz(0)
    , m_N(N)
    , m_a(new T[this->m_N])
  {}

  template<typename T>
  FixedArrayStack<T>::FixedArrayStack(const FixedArrayStack& other)
    : m_sz(other.m_sz)
    , m_N(other.m_N)
    , m_a(new T[this->m_N])
  {
    std::copy(other.m_a, other.m_a+other.m_sz, this->m_a);
  }

  template<typename T>
  FixedArrayStack<T>& FixedArrayStack<T>::operator=(const FixedArrayStack& other)
  {
    if (&other != this)
    {
      const FixedArrayStack tmp(other);
      std::swap(this->m_sz, tmp.m_sz);
      std::swap(this->m_N, tmp.m_N);
      std::swap(this->m_a, tmp.m_a);
    }
    
    return *this;
  }

  template<typename T>
  FixedArrayStack<T>::~FixedArrayStack()
  {
    delete [] this->m_a;
    this->m_a = nullptr;
  }

  template<typename T>
  bool FixedArrayStack<T>::empty() const
  {
    return this->m_sz == 0;
  }

  template<typename T>
  std::size_t FixedArrayStack<T>::size() const
  {
    return this->m_sz;
  }

  template<typename T>
  std::size_t FixedArrayStack<T>::capacity() const
  {
    return this->m_N;
  }

  template<typename T>
  const T& FixedArrayStack<T>::top() const
  {
    if (this->empty())
    {
      throw std::logic_error("top: Empty FixedArrayStack.");
    }

    return this->m_a[this->m_sz-1];
  }

  template<typename T>
  void FixedArrayStack<T>::push(const T& t)
  {
    if (this->size() == this->capacity())
    {
      throw std::logic_error("push: Full FixedArrayStack.");
    }

    this->m_a[this->m_sz++] = t;
  }

  template<typename T>
  void FixedArrayStack<T>::pop() 
  {
    if (this->empty())
    {
      throw std::logic_error("pop: Empty FixedArrayStack.");
    }

    --this->m_sz;
  }

} // ! namespace stack

#endif // ! SRC_MAIN_INCLUDE_FIXEDARRAYSTACK_H_
