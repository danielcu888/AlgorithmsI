#ifndef GUARD_QUEUE_OF_STRINGS_H_
#define GUARD_QUEUE_OF_STRINGS_H_

namespace queues
{
  class QueueOfStrings
  {
   public:
    QueueOfStrings() = default;
    virtual ~QueueOfStrings() = 0;
    
    virtual bool empty() const = 0;
    virtual std::size_t size() const = 0;
    virtual std::string front() const = 0;
    virtual std::string back() const = 0;
    virtual void enqueue(const std::string& s) = 0;
    virtual void dequeue() = 0;    
  };

} // ! namespace queues

#endif
