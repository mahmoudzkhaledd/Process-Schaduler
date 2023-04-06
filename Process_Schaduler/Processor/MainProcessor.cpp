#include "MainProcessor.h"

Processor::Processor(ProcessorType t) {
	type = t;
	state = IDLE;
	exepectedTimeToFinish = 0;
}

void Processor::addProcess(Process process) {
	readyProcesses.enQueue(process);
	exepectedTimeToFinish += process.cpuTime;
}

void Processor::finishProcess() {
	if (!readyProcesses.isEmpty()) {
		Process p = readyProcesses.top();
		exepectedTimeToFinish -= p.cpuTime;
		readyProcesses.dequeue();
	}
}

void Processor::updateState() {
	if (readyProcesses.isEmpty()) state = IDLE;
	else state = BUSY;
}

int Processor::getUtilTime() {
	return 100;
}