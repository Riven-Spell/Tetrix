#ifndef PHASE3_H
#define PHASE3_H
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

#ifndef ROOT_PASSWORD
#define ROOT_PASSWORD "tetrix"
#endif

class phase3{
 private:
 public:
  int execute();
  phase3();
  ~phase3();
};
#endif
