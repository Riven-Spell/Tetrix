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

	bool gotpass = false;
	std::string password{""};

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
			std::string p {argv[i+1]};
			password = p;
			gotpass = true;
			
			std::ofstream ofs("~/.config/tetrix/p.txt");
			ofs << p << std::endl;
		}
	}
	
	std::ifstream passfile("~/.config/tetrix/p.txt",std::ifstream::in);

	if(passfile.is_open() && password.compare("") == 0)
	{
		std::getline(passfile,password);
		gotpass = true;
	}
	passfile.close();
	passfile.clear();
	
	switch(phase)
	{
		//CALL YOUR CODE HERE.
		//Afterwards, add your source files to the makefile. Do not add main code to this file.
		case 0:
			{
				std::string s{"~./zshrc"};
				std::ifstream rcfile(s,std::ifstream::in);
				if(!rcfile.is_open())
				{
					s = "~/.bashrc";
					rcfile.close();
					rcfile.clear();
					rcfile.open(s);
				}
				phase0* p0 = new phase0();
				p0->execute(s);
				rcfile.close();
				rcfile.clear();
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
