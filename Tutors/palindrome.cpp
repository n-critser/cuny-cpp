/*******************************************************************************
  Title          : blank.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o palindrome   palindrome.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>


/*
  Palindromes have some interesting characteristics. Often the partition
  character is only used once   racecar.  it only needs to be tested from
  one side to the midpoint    , and the other side to the midpoint
  

  
 */

bool palindrome_brute ( std::string );
bool palindrome_str (std::string);
bool palindrome_rec (std::string, int front, int back);

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
	 */
	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
         bool test0 = palindrome_brute("mom");
         std::cout << "palindrome brute:"<< test0 << std::endl;

         std::string test = "racecar";
         int test_l = test.length();
         bool test2 = palindrome_str("racecar");
         std::cout << "palindrome str:"<< test2 << std::endl;
         
         bool test3 = palindrome_rec(test, 0, test_l-1);
         std::cout << "palindrome_rec3:"<< test3 << std::endl;

         return 0;
}

bool palindrome_brute ( std::string  input){
        char front;
        char back;
        
        for ( unsigned i = 0, j = input.length()-1; i < input.length(); i++, j--){
                
                front = input[i];
                back = input[j];
                std::cout << "i="<<i<< " "<<"j="<<j<<std::endl;

                std::cout << "front="<<front<< " "<<"back="<<back<<std::endl;
                if (front != back)
                        return false;
        }
        return true;
}


bool palindrome_str (std::string input){
        unsigned half = input.length()/2;
        std::cout<< "middle of length of input: "<<half<<std::endl;
        std::string sub1 = input.substr(0,half-1);
        std::cout<< "middle of length of input: "<<half<<std::endl;
        std::string sub2 = input.substr(half+2,half-1);
        std::cout << sub1<<std::endl;
        std::cout << sub2<<std::endl;
        std::string sub3="";
        for (std::string::reverse_iterator rit=sub2.rbegin(); rit!=sub2.rend(); ++rit){
                std::cout << *rit;
                //char x = *rit;
                //sub3.append(rit);
        }
        
        return (sub1 == sub3);
}

bool palindrome_rec (std::string input, int front, int back){

        std::cout << "input" << input << std::endl;
        std::cout << "front" << front << std::endl;
        std::cout << "back" << back  << std::endl;
        
        if( front == back)
                return true;
        std::cout <<input[front] << input[back]<< std::endl;
        if( input[front++] == input[back--]){
               
                return palindrome_rec(input, front, back);
                
        }
                //else
        // return false;

}
