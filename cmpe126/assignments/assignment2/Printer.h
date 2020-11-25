#ifndef PRINTER_H
#define PRINTER_H
#include <iostream>

class PrinterManager {
	public:
		PrinterManager(unsigned int = 10);
		~PrinterManager();
		unsigned int getNumPrinters() const;
		unsigned int getNumFreePrinters() const;
		void usePrinter(unsigned int);
		void freePrinter(unsigned int);
		void print();	
	private:
		bool* printers;
		unsigned numPrinters, freePrinters;
};

#endif
