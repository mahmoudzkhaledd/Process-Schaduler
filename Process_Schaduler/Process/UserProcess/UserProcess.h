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
	int arrivalTime;
	int responseTime;
	int cupTime;
	int terminationTime;
	int turnAroundDuration;
	int waitingTime;
	
	Process();
	ProcessState state;
	void execute();

};