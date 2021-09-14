#ifndef SORTEDARRAYLIST_H
#define SORTEDARRAYLIST_H
#include <iostream>

template <class elemType>
class SortedArrayList {

	public:
		SortedArrayList(unsigned int = 1);
		~SortedArrayList();

		bool isEmpty() const;
		bool isFull() const;
		unsigned int listSize() const;
		unsigned int maxListSize() const;
		void print();
		bool insert(elemType);
		void remove(elemType);
		void clearList();
		unsigned int binarySearchIter(elemType);
		unsigned int binarySearchRec(elemType);
	private:
		unsigned int binary(elemType, unsigned int, unsigned int);
		elemType* arr;
		unsigned int size;
		unsigned int max_size;
};

template <class elemType>
SortedArrayList<elemType>::SortedArrayList(unsigned int max_size) {
	this->size = 0;
	this->max_size = max_size;
	this->arr = new elemType[max_size];
}

template <class elemType>
SortedArrayList<elemType>::~SortedArrayList() {
	delete []this->arr;
}

template <class elemType>
bool SortedArrayList<elemType>::isEmpty() const {
	return size == 0;
}

template <class elemType>
bool SortedArrayList<elemType>::isFull() const {
	return this->size == this->max_size;
}

template <class elemType>
unsigned int SortedArrayList<elemType>::listSize() const {
	return this->size;
}

template <class elemType>
unsigned int SortedArrayList<elemType>::maxListSize() const {
	return this->max_size;
}

template <class elemType>
void SortedArrayList<elemType>::print() {
	for (int i = 0; i < this->size; ++i) {
		std::cout << arr[i];
		if (i < this->size -1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

template <class elemType> 
bool SortedArrayList<elemType>::insert(elemType element) {
	unsigned insert_pos = 0; 
	if (this->isFull())
		return false;
	if (this->isEmpty()) {
		this->arr[this->size++] = element;
		 return true;
	}
	while (this->arr[insert_pos] < element && insert_pos < this->size)
		insert_pos++;
	this->size++;
	if (insert_pos == this->size - 1) { //meaning last element no need to shift
		this->arr[insert_pos] = element;
		return true;
	}
	for (int i = this->size - 1; i > insert_pos; --i)
		this->arr[i] = this->arr[i - 1];
	this->arr[insert_pos] = element;
	return true;
}

template <class elemType>
void SortedArrayList<elemType>::remove(elemType element) {
	unsigned int temp; 

	if (this->isEmpty())
		return;
	temp = --this-size;
	if (this->arr[temp] == element) //meaning the last element, therefore, no need to shift
		return;
	
	for (int i = temp; i >= 0; --i) {
		if (this->arr[i] == element) {
			temp = i; 
			break; 
		}
	}
	if (temp == -1) //meaning element does not exist
		return;
	for (int i = temp; i < this->size; ++i) //doing the shift 
		arr[i] = arr[i + 1]; 
}

template <class elemType>
void SortedArrayList<elemType>::clearList() {
	this->size = 0;
}

template <class elemType>
unsigned int SortedArrayList<elemType>::binarySearchIter(elemType element) {
	unsigned int low = 0, high = this->size - 1, mid;
	
	while (low <= high) {
		mid = (high + low) / 2;
		if (this->arr[mid] == element)
			return mid;
		if (this->arr[mid] < element) //ignore the lower half
			low = mid + 1;
		else
			high = mid - 1; //ignore the upper half
	}
	return -1;
}


template <class elemType>
unsigned int SortedArrayList<elemType>::binarySearchRec(elemType element) {
	return binary(element, 0, this->size - 1);
}

template <class elemType>
unsigned int SortedArrayList<elemType>::binary(elemType element, unsigned int back, unsigned int front) {
	
	if (back > front)
		throw "invalid bounds for binary search method (recursively)";

	unsigned int mid = (back + front)/2;

	if (this->arr[mid] == element)
		return mid;
	if (this->arr[mid] > element) // it's in the left lower half
		return binary(element, 0, mid - 1);
	if (this->arr[mid] < element)
		return binary(element, mid + 1, front); //its in the right upper half
	throw "element not in the list";
}
#endif
