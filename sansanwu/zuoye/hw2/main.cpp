/*******************************************************************************
  Title          : main.cpp
  Author         : N-Critser
  Created on     : 4-06-2014
  Description    : main.cpp for HW2 project
  Purpose        : see above
  Usage          : ./EXECUTABLE INPUT.TXT
  Build with     : g++ -o hw2 main.cpp 
  References     :
                 : 1: Stewart Weiss :
                 :    [http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/csci335/csci335_s14.php]
                 : 2: Mark Allen Weiss   :
                 :    [ Data Structures and Algorithm Analysis in C++ 3rd Edition]

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
        const  int CMAX = 6;
        std::string commands[] ={"insert","remove","find","display","report","quit"};
        
        char * argFile;
        std::ifstream inFile;
        std::string addressFile="";

	/* THIS SECTION IS FOR FILE INPUT
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the
         */
	 if (argc < 2) {
                 std::cerr << "***ERROR: INPUT FILE NOT FOUND"<<std::endl;
                 std::cerr << "Program Usage:  " << argv[0] << " filename.txt" << std::endl;
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
         std::string command;
         std::string word ;
         std::string overflow ;

         try {
         while (std::getline(inFile,tree_string) ){
                 command= "-1";
                 word = "-1";
                 overflow = "-1";
                 std::stringstream strin( tree_string);
                 strin>> command;
                 strin >>word;
                 strin >>overflow;
                 bool valid = false;
                 /*COMPARE command  TO LIST OF VALID COMMAND STRINGS */
                 for ( int i = 0 ; i < CMAX; i ++){
                         if (command == commands[i])
                                 valid = true;        
                 }
                 if (valid != true){
                         std::cerr << "***ERROR: INVALID COMMAND STRING--SKIPPING***"<<std::endl;
                         //std::cerr << "You Entered:" << command<<std::endl;
                         strin.clear();
                         continue;
                 }
                 /*DENY INPUT IF OVERFLOW FLAG HAS A VALUE OTHER THAN "-1"*/
                 if ( overflow != "-1"){
                         std::cerr << "***ERROR: MALFORMED INPUT LINE***" << std::endl;
                         strin.clear();
                         //throw -1;
                         //overflow = "-1";
                         // word = "-1";
                         continue;
                 }
                 /*ALL SINGLE INPUT LINE COMMAND ARE HERE*/
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
                                 //std::cout<< eavl_strings<<std::endl;
                                 eavl_strings.display(std::cout);
                                 continue;
                         }
                 }
    
                 /*TEST THE LENGTH OF THE INPUT WORD BEFORE ALLOWING THE COMMAND*/
                 if (word.length()>32){
                         std::cerr<< "***ERROR: EXCEDED WORD LENGTH***"<<std::endl;
                         //word = "-1";
                         strin.clear();
                         continue;
                 }

                 /*A WORD IS NEEDED FOR ALL COMMANDS BELOW  */
                 if ( word == "-1"){
                         std::cerr << "***ERROR: INVALID INPUT- WORD NOT FOUND***"<<std::endl;
                         strin.clear();
                         continue;
                        
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

                        
           
         }
         
   
         } catch (...) {
                 std::cerr << "***EXCEPTION THROWN PROCESSING FILE***"<<std::endl;
                 
         }
         
         
         

         return 0;
}
