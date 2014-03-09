#include <iostream>
#include "ABCList.hpp"
#include "ABList.hpp"
#include "LinkedList.hpp"
#include "DoubleLinkList.h"


#define TEST_SIZE 13

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


// A very light "factory" -- builds and returns a List instance
ABCList<string> * getList() {
	//string input;
	int input;
	ABCList<string> * list;
	cout << "create a list  \n"
		 <<" 1: Array based list"
		 <<" 2: Linked list"
		 <<" 3: Doubly Linked LIst"
		 <<endl;
	cin >> input;
	/*
	while (input != "Y" && input != "y" && input != "N" && input != "n") {
		cout << "Y/N only please: ";
		cin >> input;
	}
	*/
	switch (input){
	case(1):
		list = new ABList<string>(); // need the <string>() parens make it all OK
		break;
	case(2):
		list = new LinkedList<string>();
		break;
	case(3):
		list = new DoubleLinkList<string>();
		break;
	default :
		list = new LinkedList<string>();
		break;

	}

	return list;
}


int main () {
	// Testing the List implmenetations; first, get a list:
	ABCList<string> * list = getList();

	// Test "insert"
	cout << "Let's populate the list with a few items." << endl;
	for (int i = 1; i <= TEST_SIZE; i++) {
		int pos = getPos(i); // Randomise "i" to test
		string input;

		cout << "Enter a word to place into the list at position " << pos << ": ";
		cin >> input;

		try {
			list->insert(pos, input);
			cout << "Successfully inserted at position " << pos << "." << endl;
		}
		catch (int e) {
			cout << "*** Error inserting at position " << pos << " ***" << endl;
		}
	}


	// Test "retrieve" & "getLength"
	cout << "List is as follows: \n\t";
	for (int i = 1; i <= list->getLength(); i++) {
		cout << list->retrieve(i) << " ";
	}
	cout << endl;


	// Test "delete" and "isEmpty"
	for (int i = 1; i <= 3 && ! list->isEmpty(); i++) {
		cout << "Deleting item " << i << "." << endl;
		try {
			cout << "Deleted item " << list->remove(1) << endl;
		}
		catch (int e) {
			cout << "*** Error deleting from position " << i << " ***" << endl;
		}
	}

	// Done. Let the destructor handle the rest.
	delete list;

	return 0;
}

