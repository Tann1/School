
#ifndef HELPER_H_
#define HELPER_H_

#include <iostream>
#include <stdlib.h>
using namespace std;

void fillRandom(int *Array, const unsigned int size){
	for(unsigned int i = 0; i < size; i++){
		Array[i] = rand() % 100 + 1;
	}
}

void print(int *Array, const unsigned int size){
	for(unsigned int i = 0; i < size; i++){
		cout << Array[i] << " ";
	}
	cout << endl;
}

#endif /* HELPER_H_ */
