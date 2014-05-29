/*******************************************************************************
  Title          : test_exit.c
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : testing atexit and exit for a posix program
  Usage          : ./EXECUTABLE
  Build with     : gxx -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

void bye (void) {
        puts ("GOODBYE, CRUEL WORLD.....");
}

int main (void) {
        atexit(bye);
        exit(EXIT_SUCCESS);
}
