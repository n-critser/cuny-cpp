/*******************************************************************************
  Title          : heapSort.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o heapSort  heapSort.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <vector>



template <class Comp>
void percolateDown( std::vector<Comp> & array , int hole, int last){
        int child;
        Comp tmp = array[ hole ];
        
        while ( hole * 2+1 < last ){
                child = hole * 2+1; //change to bit shift
                std::cout<<"INITIAL VALUES"
                         <<"array["<<hole <<"]="<<array[hole]
                         << ","<<"leftChild["<<child<<"]= "<<array[child]
                         << ","<<"rightChild["<<child+1<<"]= "<<array[child+1]<<std::endl;
                if ( child != last-1 && array[child+1] > array[child])
                        child++;
                if( array[child] > tmp ){
                        array[hole] = array[child];
                        /*       
                          std::cout<< "TMP SWAPPED WITH CHILD \n"
                           << "array["<<hole <<"]="<<array[child]<<std::endl; 
                        */
               
                }
                else
                        break;
                hole = child;               
        }
        array[ hole ] = tmp;
        std::cout<< "Final Value of Hole\n"
                 << "array["<<hole <<"]="<<tmp<< std::endl;
                

}


template <class Comp>
void heapify( std::vector<Comp> & array){
        /* HEAPIFY THE VECTOR BUT NOT SORTED YET
           i >= 0, NEED TO HEAPIFY TO THE ZERO
           POSITION IN THE VECTOR
         */
        int N = array.size();
        std::cout<<"ENTERING HEAPIFY"<<std::endl;
        /*i traverses n/2 to 0  */
        for ( int i = N/2; i >= 0; i--){ 
                percolateDown(array,i,N);
        }


}

/* HEAPSORT HAPPENS HERE    */
template <class Comp>
void heapSort( std::vector<Comp> & array){
        std::cout<<"ENTERING HEAP SORT"<<std::endl;

        int N = array.size();
        for ( int j = N-1; j > 0; j--){
                /*swap the biggest element and the bottom of the heap  */
                std::cout << "\nSWAP:"<<"arr["<<0<<"]="<<array[0]<<" & "<<"arr["<<j<<"]="<<array[j]<<std::endl;
                std::swap( array[0], array[j]);
                percolateDown(array,0,j);
        }


}

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){


	std::cout << "number of args =" << argc << std::endl;

        std::string addressFile="";

	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.

	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
	 */
        std::vector<int> vec;
        for ( int i =33; i >15; i--){
                vec.push_back((i%31));
        }
        int N = vec.size();

        /* VIEW VECTOR */
        for ( int k = 0 ; k < N; k++){
                std::cout << vec[k]<<"\t";
                
        }
        std::cout<<"\n** NOW HEAPIFY** \n"<<std::endl;
         
        heapify(vec);

        /* VIEW VECTOR */
        for ( int k = 0 ; k < N; k++){
                std::cout << vec[k]<<"\t";
                
        }

        
        std::cout<<"\n**NOW HEAPSORT**\n"<<std::endl;
        heapSort(vec);

        /* VIEW VECTOR */
        for ( int k = 0 ; k < N; k++){
                std::cout << vec[k]<<"\t";
                
        }
        std::cout <<std::endl;
        return 0;
}
