//============================================================================
// Name        : Searching.cpp
// Author      : Mahima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "arrayListT.h"
using namespace std;

int main() {
	srand(time(NULL));
	unsigned int choice = 0, element;
	ArrayList<int> list(30);

	for (int i = 0; i < 30; ++i)
		list.insertEnd(rand() % 100 + 1); //rand number from 1 to 100

	
	do {
	        cout << "Choose your search type:" << endl;
	        cout << "1. Arrays: Sequential Search without recursion" << endl;
	        cout << "2. Arrays: Sequential Search with recursion" << endl;
	        cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
	        cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
	        cout << "5. Linked List: Search without recursion"  << endl;
	        cout << "6. Linked List: Search with recursion" << endl;
	        cout << "Enter 0 to exit" << endl;
	        cout << "Your choice: ";

	        cin >> choice;
		if (choice == 0)
			break;
		std::cout << "List: "; list.print(); 


	        cout<<"\nSpecify the element to be searched for: ";
		cin >> element;

		switch (choice) {
			case 1:
				std::cout << "found element (seq. iter): " << element << " at position: " << list.seqSearchIter(element) << std::endl;
				break;

			case 2:
				std::cout << "found element (seq. rec): " << element << " at position: " << list.seqSearchRec(element) << std::endl;
				break;

		}

		std::cout << std::endl << std::endl;

	 } while(true);
	return 0;
}
