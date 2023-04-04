#include "MainProcessor.h"

Processor::Processor() {
	state = IDLE;
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
