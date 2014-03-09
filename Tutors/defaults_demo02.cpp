/*******************************************************************************
  Title          : defaults_demo02.cpp
  Author         : Stewart Weiss
  Created on     : January 12, 2014
  Description    : Shows semantics of default arguments 
  Purpose        : To show what you could do but should not do 
  Usage          : defaults_demo02 
  Build with     : g++ -o defaults_demo02  defaults_demo02.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>

// This function declares f initially with no defaults, then adds them one
// at a time. It shows that you can add defaults after calling the function.
void m() {
    void f(int, int);     // has no defaults
    f(4,3);               //
    void f(int, int = 5); // OK: it adds a default to second parameter
    f(4);                 // OK, calls f(4, 5);
    // It would be incorrect to do the following because it redefines default
    // void f(int, int = 5 );
    void f(int=1, int );  // OK: it adds the default to first parameter
    f(6);
}

// Need a definition for f(). This just prints the values of the arguments.
void f(int a, int b)
{
    std::cout << a << " " << b << "\n";
}


int main()
{
    m();
    return 0; 
}
