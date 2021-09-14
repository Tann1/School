#include "arrayQueue.h"
#include <stack>



template <typename elemType>
class stackQueue{ 
	public:
		stackQueue();
		stackQueue(unsigned int);
		void enqueue(elemType);
		elemType dequeue();
		elemType front();
		unsigned int size();
		unsigned int maxSize();
		bool isEmpty();
		bool isFull();

	private:
		std::stack<elemType> primary, secondary;
		unsigned int m_size;
};

template <typename elemType>
stackQueue<elemType>::stackQueue() {
	this->m_size = 500; //developer's decision
}

template <typename elemType>
stackQueue<elemType>::stackQueue(unsigned int m_size) {
	this->m_size = m_size;
}

template <typename elemType>
void stackQueue<elemType>::enqueue(elemType item) {
	if (this->isFull())
		throw "Queue is full, cannot enqueue";
	this->primary.push(item);
}

template <typename elemType>
elemType stackQueue<elemType>::dequeue() {
	elemType temp;

	if (this->isEmpty())
		throw "Queue is empty, cannot dequeue";
	while (this->primary.size() != 1) 
		this->secondary.push(this->primary.top()), this->primary.pop();
	temp = this->primary.top(), this->primary.pop();
	while (!this->secondary.empty())
		this->primary.push(secondary.top()), secondary.pop();
	return temp;
}

template <typename elemType>
elemType stackQueue<elemType>::front() {
	elemType temp;

	if (this->isEmpty())
		throw "Queue is empty, cannot retrieve front";
	while (this->primary.size() != 1)
		this->secondary.push(this->primary.top()), this->primary.pop();
	temp = this->primary.top(); //important not to pop the element unlike dequeue where you would pop this element
	while (!this->secondary.empty())
		this->primary.push(secondary.top()), secondary.pop();
	return temp;
}

template <typename elemType>
unsigned int stackQueue<elemType>::size() {
	return this.primary.size();
}

template <typename elemType>
unsigned int stackQueue<elemType>::maxSize() {
	return this->m_size;
}

template <typename elemType>
bool stackQueue<elemType>::isEmpty() {
	return this->primary.empty();
}

template <typename elemType>
bool stackQueue<elemType>::isFull() {
	return this->primary.size() == this->m_size;
}
