//============================================================================
// Name        : main.cpp
// Author      : Gadkari
// Version     : 1
// Description : Queue implementation test. Comment out parts you do not need.
//============================================================================

#include <iostream>
#include "stackQueue.h"
using namespace std;

int main() {
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
	/*
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
	}*/
	return 0;
}
