#ifndef BROWSER_H_
#define BROWSER_H_
#include "BrowserTab.h"

class Browser {
public:
	Browser();
	void switchToTab(unsigned int); 	// Switch to tab with index specified
	// ^ Needs to check if the index is valid
	void openTab(BrowserTab); 			// Open a new tab
	void closeCurrentTab();				// Closes the current tab
	unsigned int getCurrentTabIndex();  // Returns the index of the current tab
	unsigned int getNumTabs();			// Returns the number of open tabs
	BrowserTab* getCurrentTab();			// Returns the current BrowserTab object
	~Browser();
private:
	BrowserTab tabs[32]; //Temporarily created a static array of maximum of 32 tabs
	unsigned int current_tab_index; // Index of the current tab
	unsigned int num_tabs; // Number of open tabs
};

#endif /* BROWSER_H_ */
