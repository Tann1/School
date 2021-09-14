#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "ArrayStack.h"

/*
//Recursive solution from line 9 to 37 
std::string reverse(std::string str) {

	unsigned int start = 0, end = str.length() - 1;
	char temp;

	while (start < end) {
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}

	return str;

}


std::string generateBinary(unsigned int dec) {
	std::string s(1, (dec % 2) + 48);

	if (dec / 2 == 0) 
		return s;
	return s + generateBinary(dec/2);
}

std::string dtob(unsigned int dec) {
	std::string result = generateBinary(dec); //the answer will be in reverse order
	return reverse(result);
	
}
*/

std::string dtob(unsigned int dec) {
	
	ArrayStack<char> binary(32); //32 because 32 bits in 4bytes (size of type int)
	std::string result;

	for (int i = 0; i < binary.maxSize(); ++i) {
		binary.push((dec % 2) + 48); //+ 48 because character integers start from 48 in ASCII table
		dec = dec / 2;
	}
	
	for (int i = 0; i < binary.maxSize(); ++i){
		if (i % 4 == 0 && i != 0) //better formatting divided into 4-bits of the 32 bits
			result.append(" ");	
		result.append(1, binary.pop());
	}
	return result;
}


int main() {

	srand(time(NULL));	
	
	std::cout << "checking for verifcation range from 0 to 255 for validity (easy to check)." << std::endl;
	for (int i = 0, num; i < 10; ++i) {
		num = rand() % 256;
		std::cout << std::setw(3) << std::right << num << ": " << dtob(num) << std::endl;
	}	
	std::cout << std::endl;
	std::cout << "A wider range 0 to MAX_INT - 1." << std::endl;
	unsigned int MAX_INT = ~0; //complement of all 0s to give max int didn't feel like looking up max_int 
	for (int i = 0, num; i < 10; ++i) {
		num = rand() % MAX_INT;
		std::cout << std::setw(10) << std::right << num << ": " << dtob(num) << std::endl;
	}	
	return 0;
}
