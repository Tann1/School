#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
#include "complexNumber.h"


int main() {

	char op; //operator
	std::string line;
	unsigned int num = 0, i = 0;
	Complex<int> cmplx[2];
	std::stringstream ss;
	std::ifstream inputFile("complexInput.txt");
	std::ofstream outputFile("complexOutput.txt");
	
	if (inputFile.is_open()) {
		while (std::getline(inputFile, line)) {
			ss << line;
			if (num % 2 == 0 && std::regex_match(line, std::regex("\\d+\\s*(\\+|-)\\s*\\d+\\s*i\\r*")))
				ss >> cmplx[i++]; 
			else if (num % 2 == 1)
				ss >> op;
			else {
				std::cout << "invalid complex number" << std::endl;
				return 0;
			}
			ss.str(""); //emptying the buffer for the next input
			num++;
		}
		inputFile.close();
	} 
	else
		std::cout << "file did not open" << std::endl; 
	
	switch (op) {
		case '+':
			cmplx[0] = cmplx[0] + cmplx[1];
			break;
		case '-':
			cmplx[0] = cmplx[0] - cmplx[1];
			break;
		case '*':
			cmplx[0] = cmplx[0] * cmplx[1];
	}
	
	//put it into the output file
	if (outputFile.is_open()) {
		outputFile << cmplx[0] << std::endl;
		outputFile.close();
	} 
	else
		std::cout << "output file did not open" << std::endl;
	return 0;
}
