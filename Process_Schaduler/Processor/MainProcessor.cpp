#include "MainProcessor.h"

Processor::Processor(ProcessorType t) {
	type = t;
	state = IDLE;
	exepectedTimeToFinish = 0;
}

void Processor::loadProcess(Process* process) {
	readyProcesses.insert(process, process->cpuTime);
	exepectedTimeToFinish += process->cpuTime;
}

void Processor::finishProcess() {
	
}

void Processor::updateState() {
	if (readyProcesses.isEmpty()) state = IDLE;
	else state = BUSY;
}

int Processor::getUtilTime() {
	return 100;
}

int Processor::calcLoad() {
	return 0;
}
