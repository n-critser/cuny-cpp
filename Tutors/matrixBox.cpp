/*******************************************************************************
  Title          : matrixBox.cpp
  Author         : n-critser 
  Created on     : [2014-03-20]
  Description    : A matrix is filled with no row, column conflicting values
  Purpose        : A backtracking algorithm example
  Usage          : ./EXECUTABLE
  Build with     : g++ -o matrixBox  matrixBox.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <time.h>
#include <iomanip>
time_t start,end;

class mBox {


private:
        int ROWS;
        int COLS;
        int  matrix[9][9];
        bool solve(int r,int  c);
        int size;


public:
        mBox(int n): size(n),ROWS(n-1), COLS(n-1){}
        void fill();
        void solve();
        bool test (int r, int c, int num);
        void display();
        // Function to output class to ostream
        friend std::ostream& operator<<
	  ( std::ostream& os, const mBox& box );

};


std::ostream& operator<< ( std::ostream& os, const mBox& box ){
        os << std::endl;
        int size = box.size;

        os << " +"; for(int i = 0; i < size*5-1; ++i) os << "-";
        os << "+\n";

        for(int i = 0; i < size; ++i){ 
                os << " | "; 
                for(int j = 0; j < size; ++j)
                        os <<  std::setw(2) << box.matrix[i][j] << " | ";
                os << std::endl;

                os << " +"; for(int i = 0; i < size*5-1; ++i) os << "-";
                os << "+\n";

        }


        return os;
}

void mBox::solve(){
        solve(0,0);
}


void mBox::fill(){
        for (int i = 0; i < size; i++)
                for (int j= 0; j< size; j++)
                        matrix[i][j]= -1;

}


/*
  Function: solve
  -------------------------------------------------------------
  usage: solve(0,0);
  -------------------------------------------------------------
  description:
       Recursively submits numbers into the matrix and uses
       backtracking.  If a value is set value conflicts it is
       unset.  This process goes back and forth until all
       values are set in the matrix or a solution is unable
       to be found with the available values.
  ------------------------------------------------------------
 */
bool mBox::solve (int r, int c){
        //std::cout<<"solving["<<r<<"]"<<"["<<c<<"]"<<std::endl;
        if (r==ROWS+1 && c ==0){
                std::cout<< "solution found"<<std::endl;
                return true;}
        //std::cout <<"entering the recursion"<<std::endl;
        for (int i = 1; i <= ROWS+1;i++ ){
                if (test(r,c,i)  && matrix[r][c]==-1){
                        matrix[r][c]=i;
                        /*set [i][j] and try to solve the next element */
                        int nextC=c;
                        int nextR=r;
                        
                        nextC++;
                        //std::cout << "nextR="<<nextR<<"\t nextC="<<nextC<<std::endl;
                        if (nextC > COLS){
                                nextC = 0;
                                nextR++;
                        }
                        //std::cout<<"second solving["<<nextR<<"]"<<"["<<nextC<<"]"<<std::endl;
                        if( solve(nextR,nextC)){
                                //std::cout <<"solved all"<<std::endl;
                                return true;
                        }
                }
                matrix[r][c]=-1;
                //std::cout<<"value not set["<<r<<"]["<<c<<"]"<<std::endl;
              
        }
        
        return false;
}

void mBox::display(){
        for ( int i = 0 ; i < size; i++){
                std::cout<<std::endl;
                for( int j= 0; j< size; j++){
                        std::cout <<matrix[i][j];
                }
        }
}

/*
  Function: test
  -------------------------------------------------------------
  usage: test (row,col,number);
  -------------------------------------------------------------
  description: returns the boolean value for any number of tests done on
               the given number and all other values in the matrix.
  
 */
bool mBox::test (int r, int c, int num){

        
        if( r > 0){
                for (int i = 0; i < r; i++){
                        if (matrix[i][c] == num){
                                //std::cout<<"match found in row ["<< i<<"]"<<std::endl;
                                return false;
                        }
                }
        }
 

        for (int j = 0; j< c ; j++ ){
                if (matrix[r][j] == num){
                        //std::cout<< "match found in at["<<r<<"]["<<j<<"]"<<std::endl;
                        return false;
                }
        }
        //std::cout<<std::endl;
       
        return true;

}



/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){

        time(&start);
	std::cout << "number of args =" << argc << std::endl;

        std::string addressFile="";


        mBox matrix1(9);
        matrix1.fill();
        matrix1.solve();
        //matrix1.display();
        std::cout <<matrix1<<std::endl;
	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.

	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
        */
         time(&end);
         double dif = difftime (end,start);
         std::cout << "\n elapsed time" << dif << std::endl;
         return 0;
}


