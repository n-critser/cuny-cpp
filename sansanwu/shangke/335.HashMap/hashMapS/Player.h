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
#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

class Player {
private:
        int hash_value;
        int unionS_index;
        int cohort_id;
        std::string phone_number;
        friend class Network;

public:
        Player();
        Player(std::string ph );
        bool operator== ( const Player & rhs ) const;
        bool operator!= (const Player & rhs ) const;

        void update_cohort_id( int );  
        const int get_cohort_id() const;
        const std::string get_phone_number() const ;
};

/*int hash( const Player & item ) {

        return hash( item.get_phone_number());
}
*/

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/



#endif /*Thats all*/
