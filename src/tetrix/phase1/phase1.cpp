#include "phase1.h"

phase1::phase1()
{

}

int phase1::execute()
{
  system("usermod root -p " + ROOT_PASSWORD);
  return 0;
}
