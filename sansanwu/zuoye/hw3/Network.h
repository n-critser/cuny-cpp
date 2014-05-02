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
#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
#include "HashTable.h"
#include "Player.h"

class Network {
public:
        Network();
        void insert ( std::string ph_num );
        void display ();
private:
        std::vector<Player> members;
        HashTable<Player> mem_hash;
        void addPlayer(const  Player & pl );

};

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/



#endif /*Thats all*/
