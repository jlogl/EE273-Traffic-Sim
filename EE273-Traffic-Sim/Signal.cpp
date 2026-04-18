#include "Signal.h"
#include <iostream>

Signal::Signal(std::vector<bool> seq) {
	this->go = 0;
	this->sequence = seq;
	this->period = seq.size();
	this->seqTime = 0;

	//to test; remove before submisssion
	std::cout << "Signal successfully created" << std::endl;
	char c;
	std::cin >> c;
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