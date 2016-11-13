#include "phase2.h"

phase2::phase2()
{
	
}

int phase2::execute()
{
	int secsToWait;
	
	secsToWait = rand() % 8 + 4; //(pseudo)Randomly selects number from 4 to 12.
	
	sleep(secsToWait);
	
 	system("xdg-open Hacked.gif"); //Opens the "Hacked.gif".

	return 0;
}
