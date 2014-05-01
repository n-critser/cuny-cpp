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
#include "HashTable.h"
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

        HashTable<std::string> table;
        table.insert( "555-212-6666");
        table.printTable();
        table.insert( "555-213-6565");
        table.insert( "555-223-6565");
        table.insert( "454-223-6565");
        table.insert( "454-671-1233");
        table.insert( "546-333-1111");
        table.insert( "555-214-6565");
        table.insert( "555-225-6565");
        table.insert( "454-226-6565");
        table.insert( "454-677-1233");
        table.insert( "546-338-1111");
        
        table.printTable();
         
         
         

         return 0;
}
