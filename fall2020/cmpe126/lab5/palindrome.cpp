#include <iostream>



bool check_palindrome(const std::string &s) {
	std::string temp = s;
	if (s.length() <= 1)
		return true;

	if (s[0] != s[s.length() - 1])
		return false;
	temp.erase(0, 1);
	temp.erase(temp.length() - 1, 1);
	return	check_palindrome(temp);
}




int main() {
	std::cout << std::boolalpha;
	std::cout << check_palindrome("racecar") << std::endl;
	return 0;
}
