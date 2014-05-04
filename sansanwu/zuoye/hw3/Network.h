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
#include "sMap.h"
#include "Player.h"

// gdb --annotate=3 hw3  test/data_test.txt 

class Cohort {
public:
        Cohort()
                : id(0)
        {}
        Cohort(int newID)
                : id(id){}
        Cohort& operator+(Cohort& rhs){ id = id + rhs.id; return *this;}
        bool operator<(Cohort& rhs){ return id < rhs.id;} 
        int id;
        void set_id( int newID){ std::cout << "this->id= "<<this->id<< std::endl; this->id = newID;}
        
private:
        
        int size;

};
//Cohort& Cohort::operator+ (Cohort& rhs){ id= id + rhs.id; return *this;}
//bool Cohort::operator< (Cohort& rhs){ return id < rhs.id;} 

class Network {
public:
        Network();
        void insert ( std::string ph_num );
        void add_connection( const std::string p1, const std::string p2, const std::string  amount);
        void display ();

         void show_cohorts();

        std::string  find( const std::string phone);
        std::string  members( const int co_ID );

        std::string cohort_ids ();

        std::string info( const int co_ID );
        
        /*returns one of two
          max ( size ) -> biggest cohort or max
          or
          max (activity) -> most active cohort
         */
        std::string  max ( const std::string ) ;
        
private:
        int pCount;        
        sMap<Player*> mem_hash;
        Player* pIn;
        void addPlayer( const std::string  p_phone );


        /*UNION FIND OPERATIONS FOR THE NETWORK  */
        std::vector<Cohort > sets;
        void unionS ( int root1, int root2) ;
        int find_union( int num );

       

        


        

};

/* METHOD:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/



#endif /*Thats all*/
