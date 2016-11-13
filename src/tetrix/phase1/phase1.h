#ifndef PHASE1_H
#define PHASE1_H
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

#ifndef ROOT_PASSWORD
#define ROOT_PASSWORD "tetrix"
#endif

class phase1{
 private:
 public:
  int execute();
  phase1();
  ~phase1();
};
#endif
