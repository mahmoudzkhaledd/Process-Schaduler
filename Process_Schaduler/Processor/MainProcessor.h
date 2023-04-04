#pragma once
#include "../Process/Process.h"
#include "../DataStructures/Queue.h"
#include "../DataStructures/LinkedList.h"
enum ProcessorState {
	BUSY,
	IDLE,
};
class Processor {
public:
	Queue<Process> readyProcess;
	ProcessorState state;
	Processor();
	void executeNextProcess();
	void updateState();
	int getUtilTime();
};