/*******************************************************************************
  Project        : HW-1-335
  File           : main.cpp
  Author         : n-critser (Nick Critser)
  Created on     : 2/24/14
  Description    : Polynomial output and evaluation program 
  Purpose        : Test file parsing and I/O
  Usage          : ./hw1 <testfile>
  Build with     : make all
  Modifications  : BROKEN !!! NEEDS TO TAKE EXTRA SPACING INTO ACCOUNT!!!!
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
//#include <cassert>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
//#include <algorithm>
#include <sstream>
#include "Poly.h"

/*Tokenizing   */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);


/*
 * void controller( std::ofstream input):
 ******************************************
 * usage: controller(inFile);
 * See function definition for complete comments
 */
void controller ( std::ifstream& );




/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


	//std::cout << "number of args =" << argc << std::endl;
        char* argFile;


	
	/* If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 */
	 if (argc < 2) {
                 std::cerr << "Argument File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
         argFile= argv[1];
         std::ifstream inFile;
         inFile.open(argFile); 

         /* Test file stream before sending to controller  */
         if(!inFile){
                 std::cout << "Valid File not found:  ** Exiting ** " << std::endl;
                 exit(1);
         }

         /* Call controller(ifstream) to begin parsing file  */
         controller(inFile);
         std::cout << "Exiting Program"<<std::endl;
         return 0;
}


/* Function: controller
   -----------------------------------------
   usage: controller(<input-file-stream>);
   Accepts an input filestream as only argument.  Creates a vector of
   Poly(polynomial class) pointers. Also creates an iterator of the
   same type and proceeds to parse the input filestream based on
   relavent functionality. Controller will accept input of
   polynomials, as direct polynomial terms or as a mulitiple of 2 Polys.
   Controller will also act upon the appropriate polynomail with 2 commands
   show :  displays the polynomial ex. 2x^2+5x+1
   eval :  evaluates the polynomail with the supplied argument
 */
void controller (std::ifstream& input){

        std::vector<Poly*> polys(100);
        std::vector<Poly*>::iterator polyIt;


        /*set default value for each Poly* in polys to NULL  */
        for ( polyIt=polys.begin(); polyIt!=polys.end();polyIt++){
                (*polyIt)=NULL;
        }
/****************************************
 * Build the full vector of Polynomials from the file
 ***********************************************/
	try {
		std::string str;
                std::vector<std::string>data;
		while(std::getline(input, str, '\n'))	{
                        const char *cStr = str.c_str();
                        /* check for command or not */
                        if(isdigit(cStr[0])){
                                polyIt= polys.begin();
                                int polyPos=-1;
                                try{
                                        data = split(str, ' '); // splitting on whitespace 
                                        std::cout << "length of data= " << data.size()<< std::endl;
                                }catch(...){
                                        std::cout << "\nExeption thrown splitting string";
                                        std::cout<< "\nError Occured IN: "+str;
                                }
                                
                                polyPos= atoi(data[0].c_str());
                                std::string op_string = data[1];
                                std::cout<<  op_string << std::endl;
                                char oper= data[1][0];
                                int count=0,coeff=0,exp=-1;
                                Poly *add = new Poly();
                                /* Regular Polynomial building below.  
                                  
                                  
                                 */
                                if (oper==':'){
                                        for (unsigned i =2; i < data.size(); i++){
                                                if (count==0){
                                                        coeff= atoi(data[i].c_str());
                                                } else if( count==1){
                                                        exp=  atoi(data[i].c_str());
                                                }
                                                std::cout << "coeff =" << coeff << "expo= " << exp << std::endl;
                                                count++;
                                                if (count>=2){
                                                        add->push_term(coeff,exp);
                                                        count=0;
                                                }
                                        }
                                }

                                /* Multiplication for 2 polynomials Below.   */
                                else if (oper=='='){
                                        int poly1= atoi(data[2].c_str());
                                        int poly2= atoi(data[4].c_str());
                                        if (polys[poly1]==NULL || polys[poly2]==NULL)
                                                throw "ERROR: INVALID POLY VECTOR INDEX";
                                        add = ((*(polys[poly1]))) * (*(polys[poly2]));
                                        polys[polyPos]=add;
                                }
                                /*USE INDEX TO PLACE POLY INTO POSITION */
                                polys[polyPos]=add;
                               
                        } else {
                                /* Command Section: Split strings then execute operations
                                   based on 2 possibilities:
                                   show and eval 

                                 */

                                try{
                                        data = split(str, ' '); // splitting on whitespace 
                                }catch(...){
                                        std::cout << "\nExeption thrown splitting string";
                                        std::cout << "\nError Occured IN: "+str;
                                }
                                /*variables for switching behavior */
                                std::string command= data[0];
                                /*   */
                                enum com_Choice{show, eval} commands;
                                int operand= atoi(data[1].c_str());
                                int value= atoi(data[2].c_str());
                              
                                                             
                                if (command == "eval"){
                                        commands = eval;      
                                }else
                                        commands = show;
                                
                                switch (commands ) {
                                   
                                case show:
                                         std::cout << "Poly["<<operand<<"]="
                                                   << (*polys[operand])<<std::endl;
                                        break;
                                case eval:
                                        
                                        int result= (*polys[operand])(value );
                                        std::cout << "Poly["<<operand<<"]("<<value<<")="
                                                  <<result<< std::endl;
                                        break;
                                
                                }
                        }
                        
                        data.clear();
                        str.clear();
			
                }
        } catch(...){
		std::cout << "\nError Parsing input File:\n " << std::endl;
	}
        
}
/********************************************
 * End of List input to Controller
 *******************************************/



/*
  Tokenize into a string vector ?
  Why not tokenize into an int vector or even just build the polynomials in the tokenizer?
 */
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    std::cout << "item in split = " << item << std::endl;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
