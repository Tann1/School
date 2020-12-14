
#ifndef SORTING_H_
#define SORTING_H_


void bubbleSort(int* Array, const unsigned int size);
void selectionSort(int* Array, const unsigned int size);
void insertionSort(int* Array, const unsigned int size);
void mergeSort(int* Array, unsigned int low, unsigned int high);
void quickSort(int* Array, unsigned int low, unsigned int high);

//Optional
void shellSort(int* Array, const unsigned int size);

//Own functions
void merge(int* Array, unsigned int low, unsigned int mid, unsigned int high);
unsigned int partition(int* Array, unsigned int low, unsigned int high);

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int* Array, const unsigned int size) {
	bool swaped = true;

	while (swaped) { //keep going as long as swaps are happening
		swaped = false; //reset swap for each iteration
		for (int i = 0; i < size - 1; ++i)
			if (Array[i + 1] < Array[i]) //if swap happens then we loop again
				swap(Array[i + 1], Array[i]), swaped = true;		
	}
}

void selectionSort(int* Array, const unsigned int size) {
	unsigned int min_pos;

	for (int i = 0; i < size; ++i) {
		min_pos = i;
		for (int j = i + 1; j < size; ++j)
			if (Array[j] < Array[min_pos])
				min_pos = j;
		swap(Array[min_pos], Array[i]);
	}
}

void insertionSort(int* Array, const unsigned int size) {
	unsigned int pos;
	int val;

	for (int i = 1; i < size; ++i) {
		pos = i;
		val = Array[i];
		while (pos > 0 && Array[pos] < Array[pos - 1]) 
			swap(Array[pos], Array[pos - 1]), pos--;
	}
}

void mergeSort(int* Array, unsigned int low, unsigned int high) {
	
	if (low >= high)
		return;
	unsigned int mid = (low + high) / 2;
	mergeSort(Array, low, mid);
	mergeSort(Array, mid + 1, high);
	merge(Array, low, mid, high);
}

void merge(int* Array, unsigned int low, unsigned int mid, unsigned int high) {
	
	int* leftArr = new int[mid - low + 1]; //leftArr[low, . . . , mid]
	int* rightArr = new int[high - mid]; //rightArr[mid + 1, . . ., high]

	//populate the two arrays
	for (unsigned int i = 0; i < mid - low + 1; ++i)
		leftArr[i] = Array[low + i];
	for (unsigned int i = 0; i < high - mid; ++i)
		rightArr[i] = Array[mid + 1 + i];

	unsigned int i = 0, j = 0; // leftArr, rightArr indexes respectively
	unsigned int k = low; //keeps track of the bigger array (a.k.a the result array)
	//start comparing elements from both array to put in the bigger array
	while (i < mid - low + 1 && j < high - mid) {
		if (leftArr[i] < rightArr[j])
			Array[k] = leftArr[i++];
		else
			Array[k] = rightArr[j++];
		k++;
	} //end of while

	//pick up any left overs from either array if any at all
	while (i < mid - low + 1)
		Array[k++] = leftArr[i++];
	while (j < high - mid)
		Array[k++] = rightArr[j++];
	
	delete []leftArr;
	delete []rightArr;
}

void quickSort(int* Array, unsigned int low, unsigned int high){
	if (low >= high)
		return;
	unsigned int part = partition(Array, low, high); 
	
	quickSort(Array, low, part - 1);
	quickSort(Array, part + 1, high);

}

unsigned int partition(int* Array, unsigned int low, unsigned int high) {
	int pivot = Array[high]; //let the last element be the pivot
	unsigned int i = low; 
	//put the elements lower than pivot to the left and elements greater than pivot to the right 
	for (int j = low; j < high; ++j) 
		if (Array[j] <= pivot)
			swap(Array[i++], Array[j]);
	//if here means that j == high so swap i with high since that's where pivot belongs
	swap(Array[i], Array[high]);
	return i; //need i to decide next partition 
}


#endif /* SORTING_H_ */
