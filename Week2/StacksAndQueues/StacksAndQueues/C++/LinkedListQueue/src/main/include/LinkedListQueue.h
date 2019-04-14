#ifndef SRC_MAIN_INCLUDE_LINKEDLISTQUEUE_H_
#define SRC_MAIN_INCLUDE_LINKEDLISTQUEUE_H_

// C++
#include <cstdlib>
#include <stdexcept>

namespace queues
{
  template<typename T>
  class LinkedListQueue final
  {
   public:
    
    // Public member functions

    LinkedListQueue();
    LinkedListQueue(const LinkedListQueue& other);
    LinkedListQueue& operator=(const LinkedListQueue& other);
    LinkedListQueue(LinkedListQueue&&) = default;
    LinkedListQueue& operator=(LinkedListQueue&&) = default;
    ~LinkedListQueue();

    bool empty() const;
    std::size_t size() const;
    const T& front() const;
    const T& back() const;
    void enqueue(const T& val);
    void dequeue();

   private:
    
    // Private nested classes

    struct Node
    {
      Node(const T& val_, Node *next_ = nullptr)
        : val(val_)
        , next(next_)
      {}

      T val;
      Node *next;
    }; // ! struct Node

    Node *m_head;
    Node *m_tail;
    std::size_t m_sz;

  }; // ! class LinkedListQueue

  template<typename T>
  LinkedListQueue<T>::LinkedListQueue()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_sz(0)
  {}

  template<typename T>
  LinkedListQueue<T>::LinkedListQueue(const LinkedListQueue& other)
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_sz(other.m_sz)
  {
    Node *tmp = other.m_head;
    while (tmp != nullptr)
    {
      Node *n = new Node(tmp->val);

      if (this->m_head == nullptr)
      {
	this->m_head = this->m_tail = n;
      }
      else
      {
	this->m_tail->next = n;
	this->m_tail = this->m_tail->next;
      }

      tmp = tmp->next;
    }
  }

  template<typename T>
  LinkedListQueue<T>& LinkedListQueue<T>::operator=(const LinkedListQueue& other)
  {
    if (&other != this)
    {
      LinkedListQueue q(other);
      std::swap<Node*>(q.m_head, this->m_head);
      std::swap<Node*>(q.m_tail, this->m_tail);
      std::swap<std::size_t*>(q.m_sz, this->m_sz);
    }

    return *this;
  }

  template<typename T>
  LinkedListQueue<T>::~LinkedListQueue() 
  {
    while (!this->empty())
    {
      this->dequeue();
    }
  }

  template<typename T>
  bool LinkedListQueue<T>::empty() const
  {
    return this->m_sz == 0;
  }

  template<typename T>
  std::size_t LinkedListQueue<T>::size() const
  {
    return this->m_sz;
  }

  template<typename T>
  const T& LinkedListQueue<T>::front() const
  {
    if (this->empty())
    {
      throw std::logic_error("front: Empty Queue.");
    }

    return this->m_head->val;
  }

  template<typename T>
  const T& LinkedListQueue<T>::back() const
  {
    if (this->empty())
    {
      throw std::logic_error("back: Empty Queue.");
    }

    return this->m_tail->val;
  }

  template<typename T>
  void LinkedListQueue<T>::enqueue(const T& val)
  {
    Node *n = new Node(val);
    if (this->m_head == nullptr)
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

  template<typename T>
  void LinkedListQueue<T>::dequeue()
  {
    if (this->empty())
    {
      throw std::logic_error("dequeue: Empty Queue.");
    }

    Node *tmp = this->m_head;
    this->m_head = this->m_head->next;
    delete tmp;

    if (this->empty())
    {
      this->m_tail = this->m_head = nullptr;
    }

    --this->m_sz;
  }

} // ! namespace queues

#endif // ! SRC_MAIN_INCLUDE_LINKEDLISTQUEUE_H_

