/*
 * Stack.cpp
 *
 *  Created on: 10 Sep 2018
 *      Author: danielcumberbatch
 */
#include "Stack.h"
#include <stdexcept>

stack::stack()
 : m_head(nullptr)
 , m_sz(0)
{}

stack::~stack()
{
	while (!this->empty())
	{
		this->pop();
	}
}

bool stack::empty() const
{
	return this->m_sz == 0;
}

std::size_t stack::size() const
{
	return this->m_sz;
}

std::string stack::top() const
{
	if (this->empty())
	{
		throw std::logic_error("Attempt to top empty stack.");
	}

	return this->m_head->val;
}

void stack::push(const std::string& s)
{
	this->m_head = new Node(s, this->m_head);
	++this->m_sz;
}

void stack::pop()
{
	if (this->empty())
	{
		throw std::logic_error("Attempt to top empty stack.");
	}

	Node *tmp = this->m_head;
	this->m_head = this->m_head->next;
	delete tmp;
}
