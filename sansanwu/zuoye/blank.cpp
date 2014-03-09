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
#include <fstream>
#include <string>

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


	std::cout << "number of args =" << argc << std::endl;

        //std::string addressFile="";

        char *argFile;
	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 */
	 if (argc < 2) {
                 std::cerr << "Argument File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }

         /* argFile is set to the file from the command line
            Then an input stream is declared with name = inFile
            inFile is opened with inFile.open(argFile)
            Now infile can read the bytes found in argFile

          */
         argFile=argv[1];
         std::ifstream inFile;
         inFile.open(argFile);

         /*
           FIXME: INPUT TEST
           ----------------------------------
           parse the file without any manipulation. Either line by line
           or character by character or a mixture of the 2. 
          */
         try{
                 std::string str;
                 
                 while (std::getline(inFile,str, '\n')) {
                         std::cout << str<<std::endl;
         
                 }
         }catch (...){
                 std::cout << "Error Parsing File" << std::endl;
         }

         return 0;
}
