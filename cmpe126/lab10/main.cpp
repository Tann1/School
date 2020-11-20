#include <stdlib.h>
#include <time.h>
#include "hashtable.h"
#include "hashtablequad.h"
#include "hashtablechaining.h"


int main() {
	unsigned int HTsize = 10;
	int randNum, num;
	char input;
	int* sequence = new int[HTsize];
	srand(time(NULL));
	HashTable test(HTsize);	//linear probing test 
	HashTableQuad quad_test(HTsize);
	HashTableChaining chain_test(HTsize); 

	for (int i = 0; i < HTsize; ++i) {
		randNum = rand() % 100 + 1;
		test.insert(randNum);
		quad_test.insert(randNum);
		chain_test.insert(randNum);
		sequence[i] = randNum;
	}

	std::cout << "printing the sequence in which the numbers came" << std::endl;
	for (int i = 0; i < HTsize; ++i)
		std::cout << sequence[i] << " ";
	std::cout << std::endl << std::endl;
	std::cout << "printing table (linear probing)" << std::endl;
	test.print(); std::cout << std::endl << std::endl;
	std::cout << "printing table (quadratic table)" << std::endl;
	quad_test.print(); std::cout << std::endl << std::endl;
	std::cout << "printing table (chaining)" << std::endl;
	chain_test.print();
	while(true) {
		std::cout << "search the table (y/n): ";
		std::cin >> input;
		if ((input | 32) != 'y')
			break;
		std::cout << "enter number: ";
		std::cin >> num;
		std::cout << "found (linear probing): " << num << " at position: " << test.search(num) << std::endl;
		std::cout << "found (quadratic probing): " << num << " at position: " << quad_test.search(num) << std::endl;
		std::cout << "found (chaining): " << num << " at position: " << chain_test.search(num) << std::endl;
	}
	delete []sequence;
	return 0;
}
