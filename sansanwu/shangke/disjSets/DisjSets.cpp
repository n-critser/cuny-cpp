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
#include "DisjSets.h"



/* FUNCTION: DisjSets Constructor
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
*/
DisjSets::DisjSets( int numElements): sets(numElements) {

        for (unsigned i = 0; i < sets.size(); i++)
                sets[i] = -1;
}


/* FUNCTION: union
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION:
         Joins to subsets giving the larger subset lead and the smaller
         becoming a member of the larger. 

  
*/
void DisjSets::unionS ( int root1, int root2){
        if (root1 != root2) {
                if( sets[root2] < sets[root1]){
                        //root2 is deeper
                        std::cout <<"sets["<< root2<<"] < sets["
                                  << root1<<"]"<<std::endl;  
                        sets[root2]+= sets[root1];
                        sets[root1] = root2;
                } else {
                        //root1 is deeper
                        std::cout <<"sets["<< root1<<"]="<<sets[root1]<<" <= sets["
                                  << root2<<"]="<<sets[root2]<<std::endl;  
                        sets[root1]+= sets[root2];
                        sets[root2] = root1;
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
int DisjSets::find(int num ){
        if ( sets[num] < 0 )
                return num;
        else
                return sets[num] = find(sets[num]);

}

/* FUNCTION: print
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 
*/
void DisjSets::print(){
        for (unsigned i = 0; i < sets.size(); i++){
                std::cout<< "Sets["<<i<<"]="<<sets[i]<<std::endl;
        }     

}
