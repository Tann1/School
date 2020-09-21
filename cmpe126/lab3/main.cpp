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
	
	ArrayList<int> lst2(6);
	std::cout << "lst2 (size, max size): " << lst2.list_size() << " " << lst2.max_size() << std::endl;
	lst2 = lst;
	std::cout << "print lst2 after lst2 = lst" << std::endl;
	std::cout << "lst2 (size, max size): " << lst2.list_size() << " " << lst2.max_size() << std::endl;
	lst2.print();
	lst2.remove(0);
	std::cout << "lst2 after removing element 0" << std::endl;
	lst2.print();
	lst2.insert_end(8);
	std::cout << "after inserting at end" << std::endl;
	lst2.print();
	std::cout << "replacing 2nd element" << std::endl;
	lst2.replace(1, 3);
	lst2.print();
	std::cout << "clearing lst2" << std::endl;
	lst2.clear_list();
	lst2.print();
	return 0;
}
