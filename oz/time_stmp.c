/*******************************************************************************
  Title          : 
  Author         : http://www.makelinux.net/alp/098
  Created on     : 
  Description    : Create a new file in the PWD with timestamp saved inside
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : gxx -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/


#include <fcntl.h> 
#include <stdio.h> 
#include <string.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <time.h> 
#include <unistd.h> 

/* Return a character string representing the current date and time.  */ 
char* get_timestamp () 
{
  time_t now = time (NULL); 
  return asctime (localtime (&now)); 
} 
 

int main (int argc, char* argv[]) 
{
  /* The file to which to append the timestamp.  */ 
  char* filename = argv[1]; 
  /* Get the current timestamp.  */ 
  char* timestamp = get_timestamp (); 
  /* Open the file for writing. If it exists, append to it; 
     otherwise, create a new file.
     Permissions are set in the new file with Unix style 0XXX
  */ 
  int fd = open (filename, O_WRONLY | O_CREAT | O_APPEND, 0666); 
  /* Compute the length of the timestamp string.  */ 
  size_t length = strlen (timestamp); 
  /* Write the timestamp to the file.  */ 
  write (fd, timestamp, length); 
  /* All done.  */ 
  close (fd); 
  return 0; 
} 
