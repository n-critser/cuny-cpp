/*
  file: vec_Sample.cpp
  description: shows an example of using vectors in c++
  ------------------------------------------------------
  usage:
        Compile with g++ -Wall vec_Sample.cpp -o vec_Sample
        $ ./vec_Sample
        
        For more stringent compilation use:
        g++ -Wall -Werror ...
        This will turn any warnings into errors that result in a failure
        to compile.

 */

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>

int main() {
        std::vector<int> sqrs( 100 );

        std::vector<std::string> names ( 100 );
        std::stringstream myString;
        //myString << "hello";
        /*
          vec_Sample.cpp: warning: comparison between signed and
          unsigned integer expressions [-Wsign-compare]
          ------------------------------------------------------
          sqrs.size() gives an unsigned integer value
          int i declares i as a signed integer
          ------------------------------------------------------
          solution : use unsigned i = 0; or unsigned int i = 0;
         */
        for ( int i = 0; i < sqrs.size(); i++ )
                sqrs[i] = i * i;

        for ( unsigned int i = 0; i < sqrs.size(); i++ )
                std::cout << i << " " << sqrs[i] << std::endl;
                

        for ( unsigned j = 0; j < names.size(); j++ ) {
                myString << "hello" << j;
                names[j] = myString.str();
                myString.flush();
         
        }
        for ( unsigned k = 0; k < names.size(); k++) {
                std::cout << names[k] << std::endl;
        }
        return 0;
}
