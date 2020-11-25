#include <iostream>
#include "BrowserTab.h"



BrowserTab::BrowserTab() {
	this->current_page = "";
	this->history = new std::string[20]; 
	this->index = 0;
	this->max_size = 20;
}

BrowserTab::~BrowserTab() {
	delete [] this->history;
}


void BrowserTab::visitPage(std::string site) {
	check();
	this->history[index++] = "Visted: " + site; //add to the log
	current_page = site;
	prevPage.push(site);
}

void BrowserTab::back() {
	if (prevPage.size() < 2)
		throw "NO previous back site available";
		
	nextPage.push(prevPage.top()), prevPage.pop();
	current_page = prevPage.top();
	check();
	this->history[index++] = "Backed to: " + current_page;	
}

void BrowserTab::forward() {
	if (nextPage.size() < 1)
		throw "NO next site available";
	current_page = nextPage.top();
	prevPage.push(nextPage.top()), nextPage.pop();
	check();
	this->history[index++] = "Forwarded to: " + current_page;

}

std::string BrowserTab::getCurrentPage() {
	return this->current_page;
}

void BrowserTab::printHistory() {
	for (int i = 0; i < index; ++i)
		std::cout << history[i] << std::endl;
}


void BrowserTab::check() {	

	std::string* temp = nullptr;
	if (!(this->index == this->max_size)) //meaning not full
		return;

	max_size *= 2;
	temp = new std::string[max_size];
	for (int i = 0; i < this->index; ++i)
		temp[i] = this->history[i];

	delete []this->history;
	history = temp;
}
