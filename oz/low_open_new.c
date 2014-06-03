/*******************************************************************************
  Title          : low_open_new.c
  Author         : http://publib.boulder.ibm.com/infocenter/iseries/v5r3/index.jsp?topic=%2Fapis%2Fread.htm
  Created on     : 
  Description    : low level file creation and fill using c library unix api
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : gxx -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
main() {
  int ret, file_descriptor, rc;
  char buf[]="Test text";

  if ((file_descriptor = create("test.output", S_IWUSR))!= 0)
     perror("creat() error");
  else {
          if (-1==(rc=write(file_descriptor, buf, strlen(buf))))
                  perror("write() error");
          if (close(file_descriptor)!= 0)
                  perror("close() error");
  }

  if ((file_descriptor = open("test.output", O_RDONLY)) < 0)
    perror("open() error");
  else {
          ret = read(file_descriptor, buf, sizeof(buf)-1);
          buf[ret] = 0x00;
          printf("block read: \n <%s>  ", buf);
    if (close(file_descriptor)!= 0)
       perror("close() error");
  }
  if (unlink("test.output")!= 0)
     perror("unlink() error");
}
