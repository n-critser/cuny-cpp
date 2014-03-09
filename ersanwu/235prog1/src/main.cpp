/*
 * prog1.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: Nick Critser
 *      CS235
 *
 */

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<set>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include "sudoku.h"
using namespace std;

const int SIZE=9;

/**
 * method: write_Log
 * ******************
 * creates a log file for error checking and debugging
 */
void write_Log(const string & text){
	ofstream log_file("log_file.txt",ios::out |ios::app);// TODO: allow for clobber mode
	log_file << text ;
}
/**
 * method: convertInt
 * *****************
 * Turns an int into a string for logging
 */
string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

/**
 * method: printArray
 * *********************
 * Cycles through a multi Dim array[9][9] and prints to stdout the
 * values in each cell.  Also, puts those values into a log file.
 */
void printArray(int mdArray[SIZE][SIZE]);

int main(){
	srand(time(0));
	sudoku doku1;
	sudoku nextPuz;
	int puzzle25[9][9]={{0}};
	nextPuz.getPuzzle(puzzle25);
	int puzzle1[9][9]={{0}};
	doku1.getPuzzle(puzzle1);

	printArray(puzzle1);
	cout << "Next"<< endl;
	printArray(puzzle25);
	return 0;
}


/**
 * method: printArray
 * no shit takes a mult dim array of size SIZE
 * and prints it out and logs it
 */
void printArray(int mdArray[SIZE][SIZE]){
	for (int i = 0; i < SIZE; i++){
		for (int j=0; j< SIZE; j++){
			//mdArray[i][j]=rowN[j];
			string numToString=convertInt(mdArray[i][j]);
			cout<< mdArray[i][j];
			write_Log(numToString);
		}
		write_Log("\n");
		cout << endl;
	}
	string timeSt=convertInt(time(0));
	write_Log("time stamp");
	write_Log(timeSt);
	write_Log("\n");
}

