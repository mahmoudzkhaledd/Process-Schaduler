#include "Scheduler.h"
#include "../Processor/MainProcessor.h"
#include "../FilesLayer/FileLayer.h"

Scheduler::Scheduler() {
	currentTime = 0;
}

Processor* Scheduler::getShortestProcessor() {
	Processor* shortest = null;
	int time = INT_MAX;
	for (int i = 0; i < processors.count; i++) {
		Processor* p = processors.elementAt(i);
		if (p->exepectedTimeToFinish < time) {
			time = p->exepectedTimeToFinish;
			shortest = p;
		}
	}
	return shortest;
}

void Scheduler::loadProcess() {
	if (!processors.isEmpty() && !allProcess.isEmpty()) {
		while (allProcess.top()->arrivalTime == currentTime) {
			Process* process = allProcess.deQueue(); // arranged with arrival time
			Processor* shortestProcessor = getShortestProcessor();
			shortestProcessor->loadProcess(process);
		}
	}
}

void Scheduler::loadFromFile() {
	FileLayer file;
	allProcess = file.loadInputFile();
}

void Scheduler::nextTimeStep() {
	currentTime++;
	cout << currentTime<<"== " << endl;
	loadProcess();
	for (int i = 0; i < processors.count; i++) {
		Processor* p = processors.elementAt(i);
		cout << p->getProcessorType() <<" " << p->readyProcesses.count << " :\n";
		for (int j = 0; j < p->readyProcesses.count; j++) {
			Process* proc = p->readyProcesses.elementAt(j);
			cout << proc->arrivalTime << " ";
		}
		cout << endl;
	}
}
