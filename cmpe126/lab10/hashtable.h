#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>

class HashTable {
	public:
		HashTable(unsigned int = 10);
		~HashTable();
		void print();
		bool insert(int);
		int search(int);

	private:
		unsigned int hash(int);
		unsigned int HTsize, curr_size;
		int* table;
};

HashTable::HashTable(unsigned int HTsize) {
	this->HTsize = HTsize;
	this->curr_size = 0;
	this->table = new int[HTsize];
	for (int i = 0; i < HTsize; ++i)
		this->table[i] = -1; //signifies empty slot
}

HashTable::~HashTable() {
	delete []this->table;
}

unsigned int HashTable::hash(int element) {
	return element % this->HTsize;
}

void HashTable::print() {
	for (int i = 0; i < this->HTsize; ++i)
		if (this->table[i] != -1)
			std::cout << this->table[i] << " ";
}

bool HashTable::insert(int element) {
	unsigned int key = this->hash(element);
	unsigned int probe = 1;
	if (this->HTsize == this->curr_size) //meaning table is full
		return false;
	if (this->table[key] == -1) { //no need to probe just insert the element
		this->table[key] = element;
		this->curr_size++;
		return true;
	} //if here means we need to probe
	while (this->table[(key + probe) % this->HTsize] != -1)
		probe++;
	this->table[(key + probe) % HTsize] = element;
	this->curr_size++;
	return true;	
}

int HashTable::search(int element) {
	unsigned int key = this->hash(element);
	unsigned int probe = 0;
	unsigned int sz = 0;

	while (sz != this->curr_size) {
		if (this->table[(key + probe) % this->HTsize] == element)
			return (key + probe) % this->HTsize;
		probe++, sz++;
	}	
	return -1; //meaning we didn't find it 
}
#endif 
