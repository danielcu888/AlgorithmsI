#ifndef GUARD_RESIZING_QUEUE_OF_STRINGS_H_
#define GUARD_RESIZING_QUEUE_OF_STRINGS_H_

namespace queues
{
  class ResizingQueueOfStrings : public QueueOfStrings
  {
   public:
    ResizingQueueOfStrings();
    virtual ResizingQueueOfStrings();
    ResizingQueueOfStrings(const ResizingQueueOfStrings& other);
    ResizingQueueOfStrings& operator=(const ResizingQueueOfStrings& other);

    virtual bool empty() const;
    virtual std::size_t size() const;
    virtual std::string front() const;
    virtual std::string back() const;
    virtual void enqueue(const std::string& s);
    virtual void dequeue();

   private:
    std::size_t m_capacity;
    long long m_head;
    long long m_tail;
    std::string *m_a;

  }; // ! class ResizingQueueOfStrings

} // ! namespace queues

#endif // ! GUARD_RESIZING_QUEUE_OF_STRINGS_H_
