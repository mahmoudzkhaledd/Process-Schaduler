#pragma once
enum ProcessState {
	RDY,
	NEW,
	RUN,
	BLK,
	TRM,
	ORPH,
};
class Process {
public:
	int pid;
	int numOfIoReqs;
	int arrivalTime;
	int responseTime;
	int cpuTime;
	int terminationTime;
	int turnAroundDuration;
	int waitingTime;
	
	Process();
	ProcessState state;
	virtual void execute();

};