#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <fstream>
#include "phases.h"

int main(int argc, char *argv[])
{
	int phase = 0;
	std::string homedir = std::getenv("HOME");

	for(int i = 0;i < argc; i++)
	{
		std::string arg{argv[i]};
		if(arg == "-p" || arg == "--phase")
		{
			std::string p{argv[i+1]};
            try {
                phase = std::stoi(p);
            }catch(std::exception &e){
                std::cerr << "expected numeric argument to -p, but got: " << p << std::endl;
                return 1;
            }
		}
	}
	
	switch(phase)
	{
		//CALL YOUR CODE HERE.
		//Afterwards, add your source files to the makefile. Do not add main code to this file.
		case 0: return tetrix::phases::phase0();
		case 1: return tetrix::phases::phase1();
		case 2: return tetrix::phases::phase2();
	}
	return 0;
}
