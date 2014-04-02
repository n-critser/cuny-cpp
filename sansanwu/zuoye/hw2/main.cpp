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
//#define NDEBUG
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>

/* me   */

#include "EavlTree.h"



/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){
        

        /*REMOVE ASSERT WHEN DONE DEBUGGIN*/
        const  int CMAX = 7;
        std::string commands[] ={"assert","insert","remove","find","display","report","quit"};
        
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
         std::string command = "-1";
         std::string word = "-1";
         std::string overflow = "-1";

         
         while (std::getline(inFile,tree_string) ){
                 command= "-1";
                 word = "-1";
                 std::stringstream strin( tree_string);
                 strin>> command;
                 strin >>word;
                 bool valid = false;
                 /*COMPARE command  TO LIST OF VALID COMMAND STRINGS */
                 for ( int i = 0 ; i < CMAX; i ++){
                         if (command == commands[i])
                                 valid = true;        
                 }
                 if (valid != true){
                         std::cerr << "***ERROR: INVALID COMMAND STRING--SKIPPING***"<<std::endl;
                         std::cerr << "You Entered:" << command<<std::endl;
                         strin.clear();
                         continue;
                 }
                 //switch (command[0]){
                 if (command != "-1" && word == "-1"){
                         if (command == "quit"){
                                 //case 'q' :{ 
                                 std::cout<<"EXIT COMMAND GIVEN------>GOODBYE"<<std::endl;
                                 break;
                         }
                         else if  (command == "report"){
                                 eavl_strings.report();
                                 continue;
                         }
                         else if (command == "display"){
                                 std::cout<< eavl_strings<<std::endl;
                                 continue;
                         }
                 }
    
                 
                 if (word.length()>32){
                         std::cerr<< "***ERROR: EXCEDED WORD LENGTH***"<<std::endl;
                         word = "-1";
                         strin.clear();
                         continue;
                 }
                 strin >>overflow;
                 if ( overflow != "-1"){
                         std::cerr << "***ERROR: MALFORMED INPUT LINE***" << std::endl;
                         strin.clear();
                         overflow = "-1";
                         word = "-1";
                         continue;
                 }
                 if ( word == "-1"){
                         std::cerr << "***ERROR: INVALID INPUT- WORD NOT FOUND***"<<std::endl;
                        
                 }
                         
                 else if ((command == "insert" ) && (word != "-1")){
                         //std::cout << "Inserting word = "<<word<<std::endl;
                         eavl_strings.insert(word);
                 }
                 else if ((command == "remove" ) && (word != "-1")){
                         //std::cout << "word = "<<word<<std::endl;
                         eavl_strings.remove(word);
                 }
                 else if ((command == "find" ) && (word != "-1")){
                         eavl_strings.find(word, testFreq);
                 }
                 else if ((command == "assert") && (word != "-1")){
                         int eval = atoi(word.c_str());
                         std::cout << "Testing size["<<eavl_strings.size()<<"] : ["<<eval<<"]"<<std::endl;
                         assert (eavl_strings.size()== eval);                       
                 }
                  
                 word = "-1";

                 
         }
         
         
         
         try {
                 //std::cout << eavl_strings<< std::endl;
                 // std::cout<<std::endl;
                 // std::cout<< eavl_strings.find("skulls", testFreq)<<std::endl;
                 // std::cout<< eavl_strings.find("pants", testFreq)<<std::endl;
                 // std::cout<< eavl_strings.find("pants", testFreq)<<std::endl;
                 // std::cout<< eavl_strings.find("this", testFreq)<<std::endl;
                 // std::cout<< eavl_strings.find("hello", testFreq)<<std::endl;
                 
                 //eavl_strings.report();
                 
         } catch (...) {
                 std::cerr << "EXCEPTION MANIPULATING TREE";
         }
         
         return 0;
}
