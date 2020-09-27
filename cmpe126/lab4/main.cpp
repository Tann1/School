#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SortedLinkedList.h"




int main()
{
	SortedList<int> lst;
	SortedList<int> lst2(10);
	srand(time(NULL));
	std::cout << std::boolalpha;
	
	std::cout << "Testing insert" << std::endl;
	for (int i = 0; i < 20; i++)
		lst.insert(rand() % 20 + 1); // random # from 1 to 20
	std::cout << "list size: " << lst.listSize() << std::endl;
	std::cout << "list max size; " << lst.maxListSize() << std::endl;
	lst.print();
	std::cout << std::endl;

	std::cout << "Testing remove" << std::endl;
	lst.insert(1);
	std::cout << "before removing 1" << std::endl;
	lst.print();
	lst.remove(1);
	std::cout << "after removing 1" << std::endl;
	lst.print();

	lst.insert(5);
	std::cout << "before removing 5" << std::endl;
	lst.print();
	lst.remove(5);
	std::cout << "after removing 5" << std::endl;
	lst.print();


	lst.insert(20);
	std::cout << "before removing 20" << std::endl;
	lst.print();
	lst.remove(20);
	std::cout << "after removing 20" << std::endl;
	lst.print();

	std::cout << std::endl;
	std::cout << "testing for if an item is in list" << std::endl;
	std::cout << "The list: "; lst.print();

	for (int i = 0, temp; i < 5; i++) {
		temp = rand() % 20 + 1;
		std::cout << temp << " in list: " << lst.isItemInList(temp) << std::endl;
	} 
	
	std::cout << std::endl;
	std::cout << "testing retrieving an item from the list" << std::endl;
	std::cout << "The list: "; lst.print();

	for (int i = 0, temp; i < 5; ++i) {
		temp = rand() % 20;
		std::cout << "lst[" << temp << "] = " << lst.retrieveAt(temp) << std::endl;
	}

	std::cout << std::endl;
	std::cout << "checking for assignment (=) operator" << std::endl;
	std::cout << "lst2 before assigning lst to lst2" << std::endl;
	std::cout << "lst2: "; lst2.print();
	lst2 = lst;
	std::cout << "lst2 after assinging lst tot lst2" << std::endl;
	std::cout << "lst2: "; lst2.print();
	
	std::cout << std::endl;
	std::cout << "testing for clearing the list" << std::endl;
	std::cout << "lst2 before clearing list: "; lst2.print();
	lst2.clearList();
	std::cout << "lst2 after clearing list: "; lst2.print();
	return 0;	

}
