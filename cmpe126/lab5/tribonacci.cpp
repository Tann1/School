#include <iostream>


unsigned int tribonacci(const unsigned int &n) {
	if (n == 0)
		return 0;
	if (n < 3)
		return 1;
	if (n == 3)
		return 2;

	return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}


int main() {

	std::cout << tribonacci(7) << std::endl;	
	return 0;
}
