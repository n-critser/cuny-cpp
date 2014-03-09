/*
  .../335.Lists/main.cpp
  Author: n-critser
  1.2.2014

  bullshit!!!!!
  After messing with the Data-structures code for a long while i used code
  from:
  http://www.math.ucla.edu/~wittman/10a.1.10w/ccc/ch16/ch16.html
  Which actually works.

  Mark Weiss' code is trash!
  His template bullshit and awesome ideas are misleading ,
 
  Now i have to modify the good code to work with templates. But at least
  something works
 */
#include<iostream>
//#include "List.h"
#include <string>
#include "UCList.h"

// use this to make a simpler version
//http://www.math.ucla.edu/~wittman/10a.1.10w/ccc/ch16/ch16.html
int main(){

        std::string hi = "hellow World";
        UCList list;
        list.push_back(hi);
        list.push_back("what the fuck");
        list.push_back("this took soo long");

        Iterator pos;
        pos = list.begin();
        pos.next();
        for (pos = list.begin(); !pos.equals(list.end()); pos.next())
                std::cout << pos.get() << std::endl;
        return 0;
}
        



