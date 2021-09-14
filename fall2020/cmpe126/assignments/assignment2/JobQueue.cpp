#include "JobQueue.h"


JobQueue::JobQueue(unsigned int maxNumJobs) {
	this->maxNumJobs = maxNumJobs;
	this->numJobs = 0;
}

bool JobQueue::isEmpty() const {
	return this->jobQueue.empty();
}

bool JobQueue::isFull() const  {
	return this->numJobs == this->maxNumJobs;
}

unsigned int JobQueue::getNumJobs() const {
	return this->numJobs;
}

unsigned int JobQueue::getMaxNumJobs() const {
	return this->maxNumJobs;
}

void JobQueue::print() {
	std::queue<unsigned int> temp = this->jobQueue;

	while (!temp.empty())
		std::cout << temp.front() << " ", temp.pop();
}

bool JobQueue::addJob(unsigned int ID) {
	if (this->isFull())
		return false;
	this->jobQueue.push(ID), this->numJobs++;
	return true;
}

unsigned int JobQueue::serveJob() {
	if (this->isEmpty())
		throw "no jobs to serve";
	unsigned int ID = this->jobQueue.front();
	this->jobQueue.pop(), this->numJobs--;
	return ID;
}

void JobQueue::clearQueue() {
	while (!this->jobQueue.empty())
		this->jobQueue.pop();
}


