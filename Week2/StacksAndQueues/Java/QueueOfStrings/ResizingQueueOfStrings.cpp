#include "ResizingQueueOfStrings.h"

#include <algorithm>

namespace queues
{

  ResizingQueueOfStrings::ResizingQueueOfStrings()
    : m_capacity(1)
    , m_head(0)
    , m_tail(0)
    , m_a(new std::string(this->m_capacity))
  {}

  ResizinfQueueOfStrings::~ResizingQueueOfStrings()
  {
    delete [] this->m_a;
  }

  ResizingQueueOfStrings::ResizingQueueOfStrings(const ResizingQueueOfStrings& other)
    : m_head(other->m_head)
    , m_tail(other->m_tail)
    , m_capacity(other->m_capacity)
    , m_a(new std::string[other->m_capacity])
  {
    std::copy(other->m_a, other->m_a+other->m_capacity, this->m_a);
  }

  ResizingQueueOfStrings& ResizingQueueOfStrings::operator=(const ResizingQueueOfStrings& other)
  {
    if (this != &other)
    {
      ResizingQueueOfStrings tmp(other);
      this->m_head = tmp->m_head;
      this->m_tail = tmp->m_tail;
      this->m_capacity = tmp->m_capacity;
      std::swap(this->m_a, tmp->m_a);
    }

    return *this;
  }

  bool ResizingQueueOfStrings::empty() const
  {
    return this->size() == 0;
  }

  std::size_t ResizingQueueOfStrings::size() const
  {
    return this->m_tail - this->m_head;
  }

  std::string ResizingQueueOfStrings::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }

    return this->m_a[this->m_head];
  }

  std::string ResizingQueueOfStrings::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }

    return this->m_a[this->m_tail];    
  }

  void ResizingQueueOfStrings::enqueue(const std::string& s)
  {
    if (this->m_tail == this->m_capacity)
    {
      const std::size_t old_size = this->size();
      const std::size_t new_capacity = std::max<std::size_t>(2*old_size, 1);
      std::string* new_a = new std::string[new_capacity];
      std::copy(this->m_a+m_head, this->m_a+this->m_tail, new_a);
      delete [] this->m_a;
      this->m_capacity = new_capacity;
      this->m_head = 0;
      this->m_tail = old_size;
    }

    this->m_a[this->m_tail++] = s;
  }

  void ResizingQueueOfStrings::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");
    }

    if (this->size() <= this->m_capacity/4)
    {
      const std::size_t old_size = this->size();
      const std::size_t new_capacity = std::max<std::size_t>(this->m_capacity/2, 1);
      std::string *new_a = new std::string[new_capacity];
      std::copy(this->m_a+this->m_head, this->m_a+this->m_tail, new_a);
      this->m_capacity = new_capacity;
      this->m_head = 0;
      this0>m_tail = old_size;
    }

    ++this->m_head;
  }

} // ! namespace queues
