#include <stdlib.h>
#include <time.h>
#include "hashtable.h"


int main() {
	unsigned int HTsize = 10;
	int randNum, num;
	char input;
	int* sequence = new int[HTsize];
	srand(time(NULL));
	HashTable test(HTsize);	

	for (int i = 0; i < HTsize; ++i) {
		randNum = rand() % 100 + 1;
		test.insert(randNum);
		sequence[i] = randNum;
	}

	std::cout << "printing the sequence in which the numbers came" << std::endl;
	for (int i = 0; i < HTsize; ++i)
		std::cout << sequence[i] << " ";
	std::cout << std::endl;
	std::cout << "printing table" << std::endl;
	test.print(); std::cout << std::endl;
	while(true) {
		std::cout << "search the table (y/n): ";
		std::cin >> input;
		if ((input | 32) != 'y')
			break;
		std::cout << "enter number: ";
		std::cin >> num;
		std::cout << "found " << num << " at postion: " << test.search(num) << std::endl;
	}
	return 0;
}
