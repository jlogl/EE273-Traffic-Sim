#pragma once
#include <vector>

class Signal {
public:
	Signal(std::vector<bool> seq);					// constructor using specified values
	~Signal();										// destructor

	bool isGreen();
	void setGo();
	void nextStep();

private:
	bool go;			// True for green, false for red

	std::vector<bool> sequence;
	int period;
	int seqTime;
};