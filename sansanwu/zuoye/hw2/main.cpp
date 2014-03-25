/*******************************************************************************
  Title          : main.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o main main.cpp 
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <fstream>

/* me   */
#include "Logger.h"
#include "EavlTree.h"
/*
 * ********************************
 * usage:  write_Log("string");
 * 		   write_Log(convertDigit(number));
 */


debug::Logger log("Trees", "main.debug") ;
/* Log file  
 ***************************************************
 * usage: <log-name> << debug::Logger::DEBUG << " char* or string\n";
 * Change the type of Log 3 possible choices 
 *  {DEBUG, WARNING, INFO }  
 */

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){
        log << debug::Logger::DEBUG << "\nDebug-Log: Line 1!";

        char * argFile;
        std::ifstream inFile;
        
	std::cout << "number of args =" << argc << std::endl;
        std::string addressFile="";

	/* THIS SECTION IS FOR FILE INPUT
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the
         */
	 if (argc < 2) {
                 std::cerr << "Address File not Found";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
    

        argFile= argv[1];
        inFile.open(argFile);

          /* Test file stream before sending to controller  */
         if(!inFile){
                 std::cerr << "Valid File not found:  ** Exiting ** " << std::endl;
                 exit(1);
         }



         
        EavlTree<std::string> eavl_strings( "NOT-FOUND");
        std::string tree_string="";
        int testFreq = 0;
        while (inFile >> tree_string){
                std::cout <<"string1="<< tree_string<<"\t";
                inFile>>tree_string;
                std::cout <<"string2="<<tree_string<<std::endl;
                eavl_strings.insert(tree_string);
                // tree_string="";
        }
        try {
                std::cout << eavl_strings;
                std::cout<< eavl_strings.find("pants", testFreq);
               
        } catch (...) {
                std::cerr << "EXCEPTION MANIPULATING TREE";
        }
        
         return 0;
}
