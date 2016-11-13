#include "phase2.h"

phase2::phase2()
{

}

int phase2::execute()
{
	int secsToWait;
	
	secsToWait = rando(4, 12); //(pseudo)Randomly selects number from 4 to 12.
	
	sleep(secsToWait);
	
 	system("xdg-open Hacked.gif"); //Opens the "Hacked.gif".

	return 0;
}

int rando(int min, int max) //range : [min, max)
{
   static bool first = true;
   if ( first ) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}

