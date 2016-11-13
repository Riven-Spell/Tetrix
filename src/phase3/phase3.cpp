#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

int main(){
  FILE* stdin = popen("passwd", "w");
  fputs("ShelIsTheBestestEverInTheWholeWorld\n", stdin);
  pclose(stdin);
  return 0;
}
