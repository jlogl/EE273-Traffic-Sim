#include "Signal.h"
#include <iostream>

Signal::Signal(std::vector<bool> seq, std::pair<int, int> pos) {
	this->go = seq.front();
	this->sequence = seq;
	this->period = seq.size();
	this->seqTime = 0;
	this->position = pos;

	//to test; remove before submisssion
	std::cout << "Signal successfully created" << std::endl;
}
Signal::~Signal() {

}

void Signal::setGo() {
	this->go = sequence.at(seqTime);
}
void Signal::nextStep() {
	if ( this->seqTime >= this->period - 1) {
		this->seqTime = 0;	// resets to start of sequence if at the end
	}
	else {
		this->seqTime++;	// otherwise increments by 1 step
	}

	this->setGo();
}

bool Signal::isGreen() {
	return(this->go);
}

std::pair<int, int> Signal::getPos() {
	return(this->position);
}
int Signal::getSeqPeriod() {
	return(this->period);
}