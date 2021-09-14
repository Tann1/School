#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H


template <class elemType>
class ArrayStack {

	public:
		ArrayStack();
		ArrayStack(unsigned int);
		~ArrayStack();


		bool push(elemType);
		bool empty();
		elemType pop();
		elemType top();
		unsigned int size();
		unsigned int maxSize();
	private:
		elemType* arr;
		unsigned int max;
		unsigned int curr_top;

};


template <class elemType>
ArrayStack<elemType>::ArrayStack() {
	this->max = 500; //design decision
	this->curr_top = 0; //design decision
	this->arr = new elemType[max];
}


template <class elemType>
ArrayStack<elemType>::ArrayStack(unsigned int size) {
	this->max = size;
	this->curr_top = 0;
	this->arr = new elemType[max];
}

template <class elemType>
ArrayStack<elemType>::~ArrayStack() {
	delete []this->arr;
}


template <class elemType>
bool ArrayStack<elemType>::push(elemType item) {
	if (this->curr_top == this->max) //meaning stack is full
		return false;
	this->arr[this->curr_top++] = item; //meaning we inserted successfully
	return true;
}

template <class elemType>
bool ArrayStack<elemType>::empty() {
	return this->curr_top == 0;
}

template <class elemType>
elemType ArrayStack<elemType>::pop() {
	if (!empty()) //pop if it's not empty
		return this->arr[--this->curr_top];
}

template <class elemType>
elemType ArrayStack<elemType>::top() {
	if (!empty()) //peek top if it's not empty
		return this->arr[this->curr_top - 1];

}

template <class elemType>
unsigned int ArrayStack<elemType>::size() {
	return this->curr_top;
}


template <class elemType>
unsigned int ArrayStack<elemType>::maxSize() {
	return this->max;
}
#endif
