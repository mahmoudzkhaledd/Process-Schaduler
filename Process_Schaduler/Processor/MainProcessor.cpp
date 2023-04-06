#include "MainProcessor.h"

Processor::Processor(ProcessorType t) {
	type = t;
	state = IDLE;
	exepectedTimeToFinish = 0;
}

void Processor::addProcess(Process process) {
	readyProcess.enQueue(process);
	exepectedTimeToFinish += process.cpuTime;
}

void Processor::finishProcess() {
	if (!readyProcess.isEmpty()) {
		Process p = readyProcess.top();
		exepectedTimeToFinish -= p.cpuTime;
		readyProcess.dequeue();
	}
}

void Processor::executeNextProcess() {

}

void Processor::updateState() {
	if (readyProcess.isEmpty()) state = IDLE;
	else state = BUSY;
}

int Processor::getUtilTime() {
	return 100;
}