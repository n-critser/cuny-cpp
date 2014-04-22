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


#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cstdlib>
//#include <cassert>
#include <string>
#include <vector>

template <class HashObj>
class HashTable{
public:
        explicit HashTable ( int size = 101)
                : array ( nextPrime ( size ) ){ makeEmpty();}

        bool contains( const HashObj & x) const;

        void makeEmpty();
        bool insert ( const HashObj & x);
        bool remove ( const HashObj & x);
        void printTable();
        
        enum EntryType { ACTIVE, EMPTY, DELETED };
private:
        struct HashEntry{
                HashObj element;
                EntryType info;
                HashEntry( const HashObj & elem = HashObj(), EntryType i = EMPTY )
                : element( elem ), info ( i ) {}
        };
        int nextPrime( int ); 
        std::vector < HashEntry > array; // Separated Chaining hash table
        int currentSize;


        bool isActive( int currentPos ) const;
        int findPos( const HashObj & x) const;
        void rehash();
        int myhash( const HashObj & x) const;
        

};



int hash( const std::string & key, int  );
int hash( int key, int );




#include "HashTable.cpp"

#endif /*Thats all*/
