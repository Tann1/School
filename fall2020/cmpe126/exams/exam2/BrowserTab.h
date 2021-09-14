#ifndef BROWSERTAB_H_
#define BROWSERTAB_H_

#include <string>
#include <stack>
using namespace std;

class BrowserTab {
public:
	BrowserTab();
	void visitPage(string);
	void back();
	void forward();
	string getCurrentPage();
	void printHistory();
	~BrowserTab();
private:
	void check(); //checks for the history arr size is full or not 

	string current_page;
	std::stack<std::string> nextPage;
	std::stack<std::string> prevPage;
	std::string* history;
	unsigned int index, max_size;
	/*****************
	 * Add any fields you need
	 *****************/
};

#endif /* BROWSERTAB_H_ */
