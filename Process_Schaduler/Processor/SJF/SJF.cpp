#include "SJF.h"
SJFProcessor::SJFProcessor() : Processor(SJF) {

}
Process* SJFProcessor::getShortestProcess() {
	Process* shortestProcess = null;
	int minCpuTime = INT_MAX;

	for (int i = 0; i < readyProcesses.count; i++) {
		Process* p = readyProcesses.elementAt(i);
		if (p->cpuTime < minCpuTime) {
			minCpuTime = p->cpuTime;
			shortestProcess = p;
		}
	}
	return shortestProcess;
}
void SJFProcessor::executeNextProcess() {

}

void SJFProcessor::sceduleAlgo() {
	if (!readyProcesses.isEmpty()) {
		Process* shortest = getShortestProcess();
		shortest->execute();
	}
}
