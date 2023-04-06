#pragma once
#include"../Processor/MainProcessor.h"
#include "../DataStructures/List/List.h"
#include "../DataStructures/Queue/Queue.h"

class FileLayer {
public:
	List<Process> loadInputFile();
};