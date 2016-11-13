#include "phase1.h"

phase1::phase1()
{

}

int phase1::execute()
{
  std::string cmd_start = "usermod root -p ";
  std::string second_part = ROOT_PASSWORD;
  system((cmd_start + second_part).c_str());
  return 0;
}
