#ifndef PHASE2_H
#define PHASE2_H
#include <unistd.h>//For sleep()
#include <random>//for generating random numbers
#include <cstdlib>//For system().
#include <dirent.h>//For going through directories.
#include <sys/types.h>//Same
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "tetros-as-hex.h"
#include "Copypasta.c"

class phase2 {
 private:
 public:
  int execute();
  phase2();
  ~phase2();
};
#endif
