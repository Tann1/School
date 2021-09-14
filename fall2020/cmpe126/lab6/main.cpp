#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayStack.h"



int main() {

	ArrayStack<int> test(20);
	srand (time(0));

	unsigned int Push = rand() % test.maxSize() + 1;
	unsigned int Pop = rand() % test.maxSize() + 1;

	std::cout << "will push: " << Push << " times." << std::endl;
	std::cout << "will pop: " << Pop << " times." << std::endl;
	
	for (int i = 0; i < Push; ++i) 
		test.push(rand() % 100 + 1);
	std::cout << "size of the stack after pushing: " << test.size() << std::endl;

	std::cout << "Poping: ";
	for (int i = 0; i < Pop; ++i)
		std::cout << test.pop() << " ";
	std::cout << std::endl;
	std::cout << "size of the stack after poping: " << test.size() << std::endl;
	return 0;
} 
