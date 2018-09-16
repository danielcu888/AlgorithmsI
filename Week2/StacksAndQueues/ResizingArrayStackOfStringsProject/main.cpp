/*
 * main.cpp
 *
 *  Created on: 13 Sep 2018
 *      Author: danielcumberbatch
 */

#include "ResizingArrayStackOfStrings.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{

	ResizingArrayStackOfStrings st;
	for (int i = 0; i < 10; ++i)
	  {
	    st.push("a");
	    std::cout << "size: " << st.size() << ", capacity: " << st.capacity() << std::endl;
	  }

	while (!st.empty())
	  {
	    std::cout << "size: " << st.size() << ", capacity: " << st.capacity() << std::endl;
	    st.pop();
	  }

	return EXIT_SUCCESS;
}


