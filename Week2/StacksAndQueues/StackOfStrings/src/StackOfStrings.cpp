//============================================================================
// Name        : StackOfStrings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stack.h"

int main(int argc, char *argv[])
{
	 stack st;

	 std::string s;
	 while (std::cin >> s)
	 {
		 if (s == "-")
		 {
			 std::cout << st.top() << " ";
			 st.pop();
		 }
		 else
		{
			 st.push(s);
		}
	 }

	 return EXIT_SUCCESS;
}
