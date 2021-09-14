#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ArrayList.h"


int main() {
	ArrayList<int> test(15);

	srand(time(NULL));
	std::cout << "testing for min 5 times" << std::endl;
	for (int j = 0; j < 5; ++j) {		
		for (int i = 0; i < 15; ++i)
			test.insert(i, rand() % 15 + 1); //1 to 15 random num
		std::cout << "printing list: ";
		test.print(); 
		std::cout << "min: " << test.getMin() << std::endl;	
		std::cout << std::endl;
		test.clear_list();
	}
	return 0;
}
