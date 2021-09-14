#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "linkedListList.h"
class HashTableChaining {
	public:
		HashTableChaining(unsigned int = 10);
		~HashTableChaining();
		void print();
		bool insert(int);
		int search(int);

	private:
		unsigned int hash(int);
		unsigned int HTsize, curr_size;
		LinkedListList<int>* table;
};

HashTableChaining::HashTableChaining(unsigned int HTsize) {
	this->HTsize = HTsize;
	this->curr_size = 0;
	this->table = new LinkedListList<int>[HTsize];
}

HashTableChaining::~HashTableChaining() {
	delete []this->table;
}

unsigned int HashTableChaining::hash(int element) {
	return element % this->HTsize;
}

void HashTableChaining::print() {
	for (int i = 0; i < this->HTsize; ++i) {
		if (!this->table[i].isEmpty()) {
			std::cout << "table[" << i << "]: ";
			table[i].print();
		}
	}
}


bool HashTableChaining::insert(int element) {
	unsigned int key = this->hash(element);
	
	if (this->table[key].isFull())
		return false;
	this->table[key].insertEnd(element);
	return true;
}

int HashTableChaining::search(int element) {
	unsigned int key = this->hash(element);

	return (key = this->table[key].seqSearchRec(element) ? key : -1);
}
#endif
