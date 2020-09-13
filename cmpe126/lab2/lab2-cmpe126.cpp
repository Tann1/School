#include <iostream>
#include "triple.h"

int main() 
{
	Triple<int> triple_int(4,3,3);
	std::cout << "Triple int: ";
	triple_int.print();
	std::cout << std::endl;

	std::cout << "Max element is " << triple_int.get_max() << std::endl;
	std::cout << "Min element is " << triple_int.get_min() << std::endl;
	std::cout << "Number of unique elements is " << triple_int.num_unique() << std::endl;

	if (triple_int.contains(4))
		std::cout << "Found 4" << std::endl;
	else
		std::cout << "Did not find 4" << std::endl;
	

	Triple<std::string> triple_string("cmpe", "sjsu", "algos");
	std::cout << "Triple string: ";
	triple_string.print();
	std::cout << std::endl;

	std::cout << "Max element is " << triple_string.get_max() << std::endl;
	std::cout << "Min element is " << triple_string.get_min() << std::endl;
	std::cout << "Number of unique elements is " << triple_string.num_unique() << std::endl;

	if (triple_string.contains("sjsu"))
		std::cout << "Found sjsu" << std::endl;
	else
		std::cout << "Did not find sjsu" << std::endl;

	std::cout << std::endl;

	//testing setters
	triple_string.set_first("first");
	triple_string.set_second("second");
	triple_string.set_third("third");
	
	//testing getters
	std::cout << "Testing getters after using setters" << std::endl;
	std::cout << triple_string.get_first() << std::endl;
	std::cout << triple_string.get_second() << std::endl;
	std::cout << triple_string.get_third() << std::endl;
	
	std::cout << std::endl;
	
	//testing for one unique element
	triple_string.set_first("first");
	triple_string.set_second("first");
	triple_string.set_third("first");
	triple_string.print();
	std::cout << "printing unique element(s) after setting the 3 elements all to first: ";
	std::cout << triple_string.num_unique() << std::endl;

	std::cout << "End Of Testing" << std::endl;
	
	return 0;
}
