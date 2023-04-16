#pragma once
#include "../Processor/MainProcessor.h"
#include "../DataStructures/List/List.h"
#include "../DataStructures/Queue/Queue.h"
#include "../DataStructures/PQueue/PQueue.h"

class Scheduler {
public:
	int currentTime;
	Scheduler();
	List<Process*> allProcess; // arranged with arrival time
	List<Processor*> processors;
	Processor* getShortestProcessor();
	void loadProcess();
	void loadFromFile();
	void nextTimeStep();
};