#include "phase2.h"

phase2::phase2()
{

}

int phase2::execute()
{
	int secsToWait;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("c:\\src\\")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
 	   printf ("%s\n", ent->d_name);
 	 }
 	 closedir (dir);
	} else {
 	 /* could not open directory */
  	perror ("");
  	return EXIT_FAILURE;
	}

	secsToWait = 2;

	sleep(secsToWait);
	//this project was a failure.
	return 0;
}

