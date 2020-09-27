#include <iostream>
#include "complexNumber.h"


int main() {

	Complex<int> cmplx(3, 2);
	Complex<int> cmplx2(1, 4);
	
	std::cout << cmplx * cmplx2 << std::endl;
	return 0;
}
