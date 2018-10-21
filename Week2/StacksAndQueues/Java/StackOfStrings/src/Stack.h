/*
 * Stack.h
 *
 *  Created on: 10 Sep 2018
 *      Author: danielcumberbatch
 */
#ifndef STACK_H_
#define STACK_H_

#include <cstdlib>
#include <string>

class stack
{
 public:
	stack();
	~stack();

	bool empty() const;
	std::size_t size() const;
	std::string top() const;
	void push(const std::string&);
	void pop();

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

	Node *m_head;
	std::size_t m_sz;

}; // ! class Stack

#endif /* STACK_H_ */
