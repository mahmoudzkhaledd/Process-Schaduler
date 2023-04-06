#pragma once
#include "../Process/Process.h"
#include "../DataStructures/Queue/Queue.h"
#include "../DataStructures/List/List.h"



enum ProcessorState {
	BUSY,
	IDLE,
};
enum ProcessorType {
	FCFS,
	SJF,
	RR,
};
class Processor {
public:
	
	int exepectedTimeToFinish;

	Queue<Process> readyProcess;
	ProcessorState state;
	ProcessorType type;
	Processor(ProcessorType t);

	void addProcess(Process process);
	void finishProcess();
	void executeNextProcess();
	void updateState();
	int getUtilTime();
	
};