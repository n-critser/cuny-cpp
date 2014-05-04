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

Network::Network()
        : sets(5000){}

void Network::insert( std::string ph_num ){
        // members.push_back (ph_num );
        std::cout << "FIXME OR GET RID OF ME" << std::endl;

}


void Network::add_connection( const std::string p1, const std::string p2, const std::string amount){
        // FIXME: ERROR TEST sMAP ENTRY
        //if( (mem_hash.get(p1) !=NULL) && (mem_hash.get(p2) != NULL) then
        // pCount should be incremented for each added player use this for the DisjSet position
        // need to check it they are already in the hashtable
        std::cout << "ENTERING add_connection"<<std::endl;
        int exAmount = (atoi(amount.c_str())); 
        Player* player1= NULL;
        Player* player2= NULL;

        //Cohort* cohort1= NULL;
        // Cohort* cohort2= NULL;
                
        
        if ( mem_hash.containsKey(p1) && mem_hash.containsKey(p2) ){
                std::cout << "BOTH PLAYERS ALREADY IN HASHTABLE"<< std::endl;
                player1 = mem_hash.get(p1);
                player2 = mem_hash.get(p2);
                
        } else if ( mem_hash.containsKey(p1) ){
                std::cout << "player1 ALREADY IN HASHTABLE"<< std::endl;
                player1 = mem_hash.get(p1);
                player2 = new Player(p2,pCount++);
                mem_hash.put(p2,player2);
                
        } else if (  mem_hash.containsKey(p2) ){
                std::cout << "player2 ALREADY IN HASHTABLE"<< std::endl;
                player1 = new Player(p1,pCount++);
                player2 =mem_hash.get(p2);
                mem_hash.put(p1,player1);

        }else {
                std::cout << "neither player ALREADY IN HASHTABLE"<< std::endl;
                player1 = new Player(p1,pCount++);
                player2 = new Player(p2,pCount++);
                mem_hash.put(p1,player1);
                mem_hash.put(p2,player2);
                
        }

        
        if ((player1 != NULL) && (player2 != NULL)){
                std::cout << "Amount of Exchange ="<<exAmount<<std::endl;
                int p1SetIndex = player1->get_u_index();
                int p2SetIndex = player2->get_u_index();
                int p1CoId = player1->get_cohort_id();
                int p2CoId = player2->get_cohort_id();
                std::cout <<"p1index="<< p1SetIndex<< std::endl;
                std::cout <<"p2index="<< p2SetIndex<<std::endl;
                std::cout <<"p1CoId=" << p1CoId<<std::endl;
                std::cout <<"p2CoId=" << p2CoId<<std::endl;
                sets[player1->unionS_index].set_id(player1->cohort_id) ;
                sets[player2->unionS_index].set_id( player2->cohort_id) ;
                unionS(p1SetIndex, p2SetIndex);
        }
        else
                std::cout<< "PLAYER1 AND/OR PLAYER2 EQUAL TO NULL" <<std::endl;

        player1 = NULL;
        player2 = NULL;
        delete player1;
        delete player2;

}

/* FUNCTION: union
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION:
         Joins to subsets giving the larger subset lead and the smaller
         becoming a member of the larger. 

  
*/
void Network::unionS ( int root1, int root2){
        std::cout << "ENTERING unionS"<<std::endl;
        std::cout << "Root1="<<root1<<std::endl;
        std::cout << "Root2="<<root2<<std::endl;
        if (root1 != root2) {
                if( sets[root2].id < sets[root1].id){
                        std::cout << "ENTERING r2 < r1"<<std::endl;

                        //root2 is deeper
                        sets[root2].set_id( sets[root2].id+ sets[root1].id);
                        sets[root1].set_id(root2);
                } else {
                        std::cout << "ENTERING r1 < r2"<<std::endl;
 
                        //root1 is deeper
                        sets[root1].set_id(sets[root1].id +sets[root2].id);
                        sets[root2].set_id(root1);
                }
        }
}


/* FUNCTION: find
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 
        Recursive find with path compression. Once the root of the
        set is found each successive member from the call stack is
        set to that roots value.
  
*/
int Network::find_union(int num ){

        std::cout << "ENTERING FIND_UNION"<<std::endl;
        if ( sets[num].id < 0 )
                return sets[num].id;
        else
                return sets[num].id = find_union(sets[num].id);

}

void Network::show_cohorts(){
        for (int i = 0; i < pCount; i++){
                std::cout<< "sets["<<i<<"]="<<sets[i].id << std::endl;
        }

}

void Network::display(){
        mem_hash.mapAll();
        /*
        for (unsigned i = 0; i < members.size(); i++){

                std::cout <<members[i].phone_number<<std::endl;
        }
        */

}

void Network::addPlayer( const std::string p_phone){
        
        int unionS_index = 2;
        pIn = new Player(p_phone);//(p_phone,unionS_index);
        pIn->update_cohort_id(unionS_index);
        mem_hash.put(p_phone, pIn );

}

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/




