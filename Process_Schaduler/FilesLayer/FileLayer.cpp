#include "FileLayer.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../Process/Process.h"
void FileLayer::loadInputFile() {
	int count_read = 0;

	/*Number of processes*/
	int N_P = 0;
	int characters_read = 0;

	/*Processes*/
	Process* APR = new Process[N_P];
	int current_line = 1;
	ifstream myfile;
	myfile.open("file.txt");
	string myline;
	if (myfile.is_open()) {
		while (myfile)
		{
			if (current_line > 4)    /*Reading Processes info.*/
			{
				if (count_read == 0)   /*READING AT*/
				{
					myfile >> myline;
					APR[current_line - 5].arrivalTime = stoi(myline);
					count_read++;
				}

				else if (count_read == 1)   /*READING PID*/
				{
					myfile >> myline;
					APR[current_line - 5].pid =  stoi(myline);
					count_read++;
				}
				else if (count_read == 2)   /*READING CT*/
				{
					myfile >> myline;
					APR[current_line - 5].cupTime = stoi(myline);
					count_read++;
				}
				else if (count_read == 3) /*Reading requests*/
				{
					myfile >> myline;
					APR[current_line - 5].numOfIoReqs = stoi(myline);
					count_read++;
				}
				else if (count_read == 4) /* Reading Pairs of I/O */
				{
					count_read = 0;  //reseting count read for next process
					current_line++;
				}
			}
			else if (current_line == 1)
			{
				getline(myfile, myline);
				current_line++;
			}

			else if (current_line == 2)
			{
				getline(myfile, myline);
				current_line++;
			}

			else if (current_line == 3)
			{
				getline(myfile, myline);
				current_line++;
			}

			else if (current_line == 4)
			{
				getline(myfile, myline);
				N_P = stoi(myline);   /*Number of processes evaluated*/
				APR = new Process[N_P];
				current_line++;
			}
			else
				current_line++;
		}
	}
	else {
		std::cout << "Couldn't open file\n";
	}
	cout << "Number of processes are :" << N_P << endl;
	for (int i = 0; i < N_P; i++) {
		cout << APR[i].arrivalTime << " " 
			 << APR[i].pid         << " " 
			 << APR[i].cupTime     << " " 
			 << APR[i].numOfIoReqs << endl;
	}
}