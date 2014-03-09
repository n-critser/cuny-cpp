/*******************************************************************************
  Title          : operators.cpp
  Author         : http://pic.dhe.ibm.com/infocenter/lnxpcomp/v121v141/index.jsp?topic=%2Fcom.ibm.xlcpp121.linux.doc%2Flanguage_ref%2Foverl.html 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o 
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>



class complx
{
      double real,
             imag;
public:
        complx( double real = 0., double imag = 0.); // constructor
        complx operator+(const complx&) const;       // operator+()
        void print();
};

// define constructor
complx::complx( double r, double i )
{
      real = r; imag = i;
}
void complx::print(){
        std::cout<< "real="<<real<<" "<<"imag="<<imag<<std::endl;
}
// define overloaded + (plus) operator
/* operator+
   -------------------------------
   usage:  complx c= a + b;  
   returns by value an instance created in the method
   often uses an implicit operator= in order to push the newly
   created value to an existing instance

 */
complx complx::operator+ (const complx& c) const
{
      complx result;
      result.real = (this->real + c.real);
      result.imag = (this->imag + c.imag);
      return result;
}


/* operator=
   --------------------
   usage: X a;  X b;   b = a; 
   returns a reference to the same type as rhs argument.

 */
struct X {
  int data;
  X& operator=(X& a) { return a; }
  X& operator=(int a) {
    data = a;
    return *this;
  }
};



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
         
        complx x(4,4);
        complx y(6,6);
        complx z = x + y; // calls complx::operator+()     
        z.print();
        X x1, x2;
        x1 = x2;      // call x1.operator=(x2)
        x1 = 5;       // call x1.operator=(5)         
        std::cout<<"x1="<<x1.data<<std::endl;

        
        return 0;
}
