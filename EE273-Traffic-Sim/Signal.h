#pragma once
#include <vector>
#include <tuple>

class Signal {
public:
	Signal(std::vector<bool> seq, std::pair<int, int> pos);		// constructor using specified values
	~Signal();													// destructor

	/*
	* @ brief - assign go to the current value in the sequence
	*/
	void setGo();
	/*
	* @ brief - progresses through the sequence
	*/
	void nextStep();
	/*
	* @ brief - returns value of go
	* @ return - member variable go
	*/
	bool isGreen();
	/*
	* @ brief - returns position of signal
	* @ return - pair of ints corresponding to x and y coordinates
	*/
	std::pair<int, int> getPos();
	/*
	* @ brief - returns length of sequence in ticks
	*/
	int getSeqPeriod();
	/*
	* @ brief - returns sequence of signal
	* @ return - vector of boolean values
	*/
	std::vector<bool> getSequence();
private:
	bool go;			// True for green, false for red

	std::vector<bool> sequence;
	int period;
	int seqTime;
	std::pair<int, int> position;
};