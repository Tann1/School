#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <stack>



std::string dtob(unsigned int dec) {

	std::stack<char> binary;
	std::string result; 

	for (int i = 0; i < 32; ++i) {
		binary.push((dec % 2) + 48); //48 because of the ascii style
		dec = dec / 2;
	}

	for (int i = 0; i < 32; ++i) {
		if (i % 4 == 0 && i != 0) //formatting purpose
			result.append(" ");
		result.append(1, binary.top());
		binary.pop();
	}
	return result;

}


int main() { 
	srand(time(NULL));

	std::cout << "STL version." << std::endl;
	std::cout << "ranged from 0 to 255 for easy validation check." << std::endl;

	for (int i = 0, num; i < 20; ++i) {
		num = rand() % 256;
		std::cout << std::setw(3) << std::right << num << ": " << dtob(num) << std::endl;
	}
	return 0;
}
