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

	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
        */
        /*       
          int n;

  std::cout << "Enter a number: ";
  std::cin >> n;
  std::cout << "You have entered: " << n << '\n';

  std::cout << "Enter a hexadecimal number: ";
  std::cin >> std::hex >> n;         // manipulator
  std::cout << "Its decimal equivalent is: " << n << '\n';
  std::cin.clear();
        */ 
          std::cout << "Please, enter a number or a word: ";
          char c = std::cin.peek();
          std::cout << "c="<<c<<std::endl;
          if ( (c >= '0') && (c <= '9') )
          {
                  int n;
                  std::cin >> n;
                  std::cout << "You entered the number: " << n << '\n';
          }
          else
          {
                  std::string str;
                  std::getline (std::cin, str);
                  std::cout << "You entered the word: " << str << '\n';
          }
          
          time(&end);
          double dif = difftime (end,start);
          std::cout << "elapsed time" << dif << std::endl;
          return 0;
}
