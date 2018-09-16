#include "LinkedQueueOfStrings.h"

#include <stdexcept>

namespace queues
{
  LinkedQueueOfStrings::LinkedQueueOfStrings()
    : m_sz(0)
    , m_head(nullptr)
    , m_tail(nullptr)
  {}

  LinkedQueueOfStrings::~LinkedQueueOfStrings()
  {
    while (!this->empty())
    {
      this->dequeue();
    }
  }

  LinkedQueueOfStrings::LinkedQueueOfStrings(const LinkedQueueOfStrings& other)
    : m_sz(0)
    , m_head(nullptr)
    , m_tail(nullptr)
  {
    Node *tmp = other->m_head;
    while (tmp != nullptr)
    {
      this->enqueue(tmp->val);
    }
  }

  LinkedQueueOfStrings& LinkedQueueOfStrings::operator=(const LinkedWueueOfStrings& other)
  {
    if (this != &other)
    {
      LinkedQueueOfStrings tmp(other);

      Node *tmp_node = tmp->m_head;
      tmp->m_head = this->m_head;
      this->m_head = tmp_node;
      
      tmp_node = tmp->m_tail;
      tmp->m_tail = this->m_tail;
      this->m_tail = tmp_node;

      this->m_sz = tmp->m_sz;
    }

    return *this;
  }

  bool LinkedQueueOfStrings::empty() const
  {
    return this->m_head == nullptr;
  }

  std::size_t LinkedQueueOfStrings::size() const
  {
    return this->m_sz;
  }

  std::string LinkedQueueOfStrings::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }

    return this->m_head->val;
  }

  std::string LinkedQueueOfStrings::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }

    return this->m_tail->val;
  }

  void LinkedQueueOfStrings::enqueue(const std::string& s)
  {
    Node *n = new Node(s);

    if (this->empty())
    {
      this->m_head = this->m_tail = n;
    }
    else
    {
      this->m_tail->next = n;
      this->m_tail = this->m_tail->next;
    }

    ++this->m_sz;
  }

  void LinkedQueueOfStrings::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");
    }

    Node *tmp = this->m_head;
    if (this->m_head == this->m_tail)
    {
      this->m_head = this->m_tail = nullptr;
    }
    else
    {
      this->m_head = this->m_head->next;
    }

    delete tmp;

    --this->m_sz;
  }

} //  ! namespace queues
