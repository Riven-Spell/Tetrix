#include <unistd.h>//For sleep()
#include <random.h>//for generating random numbers
#include <cstdlib>//For system().

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if ( first ) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}


class phase1{
 private:
 public:
  int execute();
  phase2();
  ~phase2();
};
