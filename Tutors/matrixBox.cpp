/*******************************************************************************
  Title          : blank.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o blank  blank.cpp
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <time.h>
time_t start,end;

class mBox {


private:
        int ROWS;
        int COLS;
        int  matrix[9][9];



public:
        mBox(int n): ROWS(n), COLS(n){}
        void fill();
        void solve(int r,int  c);
        bool test (int r, int c, int num);
        void display();

};


void mBox::solve (int r, int c){
        if (r==ROWS && c ==COLS){return;}
        std::cout <<"entering the recursion"<<std::endl;
        for (int i = 1; i < ROWS+1; i++)
                if (test(r,c,i)  && matrix[r][c]){
                        matrix[r][c]=i;
                        if(c++ < COLS){
                                std::cout<<"next col"<<std::endl;
                                solve(r,c);
                        }
                        else{
                                std::cout<<"next row"<< std::endl;
                                solve(++r,0);
                        }
                }
        

}

        void mBox::display(){
        for ( int i = 0 ; i < ROWS; i++){
                std::cout<<std::endl;
                for( int j= 0; j< COLS; j++){
                        std::cout <<matrix[i][j];
                }
        }
}
        bool mBox::test (int r, int c, int num){
        /*for (int i = 0; i < r; i++){
                if (matrix[i][c] == num){
                        std::cout<<"match found in row ["<< i<<"]"<<std::endl;
                        return false;
                }
        }
        for (int j = 0; j< c ; j++ ){
                if (matrix[r][j] == num){
                        std::cout<< "match found in col ["<<j<<"]"<<std::endl;
                        return false;
                }
        }
        */
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

	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.

	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
        */
         //int n = 5;
         //int rows = n;
         // int cols = n;
         //int matrix[rows][cols];
         
        //solve(0,0);
        // display();
         
         time(&end);
         double dif = difftime (end,start);
         std::cout << "elapsed time" << dif << std::endl;
         return 0;
}


