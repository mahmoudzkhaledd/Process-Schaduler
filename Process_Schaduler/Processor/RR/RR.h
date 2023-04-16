#pragma once
#include "../MainProcessor.h"
class RRProcessor : public Processor {
public:
	int timeSlice;

	RRProcessor();
	virtual void executeNextProcess();
	virtual void sceduleAlgo();
};