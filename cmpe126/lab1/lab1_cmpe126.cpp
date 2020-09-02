#include "member.h"


int main()
{
	Length h1;
	Length h2(3);
	Length h3(5,10);
	int inches = 10;
	
	std::cout << "TASK 1" << std::endl;	
	std::cout << "h1: " << h1 << std::endl;
	std::cout << "h2: " << h2 << " " << "h3: " << h3 << std::endl;
	std::cout << "h2 + h3: " << h2 + h3 << std::endl;
	h1 = h3 + inches;
	std::cout << "h1 = h3 + inches: " << h1 << std::endl;
	
	std::cout << std::endl;
	std::cout << "TASK 2" << std::endl;
	int memberID = 1000;
	Member m1(memberID);
	m1.set_height(5, 7);
	m1.set_weight(150);
	std::cout << "printing m1 after initalizing values" << std::endl;
	std::cout << m1 << std::endl;
	Length h(6,2);
	m1.set_height(h); //fucking trollingggg
	std::cout << "printing m1 after changing height" << std::endl;
	std::cout << m1 << std::endl;
	return 0;
}
