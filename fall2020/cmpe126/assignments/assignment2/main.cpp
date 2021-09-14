#include <stdlib.h>
#include <time.h>
#include "JobQueue.h"
#include "Printer.h"


int main() {
	srand(time(NULL));
	unsigned int maxNumJobs = 10;
	unsigned int numPrinters = 2;
	JobQueue jobs(maxNumJobs);
	PrinterManager printers(numPrinters); //is how many printers we need
	try {
		jobs.addJob(1);
		jobs.addJob(2);
		printers.usePrinter(jobs.serveJob() % numPrinters);
		jobs.addJob(3);
		jobs.addJob(4);
		printers.usePrinter(jobs.serveJob() % numPrinters);
		printers.freePrinter(1);
		printers.usePrinter(jobs.serveJob() % numPrinters);
		std::cout << "job queue" << std::endl;
		jobs.print(); std::cout << std::endl;
		std::cout << "printing the printers' status" << std::endl;
		printers.print();
		
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
/*
	own testing from this point on
*/

	std::cout << std::endl << std::endl;
	std::cout << "more testing" << std::endl;
	JobQueue testJobs(maxNumJobs);
	PrinterManager testPrinters(maxNumJobs);
	for (int i = 0; i < maxNumJobs; ++i)
		testJobs.addJob(rand() % 100 + 1); //random num from 0 to 100
	
	std::cout << "printing the jobs" << std::endl;
	testJobs.print(); std::cout << std::endl;
	std::cout << "printing the printers' status before any jobs are given to it" << std::endl;
	testPrinters.print();
	try {
		for (int i = 0; i < maxNumJobs/2; ++i) //only doing 5 to limit the chance of running into duplicates from random number generator 
			testPrinters.usePrinter(testJobs.serveJob() % maxNumJobs);
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	}
	std::cout << std::endl << "printing the printers' status after half the jobs are done" << std::endl;
	testPrinters.print();
	return 0;
}
