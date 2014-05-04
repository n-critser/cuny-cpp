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
#include <sstream>
#include <string>


#include "Network.h"
/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


        const  int CMAX = 6;
        std::string commands[] ={"insert","remove","find","display","report","quit"};
        
        
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


         
         /* Test file stream before sending to controller  */
         if(!inFile){
                 std::cerr << "Valid File not found:  ** Exiting ** " << std::endl;
                 exit(1);
         }

         
         /*
           FIXME: INPUT TEST
           ----------------------------------
           parse the file without any manipulation. Either line by line
           or character by character or a mixture of the 2. 
          */
         try{
                 std::string str;
                 std::string command;
                 std::string Player1 ;
                 std::string Player2 ;
                 std::string exchange ;
                 Network players;
                 for (int i = 0; i < CMAX; i++)
                         std::cout<< "commands["<<i<<"]="<<commands[i]<<std::endl;
                 while (std::getline(inFile,str, '\n')) {
                         command= "-1";
                         Player1 = "-1";
                         Player2 = "-1";
                         exchange = "-1";
                         std::stringstream strin( str);
                         strin>> command;
                         strin >>Player1;
                         strin >>Player2;
                         strin >>exchange;
                         //players.insert(Player1);
                         //players.insert(Player2);
                         bool valid = false;
                         if (command == "data"){
                                 std::cout <<command
                                           <<"\n"
                                           <<"P1="<< Player1
                                           <<"\tP2="<<Player2
                                           <<"\texchange="<<exchange
                                           <<std::endl;
                                 players.add_connection(Player1,Player2,exchange);
                                 std::cout <<"valid="<<valid<<std::endl;
                         }else
                                 std::cout << "NO DATA FOUND" << std::endl;
                         
         
                 }
                 players.display();
                 players.show_cohorts();
         }catch (...){
                 std::cout << "Error Parsing File" << std::endl;
         }

         return 0;
}
