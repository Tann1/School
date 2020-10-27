
template <typename elemType>
class arrayQueue {

	public:
		arrayQueue();
		arrayQueue(unsigned int);
		~arrayQueue();
		void enqueue(elemType);
		elemType dequeue();
		elemType front();
		unsigned int size();
		unsigned int maxSize();
		bool isEmpty();
		bool isFull();

	private:
		unsigned int tail, c_front, c_size, m_size;
		elemType* arr;	
	
};

template <typename elemType>
arrayQueue<elemType>::arrayQueue() {
	this->tail = 0;
	this->c_front = 0;
	this->c_size = 0;
	this->m_size = 500; //developers decision
	this->arr = new elemType[this->m_size];
}

template <typename elemType>
arrayQueue<elemType>::arrayQueue(unsigned int m_size) {
	this->tail = 0;
	this->c_front = 0;
	this->c_size = 0;
	this->m_size = m_size;
	this->arr = new elemType[this->m_size];
}

template <typename elemType>
arrayQueue<elemType>::~arrayQueue() {
	delete []this->arr;
}

template <typename elemType>
void arrayQueue<elemType>::enqueue(elemType item) {

	if (this->isFull())
		throw "Queue is full, cannot enqueue";
	this->arr[this->tail++ % this->m_size] = item, this->c_size++;

}

template <typename elemType>
elemType arrayQueue<elemType>::dequeue() {
	
	if (this->isEmpty())
		throw "Queue is empty, cannot dequeue";
	this->c_size--;
	return this->arr[this->c_front++ % this->m_size];
}


template <typename elemType>
elemType arrayQueue<elemType>::front() {
	if (this->isEmpty())
		throw "Queue is empty, cannot retrieve front";
	return this->arr[this->c_front % this->m_size];
}


template <typename elemType>
unsigned int arrayQueue<elemType>::size() {
	return this->c_size;
}

template <typename elemType>
unsigned int arrayQueue<elemType>::maxSize() {
	return this->m_size;
}

template <typename elemType>
bool arrayQueue<elemType>::isEmpty() {
	return this->c_size == 0;
}

template <typename elemType>
bool arrayQueue<elemType>::isFull() {
	return this->c_size == this->m_size;
}
