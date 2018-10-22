#ifndef SRC_MAIN_INCLUDE_RESIZINGARRAYQUEUE_H_
#define SRC_MAIN_INCLUDE_RESIZINGARRAYQUEUE_H_

// C++
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace queues
{
  template<typename T>
  class ResizingArrayQueue final
  {
   public:
    
    // Public data members

    ResizingArrayQueue();
    ResizingArrayQueue(const ResizingArrayQueue& other);
    ResizingArrayQueue& operator=(const ResizingArrayQueue& other);
    ~ResizingArrayQueue();

    bool empty() const;
    std::size_t size() const;
    const T& front() const;
    const T& back() const;
    void enqueue(const T& val);
    void dequeue();

   private:
    
    std::size_t m_N;
    std::size_t m_head;
    std::size_t m_tail;
    T *m_a;

  }; // ! class ResizingArrayQueue

  template<typename T>
  ResizingArrayQueue<T>::ResizingArrayQueue()
    : m_N(1)
    , m_head(0)
    , m_tail(0)
    , m_a(new T[this->m_N])
  {}

  template<typename T>
  ResizingArrayQueue<T>::ResizingArrayQueue(const ResizingArrayQueue& other)
    : m_N(std::max<std::size_t>(1, other.size()))
    , m_head(0)
    , m_tail(other.size())
    , m_a(new T[this->m_N])
  {
    std::copy(other.m_a+other.m_head, other.m_a+other.m_tail, this->m_a);
  }

  template<typename T>
  ResizingArrayQueue<T>& ResizingArrayQueue<T>::operator=(const ResizingArrayQueue& other)
  {
    if (&other != this)
    {
      ResizingArrayQueue q(other);

      std::swap<std::size_t>(this->m_N, q.m_N);
      std::swap<std::size_t>(this->m_head, q.m_head);
      std::swap<std::size_t>(this->m_tail, q.m_tail);
      std::swap<std::size_t>(this->m_a, q.m_a);
    }

    return *this;
  }

  template<typename T>
  ResizingArrayQueue<T>::~ResizingArrayQueue()
  {
    delete [] this->m_a;
  }

  template<typename T>
  bool ResizingArrayQueue<T>::empty() const
  {
    return this->m_head == this->m_tail;
  }

  template<typename T>
  std::size_t ResizingArrayQueue<T>::size() const
  {
    return this->m_tail - this->m_head;
  }

  template<typename T>
  const T& ResizingArrayQueue<T>::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }
    
    return this->m_a[this->m_head];
  }

  template<typename T>
  const T& ResizingArrayQueue<T>::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }
    
    return this->m_a[this->m_tail-1];
  }

  template<typename T>
  void ResizingArrayQueue<T>::enqueue(const T& val)
  {
    if (this->m_tail == this->m_N)
    {
      // Queue is full. Double remaining capacity.

      // Store old data.
      const std::size_t sz = this->size();
      const std::size_t c = std::max<std::size_t>(1, 2*sz);

      // Copy data to new array.
      T *a = new T[c];
      std::copy( this->m_a+this->m_head
               , this->m_a+this->m_tail
	       , a
	       );
      
      // Update data.
      this->m_N = c;
      this->m_head = 0;
      this->m_tail = sz;
      std::swap<T*>(a, this->m_a);

      // Delete old data
      delete [] a;
    }

    this->m_a[this->m_tail++] = val;
  }

  template<typename T>
  void ResizingArrayQueue<T>::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");
    }

    const std::size_t c = this->m_N - this->m_head;

    if (c <= this->m_N/4)
    {
      // Store old data.
      const std::size_t old_size = this->size();
      const std::size_t new_size = std::max<std::size_t>(1, c/2);

      // Copy old data to new array.
      T *a = new T[new_size];
      std::copy(this->m_a+this->m_head, this->m_a+this->m_tail, a);

      // Update data.
      this->m_N = new_size;
      this->m_head = 0;
      this->m_tail = old_size;
      std::swap<T*>(a, this->m_a);
    }

    ++this->m_head;
  }

} // ! namespace queues

#endif // ! SRC_MAIN_INCLUDE_RESIZINGARRAYQUEUE_H_
