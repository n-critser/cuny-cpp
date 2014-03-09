/*
  File: intCell.cpp
  Description:  Code for a simple class taken from MAW C++ DAta and Algs 

  Usage:
        Compile with g++ -Wall intCell.cpp -o intCell
        $ ./intCell 
        25


 */

#include <iostream>
#include <cstdlib>

class intCell {
public:
        explicit intCell (int initialValue = 0) :
                storedValue ( initialValue ) {}

        /*
          method: read()
          ------------------
          example of an accessor method because it doesn't
          do any harm to the state of the storedValue variable.
          this is achieved by the keyword "const"
         */
        int read() const {
                return storedValue;
        }

        void write ( int x) {
                storedValue = x;
        }

private:
        int storedValue;
};

int main() {
        intCell x ( 25);
        std::cout << x.read() << std::endl;

        return 0;
}
