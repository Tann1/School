#ifndef HASHTABLEQUAD_H
#define HASHTABLEQUAD_H
#include <iostream>

class HashTableQuad {
	public:
		HashTableQuad(unsigned int = 10);
		~HashTableQuad();
		void print();
		bool insert(int);
		int search(int);

	private:
		unsigned int hash(int);
		unsigned int HTsize, curr_size;
		int* table;	
};

HashTableQuad::HashTableQuad(unsigned int HTsize) {
	this->HTsize = HTsize;
	this->curr_size = 0;
	this->table = new int[HTsize];
	for (int i = 0; i < HTsize; ++i)
		this->table[i] = -1; //signifies empty spots
}

HashTableQuad::~HashTableQuad() {
	delete []this->table;
}

unsigned int HashTableQuad::hash(int element) {
	return element % this->HTsize;
}

void HashTableQuad::print() {
	for (int i = 0; i < this->HTsize; ++i)
		if (this->table[i] != -1)
			std::cout << this->table[i] << " ";
}

bool HashTableQuad::insert(int element) {
	unsigned int key = this->hash(element);
	unsigned int probe = 0;
	
	if (this->HTsize == this->curr_size) //meaning its full
		return false;
	while (this->table[(key + (probe * probe)) % this->HTsize] != -1) //bit more optimized than linear probing code
		probe++;
	this->table[(key + (probe * probe)) % this->HTsize] = element;
	this->curr_size++;
	return true;
}

int HashTableQuad::search(int element) {
	unsigned int key = this->hash(element);
	unsigned int probe = 0;
	unsigned int sz = 0;
	
	while (sz != this->curr_size) {
		if (this->table[(key + (probe * probe)) % this->HTsize] == element)
			return (key + (probe * probe)) % this->HTsize;
		probe++, sz++;
	}
}

#endif
