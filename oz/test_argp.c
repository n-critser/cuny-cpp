/*******************************************************************************
  Title          : test_argp.c
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : testing argp for cli-arg parsing
  Usage          : ./EXECUTABLE
  Build with     : gxx -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/

#include <stdlib.h>
#include <argp.h>

const char *argp_program_version =
        "argp-ex2 1.0";
const char *argp_program_bug_address =
        "<bug-gnu-utils@gnu.org>";

/* program docs */
static char doc[] =
        "Argp example #2 minimal -- nothing but the barest";

/*
  example 2 from gnu.org.  all argp values are zero because we have no args.
  doc and bug address will be used for --help and --version
  */
static struct argp argp = { 0, 0 , 0, doc};

int main( int argc, char **argv){
        argp_parse( &argp, argc, argv, 0 , 0 , 0);
        exit(0);
}
