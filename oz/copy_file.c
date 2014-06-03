/*******************************************************************************
  Title          : copy_file.c
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : copy an existing file to another file on-line using user args
                   if <out_file> already exists error is thrown and file must
                   be rmove.  Otherwise <in_file> is copied to <out_file> and the
                   program terminates when 0 bytes are being read from the file. 
  Usage          : ./EXECUTABLE
  Build with     : gxx -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/

#include <fcntl.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <time.h>
#include <string.h> 

/* Return a character string representing the current date and time.  */ 
char* get_timestamp () 
{
  time_t now = time (NULL); 
  return asctime (localtime (&now)); 
} 


int main( int argc, char *argv[]){


        /* The path at which to create the new file.  */ 
        char* path = argv[1];
        char* out = "COPY.txt";

        size_t bytes_read=-1;

        char* buffer[128];
          /* Get the current timestamp.  */ 
        char* timestamp = get_timestamp ();
        /* Compute the length of the timestamp string.  */ 
        size_t length = strlen (timestamp); 

        
        /* The permissions for the new file.  */ 
        mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; 
        
        /* Create the file.  */ 
        int fd_in = open (path, O_RDONLY | O_EXCL );
        int fd_out = open (out, O_WRONLY | O_EXCL | O_APPEND | O_CREAT, mode);
        if ((fd_in == -1) ||  (fd_out == -1)) {
                /* An error occurred. Print an error message and bail.  */ 
                perror ("error opening file"); 
                return -1; 
        } else {
                while (bytes_read != 0){
                        write(fd_out,timestamp, length);
                        bytes_read = read ( fd_in, buffer, sizeof(buffer));
                        write(fd_out,buffer,bytes_read);
                }
        }
        close (fd_in);
        close (fd_out);
        
        
        return 0;
          
}
