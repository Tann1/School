#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

template <class elemType>
struct Node {
	elemType data;
	Node* next;
	Node(elemType d) : data(d), next(nullptr) {} //construtor
	
};

template <class elemType>
class SortedList {
	public:
		SortedList();
		SortedList(unsigned int);
		~SortedList();
		
		bool isEmpty() const;
		bool isFull() const;
		unsigned int listSize() const;
		unsigned int maxListSize() const;
		void print();
		void insert(elemType);
		void remove(elemType);
		bool isItemInList(elemType);
		elemType retriveAt(int);
		void clearList();
		void operator=(const SortedList&);
	private:
		Node<elemType>* head;
		unsigned int currSize;
		unsigned int maxSize;
};

template <class elemType>
SortedList<elemType>::SortedList()
{
	std::cout << "initializing list . . ." << std::endl;
	this->head = nullptr;
	this->currSize = 0;
	this->maxSize = ~0; //complement of all 0s of size 32-bits
}

template <class elemType>
SortedList<elemType>::SortedList(unsigned int maxSize) : SortedList()
{
	this->maxSize = maxSize;
}

template <class elemType>
SortedList<elemType>::~SortedList()
{
	this->clearList();
}

template <class elemType>
bool SortedList<elemType>::isEmpty() const
{
	return this->head == nullptr;
}

template <class elemType>
bool SortedList<elemType>::isFull() const
{
	return this->currSize == this->maxSize;
}

template <class elemType>
unsigned int SortedList<elemType>::listSize() const
{
	return this->currSize;
}

template <class elemType>
unsigned int SortedList<elemType>::maxListSize() const
{
	return this->maxSize;
}

template <class elemType>
void SortedList<elemType>::print()
{
	Node<elemType>* temp = head;
	
	if(this->isEmpty())
		return;
	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <class elemType>
void SortedList<elemType>::clearList()
{
	Node<elemType>* temp = head;

	while (head != nullptr)
	{	
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <class elemType>
void SortedList<elemType>::insert(elemType item)
{
	Node<elemType>* temp = head;
	Node<elemType>* temp_2 = nullptr; //for the new node with the value of item
	if (this->isFull())
		return;
	if (this->isEmpty())
		this->head = new Node<elemType>(item), this->currSize++;
	else if (temp->data >= item) { //special case of updating the head
		this->head = new Node<elemType>(item);
		this->head->next = temp;
		this->currSize++;
	} //if we're in the else statement then we have 2 nodes 
	else {
		while (temp->next != nullptr && temp->next->data <= item) 
			temp = temp->next;

		if (temp->next == nullptr) //meaning insert the item at last.next
			temp->next = new Node<elemType>(item);
		else { //somewhere in the middle
			temp_2 = new Node<elemType>(item);
			temp_2->next = temp->next;
			temp->next = temp_2;
		}
		this->currSize++;		
	}

}

template <class elemType>
void SortedList<elemType>::remove(elemType item)
{
	Node<elemType>* temp = this->head;
	Node<elemType>* temp_2 = nullptr; //node to be deleted
	
	if (this->isEmpty())
		return;
	if (temp->data == item) //if it's the head that needs updating
	{
		head = head->next;
		delete temp;
		this->currSize--;
	}	
	else {
		while (temp->next != nullptr && temp->next->data != item)
			temp = temp->next;
		if (temp->next->data == item) { // meaning we found item in the list without exhausting it
			temp_2 = temp->next;
			temp->next = temp->next->next;
			delete temp_2;
			this->currSize--;
		}
	}
}
#endif
