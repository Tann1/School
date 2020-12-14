#include <iostream>
#include "helper.h"
#include "sorting.h"
using namespace std;

int main() {
	unsigned int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int* Array = new int[size];

	unsigned int choice = 0;
	while (true) {
		fillRandom(Array, size);
	        cout << "Choose your sorting algorithm:" << endl;
	        cout << "1. Bubble Sort" << endl;
	        cout << "2. Selection Sort" << endl;
	        cout << "3. Insertion Sort" << endl;
	        cout << "4. Merge Sort"  << endl;
	        cout << "5. Quick Sort"  << endl;
	        cout << "Enter 0 to exit" << endl;
	        cout << "Your choice: ";

	        cin >> choice;
		if (choice == 0)
			break;
	        cout << "Unsorted Array: ";
	        print(Array, size);
		
		switch (choice) {
			case 1: 
				bubbleSort(Array, size);
				break;
			case 2:
				selectionSort(Array, size);
				break;
			case 3:
				insertionSort(Array, size);
				break;
			case 4:
				mergeSort(Array, 0, size - 1);
				break;
			case 5:
				quickSort(Array, 0, size - 1);
				break;
		}
	        cout << "Sorted Array: ";
	        print(Array, size);

	 } 
	 
	 delete [] Array;
	 
	return 0;
}
