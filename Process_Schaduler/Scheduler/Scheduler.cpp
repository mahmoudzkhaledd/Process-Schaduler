#include "Scheduler.h"
#include "../Processor/MainProcessor.h"
#include "../FilesLayer/FileLayer.h"
void Scheduler::nextTimeStep() {
	
}

Processor* Scheduler::getShortestProcessor() {
	Processor* minProcessor = null;
	int minTime = 0;
	for (int i = 0; i < processors.count; i++) {
		if (processors.ElementAt(i)->exepectedTimeToFinish < minTime) {
			minTime = processors.ElementAt(i)->exepectedTimeToFinish;
			minProcessor = processors.ElementAt(i);
		}
	}
	return minProcessor;
}

void Scheduler::loadProcess() {
	FileLayer f;
	NEWList = f.loadInputFile();
	for (int i = 0; i < NEWList.count; i++) {
		cout << NEWList.ElementAt(i)->arrivalTime << " " << NEWList.ElementAt(i)->pid << " "
			<< NEWList.ElementAt(i)->cpuTime << " " << NEWList.ElementAt(i)->numOfIoReqs << endl;
	}
}

void Scheduler::NEWToRDY(Processor* p) {
	if (NEWList.count == 0) return;

	int min = 0;
	Process* minProc = null;
	for (int i = 0; i < NEWList.count; i++) {
		if (NEWList.ElementAt(i)->arrivalTime < min) {
			min = NEWList.ElementAt(i)->arrivalTime;
			minProc = NEWList.ElementAt(i);
		}
	}
	Processor* prr = getShortestProcessor();
	prr->readyProcesses.enQueue(minProc);
	minProc->state = RDY;
	NEWList.Delete(minProc);
}

void Scheduler::RUNtoBLK(Process* p) {
	// Call UI To Get Input
	BLKList.insert(p);
	p->state = BLK;
}

// System Process and User Process. 
// Page 7 .
void Scheduler::BLKtoRDY(Process* p) {
	Processor* proc = getShortestProcessor();
	proc->readyProcesses.enQueue(p);
	p->state = RDY;
	BLKList.Delete(p);
}

void Scheduler::toTRM(Process* p) {
	TRMList.insert(p);
	p->state = TRM;
}
