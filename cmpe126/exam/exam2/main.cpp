#include <iostream>
#include <string>
#include "BrowserTab.h"

// #include "Browser.h" // UNCOMMENT TO TEST BROWSER CODE
using namespace std;

int main(){
	try{
		BrowserTab tab;
		tab.visitPage("www.google.com");
		tab.visitPage("www.google.com/search?source=hp&q=hello");
		tab.visitPage("www.google.com/search?source=hp&q=spartans");
		tab.visitPage("www.google.com/search?source=hp&q=sjsu");

		// Current page is https://www.google.com/search?source=hp&q=sjsu
		cout << "Current Page: " << tab.getCurrentPage() << endl;

		tab.back(); // Current page becomes https://www.google.com/search?source=hp&q=spartans
		cout << "After back: " << tab.getCurrentPage() << endl;

		tab.back(); // Current page becomes https://www.google.com/search?source=hp&q=hello
		cout << "After back: " << tab.getCurrentPage() << endl;

		tab.forward(); // Current page becomes https://www.google.com/search?source=hp&q=spartans
		cout << "After forward: " << tab.getCurrentPage() << endl;

		tab.forward(); // Current page becomes https://www.google.com/search?source=hp&q=sjsu
		cout << "After forward: " << tab.getCurrentPage() << endl;

//		b.forward(); // Uncommenting this statement should throw an error that no more forwards are possible
//		cout << "After forward: " << b.getCurrentPage() << endl;

		tab.back(); // Current page becomes https://www.google.com/search?source=hp&q=spartans
		cout << "After back: " << tab.getCurrentPage() << endl;

		tab.printHistory();
		/***************
		 * Use your own format *
		Visited www.google.com
		Visited www.google.com/search?source=hp&q=hello
		Visited www.google.com/search?source=hp&q=spartans
		Visited www.google.com/search?source=hp&q=sjsu
		Back to www.google.com/search?source=hp&q=spartans
		Back to www.google.com/search?source=hp&q=hello
		Forward www.google.com/search?source=hp&q=spartans
		Forward to www.google.com/search?source=hp&q=sjsu
		Back to www.google.com/search?source=hp&q=spartans
		 **************/
	}
	catch(const char* c){
		cout << c << endl;
	}
/****************** UNCOMMENT TO TEST BROWSER CODE *****************************
	try{
		Browser browser;
		BrowserTab tab;
		tab.visitPage("www.google.com");
		tab.visitPage("www.google.com/search?source=hp&q=sjsu");
		browser.openTab(tab);
		browser.getCurrentTab()->printHistory();
		cout << "Current tab index: " << browser.getCurrentTabIndex() << endl;
		cout << "Num Tabs: " << browser.getNumTabs() << endl;

		BrowserTab tab2;
		browser.openTab(tab2);
		browser.switchToTab(1);
		cout << "Current tab index: " << browser.getCurrentTabIndex() << endl;
		cout << "Num Tabs: " << browser.getNumTabs() << endl;

		browser.getCurrentTab()->visitPage("index.html");
		browser.getCurrentTab()->visitPage("contact.html");
		browser.getCurrentTab()->back();
		browser.getCurrentTab()->printHistory();


	}
	catch(const char* c){
		cout << c << endl;
	}
*********************************************************************************/
}
