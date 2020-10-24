#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stack>


bool operand(char c) {
	return !(c == '*' || c == '+' || c == '-' || c == '/');
}

int  hiearachy(char c) {
	if (c == '+' || c == '-')
		return 0;
	if (c == '*' || c == '/')
		return 1;
	return -1;
}



int type(std::string str) {
	if (str[0] == '(') //parenthesis followed by an operand
		return 0; 
	if (str[str.length() - 1] == ')') //operand followed up an parenthesis
		return 1;
	if (operand(str[0])) //vanilla operand
		return 2;
	return 3; //operator

}


std::string toPostFix(std::string infix) { //this function does both characters and integer operands

	std::stack<char> ops; //short for operators
	std::string result = "";
	int curr_hiearachy = -1;
	std::stringstream ss(infix);
	std::string str; //will parse ss variable by spliting between spaces the str could be an operator, operand, or a combination of operand and parenthesis

	while (ss >> str) {

		switch (type(str)) {
			case 0: //meaning open parenthesis followed by an operand 
				while (str[0] == '(')
					ops.push(str[0]), str.erase(0, 1);
				result = result + str + ' ';
				break;
			case 1: //meaning operand followed by closed parenthesis
				result = result + str.substr(0, str.find(")")) + ' ', str.erase(0, str.find(")"));
				while (str.length() != 0) {
					while (ops.top() != '(')
						result = result + ops.top() + ' ', ops.pop();	
					ops.pop(); //pop '('
					curr_hiearachy = ops.empty() ? -1 : hiearachy(ops.top()); //retrieve the previous heiarachy before entering the nested parenthesis (think of 4th test case)
					str.erase(str.find(")") , 1);
				}
				break;
			case 2: //meaning just an operand
				result = result + str + ' ';
				break;
			case 3: //meaning just an operator
				while (!ops.empty() && ops.top() != '(' && curr_hiearachy >= hiearachy(str[0])) {
					result = result + ops.top() + ' ', ops.pop();
					curr_hiearachy = ops.empty() ? -1 : hiearachy(ops.top()); //update 
				}
				ops.push(str[0]); //will always be the top of the stack operator
				curr_hiearachy = hiearachy(str[0]);
		}

	} //end of the string
	
	while (!ops.empty())
		result = result + ops.top() + ' ', ops.pop();

	return result.erase(result.size() - 1, 1); //remove the extra space at the end

}


double evaluatePostFix(std::string expression) {

	std::stack<double> operands;
	std::stringstream ss(expression);
	std::string str; //could be an operand or an operator
	double operand_1, operand_2; //place holders for when we need to eval 

	while (ss >> str) {

		switch(type(str)) {
			case 2: //meaning operand
				if ((str[0] | 32) >= 'a' && (str[0] | 32) <= 'z') //if it's a character then return zero
					return 0.0;
				operands.push(stod(str));
				break;
			case 3: //meaning operator
				operand_1 = operands.top(), operands.pop();
				operand_2 = operands.top(), operands.pop();
				switch(str[0]) {
					case '+':
						operands.push(operand_2 + operand_1);
						break;
					case '-':
						operands.push(operand_2 - operand_1);
						break;
					case '*':
						operands.push(operand_2 * operand_1);
						break;
					case '/':
						operands.push(operand_2 / operand_1);
						break;
				}	

		}
		
	}

	return operands.top(); //at this only one element in the stack which is the result
}

int main(int argc, char **argv) {
	
	std::stringstream ss;

	if (argc == 2) { //custom testing example usage <exe> arg1 where arg1 is a string e.g ./a.out "A + B - C" 
		std::cout << toPostFix(argv[1]) << ": " << evaluatePostFix(toPostFix(argv[1])) << std::endl; 
	}
	else {
		std::cout << toPostFix("A + B - C") << std::endl;
		std::cout << toPostFix("(A + B) * C") << std::endl;
		std::cout << toPostFix("(A + B) * (C - D)") << std::endl;
		std::cout << toPostFix("A + ((B + C) * (E - F) - G) / (H - I)") << std::endl;
		std::cout << toPostFix("A + B * (C + D) - E / F * G + H") << std::endl;
		std::cout << toPostFix("A * (B + C * D) + C") << std::endl;
		std::cout << toPostFix("2 * (3 + 4 - (5 - 6))") << std::endl;
		std::cout << toPostFix("33 * (321 + 17 - (5 - 6))") << std::endl;
	}
	return 0;
}
