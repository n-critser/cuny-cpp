/*
 * main.cpp
 *
 *  Created on: Oct 25, 2013
 *      Author: chaos
 */
#include <iostream>
#include <string>
#include "BaseStack.h"
#include "AStack.h"
#include "PStack.h"
//#include "StackException.h"

#define TEST_SIZE 5

using namespace std;



// A little randomness is a good thing (for testing):
int getPos (int p) {

	switch (p) {
		case (5): return 10;  // Should throw an error
		case (7): return 1;   // Should not throw an error
		case (9): return -1;  // Should throw an error
		default : return p;
	}

	// return -1;  // Should not be needed
}



BaseStack<string> * getStack() {
	//string input;
	int input = 1;
	BaseStack<string> * stack;
	cout << "create a list  \n"
		 <<" 1: Array based stack"
		 <<" 2: Linked stack"
		 <<" 3: Doubly Linked stack"
		 <<endl;
	cin >> input;
	switch (input){
	case(1):
		//new ABList<string>();
		stack = new AStack<string>(); // need the <string>() parens make it all OK
		break;
	case(2):
		stack = new PStack<string>();
		break;
	/*case(3):
		stack = new DoubleLinkList<string>();
		break;
	default :
		stack = new LinkedList<string>();
		break;
*/		default:
		stack = 0;
		break;

	}

	return stack;
}



int main(){
	cout <<"what the fuck am i doing" << endl;
	BaseStack <string>* stack= getStack();

	// Test "insert"
	cout << "Let's populate the list with a few items." << endl;
	for (int i = 1; i <= TEST_SIZE; i++) {
		//int pos = getPos(i); // Randomise "i" to test
		string input;

		cout << "Enter a word to push onto the stack " << ": ";
		cin >> input;
		try {
			stack->push(input);
			cout << "Successfully pushed " << input << " to stack" << endl;
		}
		catch (...) {
			cout << "*** Error pushing to stack " << " ***" << endl;
		}
	}
	string theTop="";
	cout << "top of stack is as follows: \n\t";
	cout << stack->getTop(theTop)<< endl;
	cout << endl;


	// Test "delete" and "isEmpty"
	for (int i = 1; i <= 6 ; i++) {
		cout << "Deleting item " << i << "." << endl;
		try {
			cout << "Deleted item " << stack->pop() << endl;
		}
	catch (...) {
			cout << "*** Error deleting from position " << i << " ***" << endl;
		}
	}

	// Done. Let the destructor handle the rest.
	delete stack;



	return 0;
}


