#pragma once
#include <vector>
#include <tuple>

class Signal {
public:
	Signal(std::vector<bool> seq, std::pair<int, int> pos);		// constructor using specified values
	~Signal();													// destructor

	void setGo();
	void nextStep();
	bool isGreen();
	std::pair<int, int> getPos();
	int getSeqPeriod();

private:
	bool go;			// True for green, false for red

	std::vector<bool> sequence;
	int period;
	int seqTime;
	std::pair<int, int> position;
};