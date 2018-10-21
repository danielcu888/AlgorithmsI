#ifndef SRC_MAIN_INCLUDE_FIXEDARRAYQUEUE_H_
#define SRC_MAIN_INCLUDE_FIXEDARRAYQUEUE_H_

// C++
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace queues
{
  template<typename T>
  class FixedArrayQueue final
  {
   public:
    
    // Public data members

    explicit FixedArrayQueue(std::size_t N);
    FixedArrayQueue(const FixedArrayQueue& other);
    FixedArrayQueue& operator=(const FixedArrayQueue& other);
    ~FixedArrayQueue();

    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;
    const T& front() const;
    const T& back() const;
    void enqueue(const T& val);
    void dequeue();

   private:
    
    std::size_t m_N;
    std::size_t m_head;
    std::size_t m_tail;
    T *m_a;

  }; // ! class FixedArrayQueue

  template<typename T>
  FixedArrayQueue<T>::FixedArrayQueue(std::size_t N)
    : m_N(N)
    , m_head(0)
    , m_tail(0)
    , m_a(new T[this->m_N])
  {}

  template<typename T>
  FixedArrayQueue<T>::FixedArrayQueue(const FixedArrayQueue& other)
    : m_N(std::max<std::size_t>(1, other.size()))
    , m_head(0)
    , m_tail(other.size())
    , m_a(new T[this->m_N])
  {
    std::copy(other.m_a+other.m_head, other.m_a + other.m_tail, this->m_a);
  }

  template<typename T>
  FixedArrayQueue<T>& FixedArrayQueue<T>::operator=(const FixedArrayQueue& other)
  {
    if (&other != this)
    {
      FixedArrayQueue q(other);

      std::swap<std::size_t>(this->m_N, q.m_N);
      std::swap<std::size_t>(this->m_head, q.m_head);
      std::swap<std::size_t>(this->m_tail, q.m_tail);
      std::swap<std::size_t>(this->m_a, q.m_a);
    }

    return *this;
  }

  template<typename T>
  FixedArrayQueue<T>::~FixedArrayQueue()
  {
    delete [] this->m_a;
  }

  template<typename T>
  bool FixedArrayQueue<T>::empty() const
  {
    return this->m_head == this->m_tail;
  }

  template<typename T>
  std::size_t FixedArrayQueue<T>::size() const
  {
    return this->m_tail - this->m_head;
  }

  template<typename T>
  std::size_t FixedArrayQueue<T>::capacity() const
  {
    return this->m_N - this->m_head;
  }

  template<typename T>
  const T& FixedArrayQueue<T>::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }
    
    return this->m_a[this->m_head];
  }

  template<typename T>
  const T& FixedArrayQueue<T>::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }
    
    return this->m_a[this->m_tail-1];
  }

  template<typename T>
  void FixedArrayQueue<T>::enqueue(const T& val)
  {
    if (this->m_tail == this->m_N)
    {
      throw std::logic_error("enqueue: Full Queue.");
    }

    this->m_a[this->m_tail++] = val;
  }

  template<typename T>
  void FixedArrayQueue<T>::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");
    }

    ++this->m_head;
  }

} // ! namespace queues

#endif // ! SRC_MAIN_INCLUDE_FIXEDARRAYQUEUE_H_
