#include <iostream>

#include "ArrayList.h"


int main()
{
	ArrayList<int> lst(5);
	std::cout << std::boolalpha;
	std::cout << lst.is_empty() << " " << lst.is_full() << " " << lst.list_size() << " " << lst.max_size() << std::endl;
	lst.print();
	lst.insert(0, 6);
	std::cout << "size: " << lst.list_size() << std::endl;
	lst.insert(1, 9);
	lst.insert(2, 12);
	lst.insert(2, 15);
	lst.insert(2, 18);
	lst.insert(2, 21);
	
	std::cout << "size: " << lst.list_size() << std::endl;
	lst.print();
	return 0;
}
