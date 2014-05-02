/*******************************************************************************
  Title          : HashTable.cpp
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
//#include <cassert>
#include <string>
//#include "HashTable.h"

template< class HashObj>
int  HashTable<HashObj>::myhash( const HashObj & x) const{
        int size = array.size();
        return hash (x,size);

}

template< class HashObj>
void HashTable<HashObj>:: makeEmpty(){
        currentSize = 0;
        for ( unsigned i = 0; i < array.size(); i++)
                array[ i ].info = EMPTY;
        
}


template< class HashObj>
int  HashTable<HashObj>:: nextPrime ( int num){
        std::cout << "ENTERING nextPrime FUNCTION" << std::endl;

        int temp = 1;
        temp= temp << num;
        temp -= 1;
        return temp;
}


template<class HashObj>
bool HashTable<HashObj> :: contains( const HashObj & x) const{
        return isActive( findPos( x ));
}



template<class HashObj>
int HashTable<HashObj>::findPos( const HashObj & x) const{
        std::cout << "ENTERING FINDPOS FUNCTION" << std::endl;
        int offset = 1;
        int currentPos = myhash( x );
        while ( array[currentPos].info != EMPTY &&
                array[currentPos].element != x ){
                currentPos += offset;  // iTh probe
                offset += 2;           // offset
                if ( currentPos >= (int)array.size() )
                        currentPos -= array.size();
        }
        return currentPos;
}

template<class HashObj>
bool HashTable<HashObj>:: isActive( int currentPos ) const{
        return array[currentPos].info == ACTIVE;
}


template<class HashObj>
bool HashTable<HashObj>::insert ( const HashObj & x){
        std::cout<< "Entering insert function" << std::endl;
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
                return false;
        
        array[currentPos] = HashEntry(x,ACTIVE);
        int half = array.size()/2;
        if( ++currentSize > half ) //Test if the array is over half full
                rehash();                    //rehash the table with the new value
        return true;
}


template<class HashObj>
void HashTable<HashObj>::rehash() {
        std::cout<< "Entering rehash function\n"
                 << "TEST-ME: "<< std::endl;
        std::vector<HashEntry> oldArray = array;
        array.resize( nextPrime( 2* oldArray.size()));
        for( unsigned j = 0; j < array.size(); j++)
                array[j].info = EMPTY;
        currentSize=0;
        for ( unsigned i = 0; i < oldArray.size(); i++){
                if( oldArray[i].info == ACTIVE )
                        insert( oldArray[i].element);
        }
        

}

template<class HashObj>
bool HashTable<HashObj>::remove ( const HashObj & x){
        int currentPos = findPos( x );
        if( !isActive( currentPos ))
                return false;

        array[currentPos].info = DELETED;
        return true;
}

template<class HashObj>
void HashTable<HashObj>::printTable(){
        //std::vector<HashTable<HashObj>::HashEntry>::iterator it;
        //it=array.begin();
        //for( ; it<array.end(); it++)
        //       std::cout<< (*it).element << std::endl;
        for (unsigned i= 0; i < array.size(); i++)
                if( array[i].info == ACTIVE){
                        
                        std::cout<<"TablePos["<<i<<"]="<< array[i].element<<std::endl;
                }
}

template<class HashObj>
int HashTable<HashObj>::hash( const std::string & key, int tableSize ){

        int hashVal =0 ;
        for ( unsigned i = 0; i < key.length(); i++)
                hashVal = 37 * hashVal + key[i];
        hashVal %= tableSize;
        if( hashVal < 0 )
                hashVal += tableSize;
        return hashVal;
}

template<class HashObj>
int HashTable<HashObj>::hash ( int key , int tableSize) {
        //int tableSize = array.size();
        return key %=tableSize;
}

template<class HashObj>
int HashTable<HashObj>::hash( const Player& pl , int tableSize){
        return hash( pl.get_phone_number(),tableSize);

}
