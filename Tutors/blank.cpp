/*******************************************************************************
  Title          : blank.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <time.h>
time_t start,end;






/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){

        time(&start);
	std::cout << "number of args =" << argc << std::endl;

        std::string addressFile="";

	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 */
	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }

         
         
         
         time(&end);
         double dif = difftime (end,start);
         std::cout << "elapsed time" << dif << std::endl;
         return 0;
}
