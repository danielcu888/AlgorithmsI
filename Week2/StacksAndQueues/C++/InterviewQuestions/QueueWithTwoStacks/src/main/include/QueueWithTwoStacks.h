#ifndef SRC_MAIN_INCLUDE_QUEUEWITHTWOSTACKS_H_
#define SRC_MAIN_INCLUDE_QUEUEWITHTWOSTACKS_H_

// stack
#include "LinkedListStack.h"

// C++
#include <cstdlib>

namespace iq
{
  template<typename T>
  class QueueWithTwoStacks final
  {
   public:
    QueueWithTwoStacks();
    QueueWithTwoStacks(const QueueWithTwoStacks&) = default;
    QueueWithTwoStacks& operator=(const QueueWithTwoStacks&) = default;
    QueueWithTwoStacks(QueueWithTwoStacks&&) = default;
    QueueWithTwoStacks& operator=(QueueWithTwoStacks&&) = default;
    ~QueueWithTwoStacks() = default;
    
    bool empty() const;
    std::size_t size() const;
    const T& front();
    const T& back();
    void enqueue(const T& val);
    void dequeue();

   private:

    void exchange();

    stack::LinkedListStack<T> m_enqueue;
    stack::LinkedListStack<T> m_dequeue;
    bool m_enqueuing;

  }; // ! class QueueWithTwoStacks

  template<typename T>
  QueueWithTwoStacks<T>::QueueWithTwoStacks()
    : m_enqueue()
    , m_dequeue()
    , m_enqueuing(true)
  {}

  template<typename T>
  bool QueueWithTwoStacks<T>::empty() const
  {
    if (this->m_enqueuing)
    {
      return this->m_enqueue.empty();
    }

    return this->m_dequeue.empty();
  }

  template<typename T>
  std::size_t QueueWithTwoStacks<T>::size() const
  {
    if (this->m_enqueuing)
    {
      return this->m_enqueue.size();
    }

    return this->m_dequeue.size();
  }

  template<typename T>
  const T& QueueWithTwoStacks<T>::front()
  {
    if (this->m_enqueuing)
    {
      this->exchange();
    }

    return this->m_dequeue.top();
  }

  template<typename T>
  const T& QueueWithTwoStacks<T>::back()
  {
    if (!this->m_enqueuing)
    {
      this->exchange();
    }

    return this->m_enqueue.top();
  }

  template<typename T>
  void QueueWithTwoStacks<T>::enqueue(const T& val)
  {
    if (!this->m_enqueuing)
    {
      this->exchange();
    }

    this->m_enqueue.push(val);
  }

  template<typename T>
  void QueueWithTwoStacks<T>::dequeue()
  {
    if (this->m_enqueuing)
    {
      this->exchange();
    }

    this->m_dequeue.pop();
  }

  template<typename T>
  void QueueWithTwoStacks<T>::exchange()
  {
    if (this->m_enqueuing)
    {
      while (!this->m_enqueue.empty())
      {
	this->m_dequeue.push(this->m_enqueue.top());
	this->m_enqueue.pop();
      }

      this->m_enqueuing = false;
    }
    else
    {
      while (!this->m_dequeue.empty())
      {
	this->m_enqueue.push(this->m_dequeue.top());
	this->m_dequeue.pop();
      }

      this->m_enqueuing = true;      
    }
  }

} // ! namespace iq


#endif // ! SRC_MAIN_INCLUDE_QUEUEWITHTWOSTACKS_H_
