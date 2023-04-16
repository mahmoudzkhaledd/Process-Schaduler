#pragma once
#include "../MainProcessor.h"
class SJFProcessor : public Processor {
public:
	SJFProcessor();
	Process* getShortestProcess();
	virtual void executeNextProcess();
	virtual void sceduleAlgo();
};