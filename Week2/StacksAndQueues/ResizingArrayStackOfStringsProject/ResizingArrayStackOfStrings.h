/*
 * ResizingArrayStackOfStrings.h
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#ifndef RESIZINGARRAYSTACKOFSTRINGS_H_
#define RESIZINGARRAYSTACKOFSTRINGS_H_

#include <string>

class ResizingArrayStackOfStrings final {
 public:
	ResizingArrayStackOfStrings();
	ResizingArrayStackOfStrings(const ResizingArrayStackOfStrings&);
	ResizingArrayStackOfStrings& operator=(const ResizingArrayStackOfStrings&);
	~ResizingArrayStackOfStrings();

	bool empty() const;
	std::size_t size() const;
	const std::string& top() const;
	void push(const std::string& s);
	void pop();
	std::size_t capacity() const;

 private:
	std::string *m_a;
	std::size_t m_capacity;
	std::size_t m_head;
};

#endif /* RESIZINGARRAYSTACKOFSTRINGS_H_ */
