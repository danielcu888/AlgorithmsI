/*
 * FixedCapacityStackOfStrings.cpp
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#include "FixedCapacityStackOfStrings.h"

#include <stdexcept>
#include <algorithm>

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(std::size_t capacity)
	: m_a(new std::string[capacity])
    , m_capacity(capacity)
    , m_head(0)
{}

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(const FixedCapacityStackOfStrings& other)
	: m_a(new std::string[other.m_capacity])
    , m_capacity(other.m_capacity)
    , m_head(other.m_head)
{
	std::copy(other.m_a, other.m_a+other.m_capacity, this->m_a);
}

FixedCapacityStackOfStrings& FixedCapacityStackOfStrings::operator=(const FixedCapacityStackOfStrings& other)
{
	if (this != &other)
	{
		FixedCapacityStackOfStrings tmp(other);
		std::string *p = tmp.m_a;
		tmp.m_a = this->m_a;
		this->m_a = p;

		this->m_head = tmp.m_head;
		this->m_capacity = tmp.m_capacity;
	}

	return *this;
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings()
{
	delete [] this->m_a;
}

bool FixedCapacityStackOfStrings::empty() const
{
	return this->size() == 0;
}

std::size_t FixedCapacityStackOfStrings::size() const
{
	return this->m_head;
}

const std::string& FixedCapacityStackOfStrings::top() const
{
	if (this->empty())
	{
		throw std::logic_error("top::Stack is empty.");
	}

	return this->m_a[this->m_head-1];
}

void FixedCapacityStackOfStrings::push(const std::string& s)
{
	if (this->size() == this->capacity())
	{
		throw std::logic_error("push::Stack is full.");
	}

	this->m_a[this->m_head++] = s;
}

void FixedCapacityStackOfStrings::pop()
{
	if (this->empty())
	{
		throw std::logic_error("pop::Stack is empty.");
	}

	--this->m_head;
}

std::size_t FixedCapacityStackOfStrings::capacity() const
{
	return this->m_capacity;
}
