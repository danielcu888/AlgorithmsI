#ifndef SRC_MAIN_INCLUDE_LINKEDLISTSTACK_H_
#define SRC_MAIN_INCLUDE_LINKEDLISTSTACK_H_

// C++
#include <cstdlib>
#include <stdexcept>

namespace stack
{
  template<typename T>
  class LinkedListStack final
  {
   public:

    // Public member functions

    LinkedListStack();
    LinkedListStack(const LinkedListStack& other);
    LinkedListStack& operator=(const LinkedListStack& other);
    LinkedListStack(LinkedListStack&&) = default;
    LinkedListStack& operator=(LinkedListStack&&) = default;
    ~LinkedListStack();

    bool empty() const;
    std::size_t size() const;
    const T& top() const;
    void push(const T& val);
    void pop();

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

    // Private data members

    std::size_t m_sz;
    Node *m_head;

  }; // ! class LinkedListStack

  template<typename T>
  LinkedListStack<T>::LinkedListStack()
    : m_sz(0)
    , m_head(nullptr)
  {}

  template<typename T>
  LinkedListStack<T>::LinkedListStack(const LinkedListStack& other)
    : m_sz(0)
    , m_head(nullptr)
  {
    if (!other.empty())
    {
      // Create Head.
      Node *tmp = other.m_head;
      Node *tail = this->m_head = new Node(tmp->val);
      ++this->m_sz;
      tmp = tmp->next;

      // Append remaining to current tail.
      while (tmp != nullptr)
      {
	tail->next = new Node(tmp->val);
	++this->m_sz;

	// Update tail.
	tail = tail->next;

	// Step to next reference Node.
	tmp = tmp->next;
      }
    }
  }

  template<typename T>
  LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack& other)
  {
    if (this != &other)
    {
      LinkedListStack tmp(other);
      std::swap<std::size_t>(this->m_sz, tmp.m_sz);
      std::swap<Node*>(this->m_head, tmp.m_head);
    }

    return *this;
  }

  template<typename T>
  LinkedListStack<T>::~LinkedListStack()
  {
    while (!this->empty())
    {
      this->pop();
    }
  }

  template<typename T>
  bool LinkedListStack<T>::empty() const
  {
    return this->m_head == nullptr;
  }

  template<typename T>
  std::size_t LinkedListStack<T>::size() const
  {
    return this->m_sz;
  }

  template<typename T>
  const T& LinkedListStack<T>::top() const
  {
    if (this->empty())
    {
      throw std::logic_error("top: Empty Stack.");
    }

    return this->m_head->val;
  }

  template<typename T>
  void LinkedListStack<T>::push(const T& val)
  {
    this->m_head = new Node(val, this->m_head);
    ++this->m_sz;
  }

  template<typename T>
  void LinkedListStack<T>::pop()
  {
    if (this->empty())
    {
      throw std::logic_error("pop: empty Stack.");
    }

    Node *tmp = this->m_head;
    this->m_head = tmp->next;
    delete tmp;
    --this->m_sz;
  }

} // ! namespace stack

#endif
