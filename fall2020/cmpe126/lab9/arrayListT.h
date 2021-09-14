/*
 * ArrayListT.h
 *
 *  Created on: Sep 11, 2018
 *      Author: Mahima
 */

#ifndef ARRAYLISTT_H_
#define ARRAYLISTT_H_

#include <iostream>
using namespace std;

template <class elemType>
class ArrayList{
public:
	ArrayList(const unsigned int=1);
	bool isEmpty() const; 				//Checks if list is empty
	bool isFull() const; 				// Checks if list is full
	unsigned int listSize() const; 		// Returns the size of the list
	unsigned int maxListSize() const;	// Returns the maximum possible size of the list
	void print() const; 						// Prints the elements of the list on the console
	bool isItemAtEqual(const unsigned int, const elemType &) const;	// Checks if the item at position matches the 2nd parameter
	void insertAt(const unsigned int, const elemType &);		// Inserts 2nd parameter at position
	void insertEnd(const elemType&); 			// Inserts object to end of the list
	void removeAt(const unsigned int); 				// Removes object at position
	elemType retreiveAt(const unsigned int) const; 			// Retrieves object at position
	void replaceAt(const unsigned int, const elemType &); 		// Replaces object at position with 2nd parameter
	void clearList(); 					// Empties the list
	unsigned int seqSearchIter(elemType);
	unsigned int seqSearchRec(elemType);
	ArrayList &operator=(const ArrayList &);
	virtual ~ArrayList();

private:
	unsigned int size;
	unsigned int maxSize;
	unsigned int rec_pos;
	elemType* myList;
};

template<class elemType>
ArrayList<elemType>::ArrayList(const unsigned int maxSize) {
	this->maxSize = maxSize;
	this->size = 0;
	this->rec_pos = 0;
	this->myList = new elemType[maxSize];
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isEmpty() const {
	if(size == 0)
		return true;
	return false;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isFull() const {
	if(size == maxSize)
		return true;
	return false;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::listSize() const {
	return size;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::maxListSize() const {
	return maxSize;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::print() const {
	for(unsigned int i = 0; i < size; i++){
		cout << myList[i];
		if (i < size - 1)
			std::cout << ", ";
	}
	cout << endl;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isItemAtEqual(const unsigned int position, const elemType &element) const {
	if(position > size){
		throw "Out of bounds.";
	}
	if(element == myList[position-1])
		return true;
	return false;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::insertAt(const unsigned int position, const elemType &element) {
	if (this->isFull()){
		throw "List if full";
	}
	if(position > size+1){
		throw "Inserting out of bounds.";
	}
	for(unsigned int i = size; i > position-1; i--){
		myList[i] = myList[i-1];
	}
	myList[position-1] = element;
	size++;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::insertEnd(const elemType &element) {
	if (this->isFull()){
		throw "List if full";
	}
	myList[size] = element;
	size++;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::removeAt(const unsigned int position) {
	if(position > size){
		throw "Removing out of bounds.";
	}
	for(unsigned int i = position-1; i < size-1; i++){
		myList[i] = myList[i+1];
	}
	size--;
}

//This function is O(1)
template<class elemType>
elemType ArrayList<elemType>::retreiveAt(const unsigned int position) const{
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	return myList[position-1];
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::replaceAt(const unsigned int position, const elemType &element) {
	if(position > size){
		throw "Retrieving out of bounds.";
	}
	myList[position-1] = element;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::clearList() {
	size = 0;
}

template<class elemType>
unsigned int ArrayList<elemType>::seqSearchIter(elemType element) {
	
	for (unsigned int pos = 0; pos < size; ++pos)
		if (myList[pos] == element)
			return pos;
	throw "element not found";	
}

template<class elemType>
unsigned int ArrayList<elemType>::seqSearchRec(elemType element) {
	unsigned temp;

	if (rec_pos == size) 
		rec_pos = 0, throw "element not found";
	if (myList[rec_pos] == element) {
		temp = rec_pos, rec_pos = 0;
		return temp;
	}
	rec_pos++;
	return seqSearchRec(element);	
}


//This function is O(n)
template<class elemType>
ArrayList<elemType>& ArrayList<elemType>::operator =(const ArrayList<elemType>& constArrayList) {
	if (constArrayList.maxListSize() > maxSize){
		throw "Array too big to copy";
	}
	for(unsigned int i = 0; i < constArrayList.listSize(); i++){
		myList[i] = constArrayList.retreiveAt(i+1);
	}
	size = constArrayList.listSize();
	return *this;
}


//This function is O(1)
template<class elemType>
inline ArrayList<elemType>::~ArrayList() {
	delete[] myList;
}

#endif /* ARRAYLISTT_H_ */
