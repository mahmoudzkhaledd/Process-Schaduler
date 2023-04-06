#pragma once
#include "../Process/Process.h"
#include "../DataStructures/Queue.h"
#include "../DataStructures/LinkedList.h"
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
	Queue<Process> readyProcess;
	ProcessorState state;
	ProcessorType type;
	Processor(ProcessorType t);
	void executeNextProcess();
	void updateState();
	int getUtilTime();
};