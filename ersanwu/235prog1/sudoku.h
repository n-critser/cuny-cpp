/*
 * sudoku.h
 *
 *  Created on: Sep 12, 2013
 *      Author: Nick Critser
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_


struct PointT{
	int rowY,colX;
};

class sudoku {

private:
	const static int ROWS = 9;
	const static int COLS = 9;
	int puzzle[9][9];
	int makeRows( int numRows);
	bool checkBlock(PointT start, PointT stop);
	bool checkBlock(int block_A[3], int block_B[3], int block_C[3]);
	bool testForCollision( PointT test, int aTarget);// don't need the array its there already
	bool testHorizontalCollision( PointT test, int aTarget);
	bool testVerticalCollision( PointT test, int aTarget);
	bool testBlock(PointT test, int aNumber);
	bool endOfPuzzle(PointT check);
	bool makeBoard(PointT makeThis );
	PointT nextPoint(PointT curPT);
	int shuffleInts();
	void pushValue(PointT pt, int number);
	void popValue(PointT pt);
	void createPuzzle();

public:
	sudoku();
	virtual ~sudoku();
	void printPuzzle();
	void getPuzzle(int somePuzzle[ROWS][COLS] );






};

#endif /* SUDOKU_H_ */
