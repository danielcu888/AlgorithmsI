/*
 * FixedCapacityStackOfStrings.h
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#include <string>

#ifndef FIXEDCAPACITYSTACKOFSTRINGS_H_
#define FIXEDCAPACITYSTACKOFSTRINGS_H_

class FixedCapacityStackOfStrings final
{
 public:
	FixedCapacityStackOfStrings(std::size_t capacity);
	FixedCapacityStackOfStrings(const FixedCapacityStackOfStrings& other);
	FixedCapacityStackOfStrings& operator=(const FixedCapacityStackOfStrings& other);
	~FixedCapacityStackOfStrings();

	bool empty() const;
	std::size_t size() const;
	const std::string& top() const;
	void push(const std::string& s);
	void pop();
	std::size_t capacity() const;

 private:
	std::string *m_a;
	const std::size_t m_capacity;
	std::size_t m_head;
};

#endif /* FIXEDCAPACITYSTACKOFSTRINGS_H_ */
