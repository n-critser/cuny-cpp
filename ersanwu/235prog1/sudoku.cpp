/*
 * sudoku.cpp
 *
 *  Created on: Sep 12, 2013
 *      Author: Nick Critser
 */

#include "sudoku.h"
#include <iostream>
#include <cstdlib>
using namespace std;
sudoku::sudoku() {
	//  Auto-generated constructor stub
}

sudoku::~sudoku() {
	//  Auto-generated destructor stub
}

/**method: createPuzzle
 * **********************************
 * Public method used to create a sudoku puzzle.
 * Initializes the first number with a random shuffled int {1-9}
 * Then calls all the necessary private methods to build
 * the puzzle.  All under the covers and hidden from user
 * Usage:
 * 	createPuzzle();
 */
void sudoku::createPuzzle(){
	int first=shuffleInts();
    puzzle[9][9]= {0};
	PointT start;
	puzzle[0][0]=first;
	start.colX=1;
	start.rowY=0;
	makeBoard(start);
}

/**
 * method: testVerticalCollision
 * *****************************
 * Boolean test for a collision in a given row
 */
bool sudoku::testVerticalCollision( PointT test, int aTarget){
		//testing the rows
	if (test.rowY>0){
		for (int k=0; k< test.rowY; k++){  // rows
			//cout << puzzle[k][test.colX]<< endl;
			if (aTarget== puzzle[k][test.colX]){ // what about the current position can't count that
				// << "collision failure in rows\n"<< "test= "<<aTarget<<" target= "<< puzzle[k][test.colX]<< endl;
				return true;
			}
		}
	}
	return false;

}

/**
 * method: testHorizontalCollision
 * ************************
 * Terrible name for a method but it does what it says
 * Boolean test for a collision in a given column
 */
bool sudoku::testHorizontalCollision( PointT test, int aTarget){
	for (int i= 0; i < test.colX; i++){  // columns
		if (aTarget== puzzle[test.rowY][i]){
			return true;
		}
	}
	return false;

}
/**
 * method: testForCollision
 * ******************************
 * The main Bool: it tests for all possible collisions
 */
// needs a point position and a target to find out if a collision exists for this spot
bool sudoku::testForCollision( PointT test, int aTarget){
	if (testHorizontalCollision(test,aTarget) || testVerticalCollision(test,aTarget) || testBlock(test,aTarget)){
		return true;
	}
	return false;
}
/**
 * method: getPuzzle
 * ***********************
 * Takes in a 9 by 9 int array and returns a sudoku puzzle board
 * by calling sudoku::createPuzzle() and filling in the values
 */
//need to have some error checking so that it doesn't return a blank puzzle
void sudoku::getPuzzle(int somePuzzle[ROWS][COLS]){
	createPuzzle();
	for (int row=0; row < ROWS; row++)
		for(int col=0; col < COLS; col++){
			somePuzzle[row][col]=puzzle[row][col];
		}
}

/**
 * method: printPuzzle
 * ************************
 * Prints out the puzzle from the class instance.
 */
void sudoku::printPuzzle(){
	for (int row=0;row<9;row++){
		for (int col=0; col<9; col++){
			std::cout<<  puzzle[row][col];
		}
		std::cout << "\n";
	}
	return;

}

/**method:  testBlock
 * ****************************
 * Checks to see if 3 arrays of int's are valid sudoku 3x3 block
 * Returns the boolean value true if a collision is found
 *usage: if(testBlock(point, numberToTest))
 *
 *	this function taken from
 *	http://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf
 *UsedInBox(grid, row - row%3 , col - col%3, num)
 */
bool sudoku::testBlock(PointT test, int aNumber){
	int checkRows= test.rowY-test.rowY%3;
	int checkCols= test.colX-test.colX%3;
	for (int row=0; row < 3; row++){
		for (int col=0; col< 3; col++){
			if (puzzle[row+checkRows][col+checkCols]== aNumber)return true;
		}
	}
	return false;
}

/**
 * method: endOfPuzzle
 * **********************
 * Recursive base case. Stops the recursion when the
 * puzzle numbers are filled from (0,0) to (9,9)
 */
bool sudoku::endOfPuzzle(PointT check){
	if (check.rowY >= ROWS){
		//cout << "puzzle has ended" << endl;
		return true;}
	return false;
}

/**
 * method: pushValue
 * **********************
 * Pushes a value into the array at a Point
 *
 */
void sudoku::pushValue(PointT pt, int number){
	//cout << "value pushed " << endl;
	puzzle[pt.rowY][pt.colX]= number;
}

/**
 * method: popValue
 * ******************
 * removes a value from the puzzle array and
 * replaces it with -1
 */
void sudoku::popValue(PointT pt){
	//cout << "value popped" << endl;
	puzzle[pt.rowY][pt.colX]= -1;
}

/**
 * method: makeBoard
 * *********************
 * This is the big money method. All the
 * recursion happens here and when the base case
 * is reached then the party ends.
 */
bool sudoku::makeBoard(PointT makeThis ){
	//int num = shuffleInts();
	//cout << "point row=" << makeThis.rowY << " point col= "<< makeThis.colX << " num = " << num<< endl;
	if (endOfPuzzle(makeThis)){ return true;}
	for (int n=1; n < 10; n++){
                if (!testForCollision(makeThis, n)){
                        pushValue(makeThis, n);
                        if (makeBoard(nextPoint(makeThis))){
                                return true;
                        }
                        popValue(makeThis);
                }
	}
	return false;
}

/**
 * method: shuffleInts
 * **********************
 * Returns a random int between 1 and 9
 * Here only used once in the beginning of the
 * array sudoku creation process
 */
int sudoku::shuffleInts(){
	int nums[9]= {1,2,3,4,5,6,7,8,9};
	int x1= rand()%9;
	return nums[x1];
}

/**
 * method: nextPoint
 * ************************
 * Takes a PointT param of a (row,col) ordered pair and
 * returns the next point in the array.  Also keeps
 * track of where in the array the process has gotten.
 * Could probably be pointers to save some clock cycles.
 */
PointT sudoku::nextPoint(PointT curPT){
	PointT nextPT;
	nextPT.rowY=-1;
	nextPT.colX=-1;
/*	for (int rows = 0; rows < ROWS; rows++){
		for (int cols= 0; cols< COLS; cols++){

		}
	}
*/
	//if (curPT.colX==COLS && curPT.rowY==ROWS){ return nextPT;}
	if (curPT.colX < COLS-1){
		nextPT.rowY=  curPT.rowY;
		nextPT.colX= curPT.colX+1;
		//cout << "col increment" << nextPT.colX << endl;
	}else{    // if (curPT.colX  COLS-1){
		nextPT.rowY= curPT.rowY+1;
		nextPT.colX= 0;
	}
	//cout << "nextPt row" << nextPT.rowY << "nextPT col" << nextPT.colX<< endl;
	return nextPT;
}

