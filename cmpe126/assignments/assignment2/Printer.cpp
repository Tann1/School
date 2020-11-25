#include "Printer.h"


PrinterManager::PrinterManager(unsigned int numPrinters) {
	this->numPrinters = numPrinters;
	this->freePrinters = numPrinters; //assuming all are free
	this->printers = new bool[numPrinters];

	for (int i = 0; i < numPrinters; ++i)
		this->printers[i] = false; //false = free
}

PrinterManager::~PrinterManager() {
	delete []this->printers;
}

unsigned int PrinterManager::getNumPrinters() const  {
	return this->numPrinters;
}

unsigned int PrinterManager::getNumFreePrinters() const {
	return this->freePrinters;
}

void PrinterManager::usePrinter(unsigned int pos) {
	if (this->printers[pos] == true)
		throw "printer already busy";
	this->printers[pos] = true, this->freePrinters--;
}

void PrinterManager::freePrinter(unsigned int pos) {
	if (this->printers[pos] == false)
		throw "printer already free";
	this->printers[pos] = false, this->freePrinters++;
}

void PrinterManager::print() {
	std::cout << std::boolalpha;
	for (int i = 0; i < this->numPrinters; ++i)
		std::cout << "printer[" << i << "] = " << this->printers[i] << std::endl;
}
