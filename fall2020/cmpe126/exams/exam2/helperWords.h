#ifndef HELPERWORDS_H_
#define HELPERWORDS_H_

#include <string>
using namespace std;

string extractFirstWord(string s, string delim){
	unsigned int pos = s.find(delim);
	if(pos == string::npos)
			return s;
	else
		return s.substr(0, pos);
}

#endif /* HELPERWORDS_H_ */