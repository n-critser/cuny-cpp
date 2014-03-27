/*******************************************************************************
  Title          : shellSort.cpp
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
#include <vector>

/*
  Shellsort, using Shell's original gap (gap/2) 


 */
template <typename Comp>
void shellsort( std::vector<Comp> & a){
        for ( int gap = a.size() / 2; gap > 0; gap/=2){
                for ( int i = gap; i < a.size(); i++){

                        Comp tmp = a[i];
                        int j= i;
                        for ( ; j >= gap && tmp < a[ j-gap ]; j-=gap){
                                a[j] = a[j-gap];
                        }
                        a[j]= tmp;
                }
        }
}


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


        std::vector<int> nums;
        
        for ( unsigned i = 999; i > 0; i--)
                nums.push_back(i);
        shellsort(nums);
        std::cout << "Vector after Shell Sort"<<std::endl;
        std::vector<int>::iterator it;
        for ( it = nums.begin() ; it != nums.end(); ++it)
                std::cout << ' ' << *it;
        std::cout << "\nDone Sorting"<< std::endl;
         

         return 0;
}
