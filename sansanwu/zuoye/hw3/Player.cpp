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

Player::Player(std::string ph) : phone_number(ph){
        cohort_id= -1;
        unionS_index=0;

}       

Player::Player(std::string ph , int us_index) : phone_number(ph){
        cohort_id= -1;
        unionS_index= us_index;

}       


bool Player::operator== ( const Player & rhs ) const{
        return rhs.get_phone_number() == phone_number;
}
bool Player::operator!= (const Player & rhs ) const{
        return rhs.get_phone_number() != phone_number;
}

void Player::update_cohort_id(int newID){
        cohort_id = newID;
}

const int Player::get_cohort_id() const{
        return cohort_id;
}


const int Player::get_u_index() const{
        std::cout << "ENTERING GET_U_INDEX"<<std::endl;
        return unionS_index;
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
