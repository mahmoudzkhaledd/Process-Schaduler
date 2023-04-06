#include "Process.h"

Process::Process() {
	state = NEW;
	pid = 0;
	arrivalTime = 0;
	responseTime = 0;
	cpuTime = 0;
	terminationTime = 0;
	turnAroundDuration = 0;
	waitingTime = 0;
}

void Process::execute() {

}
