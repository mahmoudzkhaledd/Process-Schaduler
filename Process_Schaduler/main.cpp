#include<iostream>
#include"DataStructures/Queue/Queue.h"
#include "FilesLayer/FileLayer.h"
#include "Scheduler/Scheduler.h"
#include"Processor/FCFS/FCFS.h"
#include"Processor/RR/RR.h"
#include"Processor/SJF/SJF.h"

#define null NULL
using namespace std;
int main() {
	FileLayer f;
	List<Process*> l = f.loadInputFile();
	
	Scheduler s;
	s.processors.insert(new FCFSProcessor());
	s.processors.insert(new SJFProcessor());
	s.processors.insert(new RRProcessor());
	s.loadFromFile();
	s.nextTimeStep();
	s.nextTimeStep();
	s.nextTimeStep();
	s.nextTimeStep();
}