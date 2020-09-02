#include "length.h"


int main()
{
	Length h1;
	Length h2(3);
	Length h3(5,10);
	int inches = 10;
	
	std::cout << "h1: " << h1 << std::endl;
	std::cout << "h2: " << h2 << " " << "h3: " << h3 << std::endl;
	std::cout << "h2 + h3: " << h2 + h3 << std::endl;
	h1 = h3 + inches;
	std::cout << "h1 = h3 + inches: " << h1 << std::endl;
	return 0;
}
