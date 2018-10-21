/*
 * ResizingArrayStackOfStrings.cpp
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#include "ResizingArrayStackOfStrings.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

ResizingArrayStackOfStrings::ResizingArrayStackOfStrings()
  : m_a(new std::string[1])
  , m_capacity(1)
  , m_head(0)
{}

ResizingArrayStackOfStrings::ResizingArrayStackOfStrings(const ResizingArrayStackOfStrings& other)
  : m_a(new std::string[other.m_capacity])
  , m_capacity(other.m_capacity)
  , m_head(other.m_head)
{
  std::copy(other.m_a, other.m_a+other.m_capacity, this->m_a);
}

ResizingArrayStackOfStrings& ResizingArrayStackOfStrings::operator=(const ResizingArrayStackOfStrings& other)
{
  if (this != &other)
    {
      ResizingArrayStackOfStrings tmp(other);
      std::string *p = tmp.m_a;
      tmp.m_a = this->m_a;
      this->m_a = p;

      this->m_capacity = tmp.m_capacity;
      this->m_head = tmp.m_head;
    }

  return *this;
}

ResizingArrayStackOfStrings::~ResizingArrayStackOfStrings()
{
  delete [] this->m_a;
}

bool ResizingArrayStackOfStrings::empty() const
{
  return this->size() == 0;
}

std::size_t ResizingArrayStackOfStrings::size() const
{
  return this->m_head;
}

const std::string& ResizingArrayStackOfStrings::top() const
{
  if (this->empty())
    {
      throw std::logic_error("top: Stack is empty.");
    }

  return this->m_a[this->m_head-1];
}

void ResizingArrayStackOfStrings::push(const std::string& s)
{
  if (this->size() == this->m_capacity)
    {
      const std::size_t new_capacity = std::max<std::size_t>(2*this->size(),1);
      std::string *p = new std::string[new_capacity];
      std::copy(this->m_a, this->m_a+this->m_capacity, p);
      delete [] this->m_a;
      this->m_a = p;

      this->m_capacity = new_capacity;
    }

  this->m_a[this->m_head++] = s;
}

void ResizingArrayStackOfStrings::pop()
{
  if (this->empty())
    {
      throw std::logic_error("pop: Stack is empty.");
    }

  --this->m_head;

  if (this->m_head <= this->m_capacity/4)
    {
      const std::size_t new_capacity = std::max<std::size_t>(1,this->m_capacity/4);
      std::string *p = new std::string[new_capacity];
      std::copy(this->m_a, this->m_a+this->m_head, p);
      delete [] this->m_a;
      this->m_a = p;

      this->m_capacity = new_capacity;
    }
}

std::size_t ResizingArrayStackOfStrings::capacity() const
{
  return this->m_capacity;
}
