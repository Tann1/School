#ifndef JOBQUEUE_H
#define JOBQUEUE_H
#include <iostream>
#include <queue>

class JobQueue {
	public:
		JobQueue(unsigned int = 10);
		bool isEmpty() const;
		bool isFull() const;
		unsigned int getNumJobs() const;
		unsigned int getMaxNumJobs() const;
		void print();
		bool addJob(unsigned int);
		unsigned int serveJob();
		void clearQueue();
	private:
		unsigned int numJobs, maxNumJobs;
		std::queue<unsigned int> jobQueue;	

};


#endif
