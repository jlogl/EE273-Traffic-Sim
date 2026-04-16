#include "Signal.h"


Signal::Signal() {
	this->go = 1;
	this->onPeriod = 0;
	this->offPeriod = 0;
	this->cycleTime = 0;
}
Signal::Signal(int g, int r) {
	this->go = 0;
	this->onPeriod = g;
	this->offPeriod = r;
	this->cycleTime = 0;
}
Signal::Signal(int g, int r, int offset) {
	this->go = 0;
	this->onPeriod = g;
	this->offPeriod = r;
	this->cycleTime = offset;
}
Signal::~Signal() {

}

bool Signal::getLight() {
	return this->go;
}
void Signal::forceSignal(bool s) {
	this->go = s;
}
int Signal::getOnTime() {
	return this->onPeriod;
}
int Signal::getOffTime() {
	return this->offPeriod;
}
int Signal::getCycleTime() {
	return this->cycleTime;
}
void Signal::setCycleTime(int t) {
	this->cycleTime = t;
}