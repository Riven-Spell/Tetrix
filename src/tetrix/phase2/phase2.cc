phase2::execute()
{
	int secsToWait;
	
	secsToWait = random(4, 12); //(pseudo)Randomly selects number from 4 to 12.
	
	sleep(secsToWait);
	
 	system("xdg-open Hacked.gif"); //Opens the "Hacked.gif".

	return 0;
}
