/*
 * main.cpp
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#include "FixedCapacityStackOfStrings.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{

	FixedCapacityStackOfStrings st(10);
	for (int i = 0; i < 10; ++i)
	{
		std::string tmp;
		for (int j = 0; j < i; ++j)
		{
			tmp += 'a';
		}
		st.push(tmp);
	}

	while (!st.empty())
	{
		std::cout << "Top is: " << st.top() << std::endl;
		std::cout << "Size is: " << st.size() << std::endl;
		std::cout << "Capacity is: " << st.capacity() << std::endl;
		st.pop();
	}

	return EXIT_SUCCESS;
}




