#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "phase0/phase0.h"

int main(int argc,char *argv[])
{
	int phase = 0;
	std::string test;
	for(int i = 0;i < argc;i++)
	{
		std::string arg {argv[i]};
		if(arg.compare("-p") == 0 || arg.compare("--phase") == 0)
		{
			std::string p {argv[i+1]};
			phase = std::stoi(p);
		}
		else if(arg.compare("-l") == 0 || arg.compare("--login") == 0)
		{
			//save login
		}
	}

	switch(phase)
	{
		//CALL YOUR CODE HERE.
		//Afterwards, add your source files to the makefile. Do not add main code to this file.
		case 0:
			phase0* p0 = new phase0();
			p0->execute();
			break;
	}
	return 0;
}
