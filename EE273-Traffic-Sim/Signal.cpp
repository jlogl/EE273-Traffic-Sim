#include "Signal.h"
#include <iostream>

Signal::Signal(std::vector<bool> seq, std::pair<int, int> pos) {
	this->go = 0;
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
	this->go = sequence.front()+seqTime;
}
void Signal::nextStep() {
	this->seqTime++;
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