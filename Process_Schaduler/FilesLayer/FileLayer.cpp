#include "FileLayer.h"
#include <iostream>
#include <fstream>
#include "../DataStructures/List/List.h"
#include "../Process/Process.h"
List<Process*> FileLayer::loadInputFile() {
	fstream stream;
	stream.open("file.txt");
	int fcfsNum = 0, sjfNum = 0, rrNum = 0;
	int rrTimeSlice; 
	int rtf, maxW, stl, forkProb;
	stream >> 
		fcfsNum >>
		sjfNum >> 
		rrNum >> 
		rrTimeSlice >>
		rtf >>
		maxW >> 
		stl >> 
		forkProb;
	int n;
	stream >> n;
	List<Process*> process;
	for (int i = 0; i < n; i++) {
		Process* p = new Process();
		stream >> p->arrivalTime >> p->pid >> p->cpuTime >> p->numOfIoReqs;
		process.insert(p,-p->arrivalTime);
	}
	
	stream.close();
	return process;
}
