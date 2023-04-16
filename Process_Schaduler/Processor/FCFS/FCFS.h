#pragma once
#include "../MainProcessor.h"
class FCFSProcessor : public Processor {
public:
	FCFSProcessor();
	virtual void executeNextProcess();
	virtual void sceduleAlgo();
};
