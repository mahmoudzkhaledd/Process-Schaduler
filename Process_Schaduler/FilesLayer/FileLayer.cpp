#include "FileLayer.h"
#include <iostream>
#include <fstream>
#include "../DataStructures/List/List.h"
#include "../Process/Process.h"
void FileLayer::loadInputFile() {
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
	List<Process> process;
	for (int i = 0; i < n; i++) {
		Process p;
		stream >> p.arrivalTime >> p.pid >> p.cupTime >> p.numOfIoReqs;
		process.insert(p);
	}
	for (int i = 0; i < process.count; i++) {
		cout << process.ElementAt(i).arrivalTime  << " " << process.ElementAt(i).pid <<" " << process.ElementAt(i).cupTime <<" " << process.ElementAt(i).numOfIoReqs<<endl;
	}
	stream.close();
}
