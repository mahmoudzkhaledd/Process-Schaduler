#pragma once
#include "../Process/Process.h"
#include "../DataStructures/PQueue/PQueue.h"
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

	List<Process*> runningProcesses;
	List<Process*> readyProcesses;

	ProcessorState state;
	ProcessorType type;
	Processor(ProcessorType t);
	string getProcessorType() {
		if (type == FCFS) return "FCFS";
		else if (type == SJF) return "SJF";
		else return "RR";
	}
	void loadProcess(Process* process);
	void finishProcess();
	virtual void executeNextProcess() = 0;
	virtual void sceduleAlgo() = 0;
	void updateState();
	int getUtilTime();
	int calcLoad();

};