#include <iostream>
#include <stack>


bool operand(char c) {
	return !(c == '*' || c == '+' || c == '-' || c == '/');
}

int  hiearachy(char c) {
	if (c == '-' || c == '+')
		return 0;
	if (c == '*')
		return 1;
	if (c == '/') 
		return 2;
	return -1;
}

std::string toPostFix(std::string infix) {

	std::stack<char> ops; //short for operators
	std::string result = "";
	int curr_hiearachy = -1;

	for (char ch : infix) {	
		if (ch == ' ')
			continue;
		if (ch == '(') 
			ops.push(ch); 
		else if (ch == ')') {
			while (ops.top() != '(') 
				result = result + ops.top() + ' ', ops.pop();
			ops.pop(); //one more time for the '('
			curr_hiearachy = ops.empty() ? -1 : hiearachy(ops.top()); //recover previous hiearachy that was lost after entering the nested parentehsis 
		}
		else if (operand(ch)) { //checking for operand 
			result = result + ch + ' ';
		}
		else { //push the operator on the stack
			while (!ops.empty() && ops.top() != '(' && curr_hiearachy > hiearachy(ch)) {
				result = result + ops.top() + ' ', ops.pop();
				curr_hiearachy = ops.empty() ? -1 : hiearachy(ops.top()); //update the current hiearachy 
			}
			ops.push(ch);
			curr_hiearachy = hiearachy(ch);
		}
	
	} //end of the string

	while (!ops.empty())
		result = result + ops.top() + ' ', ops.pop();

	return result;

}

int main() {

	std::cout << toPostFix("A + B - C") << std::endl;
	std::cout << toPostFix("(A + B) * C") << std::endl;
	std::cout << toPostFix("(A + B) * (C - D)") << std::endl;
	std::cout << toPostFix("A + ((B+C) * (E-F) - G) / (H - I)") << std::endl;
	std::cout << toPostFix("A + B * (C + D) - E / F * G + H") << std::endl;
	return 0;
}
