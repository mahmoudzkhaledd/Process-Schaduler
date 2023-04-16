#include "FCFS.h"
FCFSProcessor::FCFSProcessor() : Processor(FCFS) {

}
void FCFSProcessor::executeNextProcess() {

}

void FCFSProcessor::sceduleAlgo() {
	if (!readyProcesses.isEmpty()) {
		Process* p = readyProcesses.elementAt(0);
		p->execute();
	}
}
