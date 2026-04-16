#pragma once

class Signal {
public:
	Signal();							// blank constructor
	Signal(int g, int r);				// constructor using specified values; g and r for time spent on green and on red
	Signal(int g, int r, int offset);	// offset is initial cycle time
	~Signal();							// destructor

	bool getLight();
	void forceSignal(bool s);
	int getOnTime();
	int getOffTime();
	int getCycleTime();
	void setCycleTime(int t);

private:
	bool go;				// True for green, false for red

	int onPeriod;		// Period for which the signal is on (green)
	int offPeriod;		// Period for which the signal is off (red)
	int cycleTime;
};