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


#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>
#include "Network.h"

Network::Network(){}

void Network::insert( std::string ph_num ){
        members.push_back (ph_num );

}

void Network::display(){
        for (unsigned i = 0; i < members.size(); i++){

                std::cout <<members[i].phone_number<<std::endl;
        }

}

void Network::addPlayer( const Player &pl){
        mem_hash.insert( pl);

}

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/




