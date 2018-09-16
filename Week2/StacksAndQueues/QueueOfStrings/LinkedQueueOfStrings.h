#ifndef GUARD_LINKED_QUEUE_OF_STRING_H_
#define GUARD_LINKED_QUEUE_OF_STRINGS_H_

#include "QueueOfStrings.h"

namespace queues
{
  class LinkedQueueOfStrings : public QueueOfStrings
  {
   public:
    LinkedQueueOfStrings();
    virtual ~LinkedQueueOfStrings();
    
    LinkedQueueOfStrings(const LinkedQueueOfStrings& other);
    LinkedQueueOfStrings& operator=(const LinkedQueueOfStrings& other);

    virtual bool empty() const;
    virtual std::size_t size() const;
    virtual std::string front() const;
    virtual std::string back() const;
    virtual void enqueue(const std::string& s);
    virtual void dequeue();

  private:
    struct Node
    {
      Node(const std::string& val_, Node *next_ = nullptr)
        : val(val_)
        , next(next_)
      {}

      std::string val;
      Node *next;
    }; // ! struct Node

    std::size_t m_sz;
    Node *m_head;
    Node *m_tail;
  }; // ! class LinkedQueueOfStrings

} // ! namespace queues

#endif
