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
#include "DisjSets.h"

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


	std::cout << "number of args =" << argc << std::endl;

        std::string addressFile="";

	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 
	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
          */


        DisjSets numbers(20);

        numbers.unionS(numbers.find(1),numbers.find(6));
        numbers.unionS(numbers.find(3),numbers.find(4));
        numbers.unionS(numbers.find(1),numbers.find(9));
        numbers.unionS(numbers.find(1),numbers.find(5));
        numbers.unionS(numbers.find(6),numbers.find(5));

        numbers.unionS(numbers.find(4),numbers.find(5));
        numbers.unionS(numbers.find(7),numbers.find(5));
        numbers.unionS(numbers.find(8),numbers.find(17));
        numbers.unionS(numbers.find(8),numbers.find(16));
        numbers.unionS(numbers.find(8),numbers.find(15));
        numbers.unionS(numbers.find(8),numbers.find(0));
        numbers.unionS(numbers.find(8),numbers.find(3));
        numbers.print();
 /* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */

         
         
         

         return 0;
}
