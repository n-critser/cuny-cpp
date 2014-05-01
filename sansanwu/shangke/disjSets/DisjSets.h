/*******************************************************************************
  Title          : blank.h
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o 
  Modifications  : 
 
*******************************************************************************/
#ifndef DISJSETS_H
#define DISJSETS_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>


class DisjSets{
public:
        DisjSets(int);
        void unionS ( int, int);
        int find(int);
        void print();

private:
        std::vector<int> sets;

};
/* CLASS:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/



#endif /*Thats all*/
