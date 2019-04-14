#ifndef SRC_MAIN_INCLUDE_CIRCULARARRAY_H_
#define SRC_MAIN_INCLUDE_CIRCULARARRAY_H_

// C++
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace queues
{
  template<typename T>
  class CircularArrayQueue final
  {
   public:
    
    // Public member functions

    explicit CircularArrayQueue(std::size_t N);
    CircularArrayQueue(const CircularArrayQueue& other);
    CircularArrayQueue& operator=(const CircularArrayQueue& other);
    CircularArrayQueue(CircularArrayQueue&&) = default;
    CircularArrayQueue& operator=(CircularArrayQueue&&) = default;
    ~CircularArrayQueue();

    bool empty() const;
    std::size_t size() const;
    const T& front() const;
    const T& back() const;
    void enqueue(const T& val);
    void dequeue();

   private:
    
    // Private data members

    std::size_t m_N;
    std::size_t m_head;
    std::size_t m_tail;
    T *m_a;

  }; // ! class CircularArrayQueue

  template<typename T>
  CircularArrayQueue<T>::CircularArrayQueue(std::size_t N)
    : m_N(N)
    , m_head(0)
    , m_tail(0)
    , m_a(new T[this->m_N])
  {}

  template<typename T>
  CircularArrayQueue<T>::CircularArrayQueue(const CircularArrayQueue& other)
    : m_N(other.m_N)
    , m_head(other.m_head)
    , m_tail(other.m_tail)
    , m_a(new T[this->m_N])
  {
    std::copy(other.m_a, other.m_a+other.m_N, this->m_a);
  }

  template<typename T>
  CircularArrayQueue<T>& CircularArrayQueue<T>::operator=(const CircularArrayQueue& other)
  {
    if (this != &other)
    {
      CircularArrayQueue q(other);
      std::swap<std::size_t>(this->m_N, q.m_N);
      std::swap<std::size_t>(this->m_head, q.m_head);
      std::swap<std::size_t>(this->m_tail, q.m_tail);
      std::swap<std::size_t>(this->m_a, q.m_a);
    }

    return *this;
  }

  template<typename T>
  CircularArrayQueue<T>::~CircularArrayQueue()
  {
    delete [] this->m_a;
  }

  template<typename T>
  bool CircularArrayQueue<T>::empty() const
  {
    return this->m_head == this->m_tail;
  }

  template<typename T>
  std::size_t CircularArrayQueue<T>::size() const
  {
    if (this->m_tail > this->m_head)
    {
      return this->m_tail - this->m_head;
    }

    return this->m_head - this->m_tail;
  }

  template<typename T>
  const T& CircularArrayQueue<T>::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }

    return this->m_a[this->m_head];
  }

  template<typename T>
  const T& CircularArrayQueue<T>::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }

    return this->m_a[this->m_tail-1];
  }

  template<typename T>
  void CircularArrayQueue<T>::enqueue(const T& val)
  {
    this->m_a[this->m_tail++] = val;
    this->m_tail = this->m_tail % this->m_N;
  }

  template<typename T>
  void CircularArrayQueue<T>::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");      
    }

    ++this->m_head;
    this->m_head = this->m_head % this->m_N;
  }

} // ! namespace queues

#endif // ! SRC_MAIN_INCLUDE_CIRCULARARRAY_H_
