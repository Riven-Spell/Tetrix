#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

int main(){
  FILE* stdin = popen("passwd", "w");
  char* newpass = "tetrix";
  fputs(newpass, stdin);
  fputs(newpass, stdin);
  pclose(stdin);
  return 0;
}
