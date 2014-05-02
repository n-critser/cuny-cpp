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
#include "Player.h"

Player::Player(){}

Player::Player(std::string ph) : phone_number(ph){}       


bool Player::operator== ( const Player & rhs ) const{
        return rhs.get_phone_number() == phone_number;
}
bool Player::operator!= (const Player & rhs ) const{
        return rhs.get_phone_number() != phone_number;
}
        

const std::string Player::get_phone_number() const {
        return phone_number;
}

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/
