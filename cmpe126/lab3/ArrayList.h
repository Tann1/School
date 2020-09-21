#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class elemType>
class ArrayList 
{
	public:
		ArrayList(const int);
		~ArrayList();

		bool is_empty() const;
		bool is_full() const;
		int list_size() const;
		int max_size() const;
		void print();
		bool is_equal(int, elemType);
		void insert(int, elemType);
		void insert_end(elemType);
		void remove(int);
		elemType retrive_at(int);
		void replace(int, elemType);
		void clear_list();

		void operator=(const ArrayList&);
	private:
		elemType* arr;
		int max;
		int curr_size;
};



template <class elemType>
ArrayList<elemType>::ArrayList(const int MAX)
{
	std::cout << "allocating array . . ." << std::endl;
	this->max= MAX;
	this->arr = new elemType[MAX];
	this->curr_size = 0;
}

template <class elemType>
ArrayList<elemType>::~ArrayList()
{
	std::cout << "deallocating array . . ." << std::endl;
	delete [] this->arr;
}

template <class elemType>
bool ArrayList<elemType>::is_empty() const
{
	return this->curr_size == 0; 
}

template <class elemType>
bool ArrayList<elemType>::is_full() const
{
	return this->curr_size == max;
}

template <class elemType>
int ArrayList<elemType>::list_size() const
{
	return this->curr_size;
}

template <class elemType>
int ArrayList<elemType>::max_size() const
{
	return this->max;
}

template <class elemType>
void ArrayList<elemType>::print() 
{
	if (is_empty()) {
		std::cout << "empty list, nothing to print." << std::endl;
		return;
	}
	for (int i = 0; i < this->curr_size; ++i)
		std::cout << this->arr[i] << " ";
	std::cout << std::endl;
}

template <class elemType>
bool ArrayList<elemType>::is_equal(int pos, elemType item)
{
	if (pos < this->curr_size)
		return this->arr[pos] == item;
	return false;
}

template <class elemType>
void ArrayList<elemType>::insert(int pos, elemType item)
{
	char input;
	if (pos > this->curr_size) {
		std::cout << "pos is greater than current size, can't insert given element." << std::endl;
		return;
	}
	if (is_full()) {
		std::cout << "list full, overwrite current element (y/n): ";
		std::cin >> input;
		if ((input | 32) == 'y') //bitwise or to turn on the 5th bit in order to make input lowercase y
			this->arr[pos] = item;
		return;
	}
	if (is_empty() || pos == this->curr_size) 
		this->arr[this->curr_size++] = item;
	else {
		for(int i = this->curr_size++; i > pos; --i)
			this->arr[i] = this->arr[i - 1];
		this->arr[pos] = item;
	}

}

template <class elemType>
void ArrayList<elemType>::insert_end(elemType item)
{
	if (!this->is_full())
		this->arr[curr_size++] = item;
	else
		std::cout << "list full, can't insert element at the end" << std::endl;
}

template <class elemType>
void ArrayList<elemType>::remove(int pos) 
{
	if (pos < this->curr_size)
		this->curr_size--;
	for (int i = pos; i < curr_size; ++i)
		this->arr[i] = this->arr[i + 1];
}

template <class elemType>
elemType ArrayList<elemType>::retrive_at(int pos)
{
	if (pos >= this->curr_size) {
		std::cout << "index out of position" << std::endl;
		return NULL;
	}
	return this->arr[pos];

}

template <class elemType>
void ArrayList<elemType>::replace(int pos, elemType item)
{
	if (pos < this->curr_size)
		this->arr[pos] = item;
}

template <class elemType>
void ArrayList<elemType>::clear_list() {
	this->curr_size = 0;
}

template <class elemType>
void ArrayList<elemType>::operator=(const ArrayList& other)
{
	delete [] this->arr;
	this->curr_size = other.curr_size;
	this->max = other.max;
	
	this->arr = new elemType[this->max];
	for (int i = 0; i < this->curr_size; ++i)
		this->arr[i] = other.arr[i];
}

#endif




