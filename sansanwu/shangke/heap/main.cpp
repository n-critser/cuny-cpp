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
#include "Heap.h"

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


	std::cout << "number of args =" << argc << std::endl;

        std::string addressFile="";
        Heap<int> intHeap;
        for ( int i = 16; i > 0; i--){
                 intHeap.insert(i);
        }
       
        intHeap.display();
        intHeap.heapify();
        intHeap.display();
        
	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.

	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
         */
         
         
         

         return 0;
}
