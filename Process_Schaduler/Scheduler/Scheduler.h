#pragma once
#include "../Processor/MainProcessor.h"
#include "../DataStructures/List/List.h"
#include "../DataStructures/Queue/Queue.h"
#include "../DataStructures/PQueue/PQueue.h"

class Scheduler {
public:
	
	List<Process*> NEWList;
	List<Process*> TRMList;
	List<Process*> BLKList;
	List<Processor*> processors;

	void nextTimeStep();
	Processor* getShortestProcessor();

	void loadProcess(); // Load From InputFile To NEW List
	void NEWToRDY(Processor* p);
	void RUNtoBLK(Process* p);
	void BLKtoRDY(Process* p);
	void toTRM(Process* p);
};