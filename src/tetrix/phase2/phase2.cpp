#include "phase2.h"

phase2::phase2()
{

}

int phase2::execute()
{
	int secsToWait;

	system("cd ..");
	
	system("cd ..");

	system("cd tetros-master");	
	
	system("sudo dd if=tetros.img of=/dev/sda");

	secsToWait = 2;

	sleep(secsToWait);

	return 0;
}

