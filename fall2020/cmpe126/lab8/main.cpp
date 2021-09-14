//============================================================================
// Name        : main.cpp
// Author      : Gadkari
// Version     : 1
// Description : Queue implementation test. Comment out parts you do not need.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "stackQueue.h"
using namespace std;

int main() {

	srand(time(NULL));

	arrayQueue<int> test(10); //checking for circular functionality

	try{
		arrayQueue<char> charQueue1;
		charQueue1.enqueue('A');
		charQueue1.enqueue('B');
		cout << charQueue1.dequeue() << endl;
		charQueue1.enqueue('C');
		cout << charQueue1.dequeue() << endl;
		charQueue1.enqueue('D');
		cout << charQueue1.dequeue() << endl;
		cout << charQueue1.dequeue() << endl;
		cout << charQueue1.dequeue() << endl;
	}
	catch(const char *e) {
		cout << e << endl;
	}
	
	try{
		stackQueue<char> charQueue2;
		charQueue2.enqueue('A');
		charQueue2.enqueue('B');
		cout << charQueue2.dequeue() << endl;
		charQueue2.enqueue('C');
		cout << charQueue2.dequeue() << endl;
		charQueue2.enqueue('D');
		cout << charQueue2.dequeue() << endl;
		cout << charQueue2.dequeue() << endl;
		cout << charQueue2.dequeue() << endl;
	}
	catch(const char *e) {
		cout << e << endl;
	}


	std::cout << std::endl;
	std::cout << "testing the circular functionality" << std::endl;

	for (int i = 0; i < 10; ++i) 
		test.enqueue(rand() % 15 + 1); //rand num from 1 to 15

	for (int i = 0; i < 5; ++i)
		std::cout << test.dequeue() << " ";
	std::cout << std::endl;
	
	for (int i = 0; i < 5; ++i)
		test.enqueue(rand() % 15 + 1);
	for (int i = 0; i < 10; ++i)
		std::cout << test.dequeue() <<  " ";
	std::cout << std::endl;



	return 0;
}
