//============================================================================
// Name        : recursiveReverseWords.cpp
// Author      : Mahima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "helperWords.h"
using namespace std;

//input.erase(0, input.find(" ") + 1);
string reverseWords(string input) {
	
	std::string result;	
	if (input.find(" ") == std::string::npos) //meaning only one word
		return input;
	std::string word = extractFirstWord(input, " ");
	result = reverseWords(input.substr(input.find(" ") + 1)); //get the first space but ignore it
	return result + " " + word;
}

int main() {
	string s;
	s = reverseWords("A quick brown fox jumps over the lazy dog");
	cout << s << endl; // Expects dog lazy the over jumps fox brown quick A

	s = reverseWords("Tuesday");
	cout << s << endl; // Expects Tuesday

	s = reverseWords("Algorithms and Data Structure Design");
	cout << s << endl; // Expects Design Structure Data and Algorithms
	
	return 0;
}
