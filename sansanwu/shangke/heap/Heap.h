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
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>

template <class Comp>
class Heap;

#define MAX 100
template <class Comp> 
class Heap {

private:
        Comp hArray[MAX];
        int currentSize;
        bool isEmpty(){return currentSize <=0;}
        void percolateDown( int hole );
        

public:
Heap() : currentSize(0) {};
               
        void insert ( const Comp & x);
        void heapify() { for (int i = currentSize/2; i >= 0; i--) percolateDown(i);}
        bool isFull () { return currentSize == MAX;}
        void display () ;
        void deleteMin();

};

template<class Comp>
void Heap<Comp>::deleteMin(){
        if (isEmpty())
                throw -1;
        hArray[1] = hArray [ currentSize--];
        percolateDown(1);

}
template<class Comp>
void Heap<Comp>::display(){
        for (int i =1 ; i <= currentSize; i++)
                std::cout<< hArray[i] << std::endl;

}

template<class Comp>
void Heap<Comp>::percolateDown(int hole){
        int child;
        Comp tmp = hArray[hole];
        for ( ; hole * 2 <= currentSize; ){  //2i 
                child = hole *2;           //2i+1 
                if ( child != currentSize && hArray[child+1] < hArray[child])
                        child++;
                if( hArray[child] < tmp )
                        hArray[ hole ] = hArray[ child ] ;
                else
                        break;
                hole = child;
        }
        hArray[hole] = tmp;
}

template<class Comp>
void Heap<Comp>::insert(const Comp & x){
        if ( isFull() )
                throw -1;//Overflow();

        //percolate up
        int hole = ++currentSize;
        for ( ; hole > 1 && hArray[ hole/2 ]; hole /=2)
                hArray[hole] = hArray[hole/2];
        hArray[hole] = x;
        
}



#endif /*Thats all*/
