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
	List<Process*> runProcesses;
	Queue<Process*> readyProcesses;
	ProcessorState state;
	ProcessorType type;
	Processor(ProcessorType t);

	void addProcess(Process* process);
	void finishProcess();
	virtual void executeNextProcess() = 0;
	virtual void sceduleAlgo() = 0;
	void updateState();
	int getUtilTime();
	
};