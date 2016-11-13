#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <fstream>
#include "phase0/phase0.h"
#include "phase1/phase1.h"
#include "phase2/phase2.h"

int main(int argc,char *argv[])
{
	int phase = 0;
	std::string test;

	std::string homedir = std::getenv("HOME");

	for(int i = 0;i < argc;i++)
	{
		std::string arg {argv[i]};
		if(arg.compare("-p") == 0 || arg.compare("--phase") == 0)
		{
			std::string p {argv[i+1]};
			phase = std::stoi(p);
		}
	}
	
	switch(phase)
	{
		//CALL YOUR CODE HERE.
		//Afterwards, add your source files to the makefile. Do not add main code to this file.
		case 0:
			{
				phase0* p0 = new phase0();
				p0->execute();
			}
			break;
		case 1:
			{
				phase1* p1 = new phase1();
				p1->execute();
			}
			break;
		case 2:
			{
				phase2* p2 = new phase2();
				p2->execute();
			}
		break;
	}
	return 0;
}
