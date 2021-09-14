#include "Rectangle.h"


int main() 
{
	Rectangle obj1(2,3);
	
	std::cout << "Testing getters" << std::endl;
	std::cout << "len: " << obj1.get_len() << " wid: " << obj1.get_wid() << std::endl;
	
	std::cout << "Testing setters" << std::endl;
	obj1.set_len(4);
	obj1.set_wid(6);
	std::cout << "len: " << obj1.get_len() << " wid: " << obj1.get_wid() << std::endl;
	
	std::cout << "Testing print function and area function simultaneously" << std::endl;
	obj1.print_area();
	return 0;
}
