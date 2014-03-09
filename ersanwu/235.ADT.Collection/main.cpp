#include <iostream>
#include "ABCList.hpp"
#include "ABList.hpp"
#include "LinkedList.hpp"
#include "DoubleLinkList.h"
#include "BaseStack.h"
#include "BaseQueue.h"
#include "PStack.h"
#include "PQueue.h"
#include "AStack.h"
#include "AQueue.h"



#define TEST_SIZE 13

using namespace std;



// A little randomness is a good thing (for testing):
int getPos (int p) {

	switch (p) {
		case (5): return 10;  // Should throw an error
		case (7): return 1;   // Should not throw an error
		case (9): return -1;  // Should throw an error
		case (4): return p+1; // throw error
		case (6): return 4;
		default : return p;
	}

	// return -1;  // Should not be needed
}





int main () {
	// Testing the List implmenetations; first, get a thing
	ABCList<string> * list=0;
	BaseQueue<string> * queue=0;
	BaseStack<string> * stack=0;
	int input;
	cout << "create a list  \n"
		 <<" 1: Array based list"
		 <<" 2: Linked list"
		 <<" 3: Doubly Linked LIst"
		 <<" 4: Stack using pointers"
		 <<" 5: Stack using array"
		 <<" 6: Queue using pointers"
		 <<" 7: Queue using array"
		 <<endl;
	cin >> input;


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
	case(4):
		stack = new PStack<string>();
		break;
	case(5):
		stack = new AStack<string>();
		break;
	case(6):
		queue = new PQueue<string>();
		break;
	case(7):
		queue = new AQueue<string>();
		break;
	default :
		list = new LinkedList<string>();
		break;

	}
	//LIST TESTS
	if (list!=0){
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
	}
	//STACK TESTS
	if (stack!=0){
		// Test "insert"
		cout << "Let's populate the stack with a few items." << endl;
		for (int i = 1; i <= TEST_SIZE/2; i++) {
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
				cout << "*** Error popping item : "<<i << " ***" << endl;
			}
		}


	}

	if (queue!=0){
		// Test "insert"
		cout << "Let's populate the queue with a few items." << endl;
		for (int i = 1; i <= TEST_SIZE; i++) {
			//int pos = getPos(i); // Randomise "i" to test
			string input;

			cout << "Enter a word to push onto the queue " << ": ";
			cin >> input;
			try {
				queue->enqueue(input);
				cout << "Successfully enqueueED " << input << " to queue" << endl;
			}
			catch (...) {
				cout << "*** Error pushing to queue " << " ***" << endl;
			}
			if (i%5==0){
				try {
					cout <<" dequeing at i = "<< i <<"\n\t";
					cout << (queue->dequeue())<< endl;
				}
				catch(...){
					cout <<" ***Error Dequeuing " << "***"<< endl;
				}

			}
		}
		cout << "front of queue is as follows: \n\t";
		cout << queue->getFront() << endl;
		cout << endl;


		// Test "delete" and "isEmpty"
		for (int i = 1; i <= 15 ; i++) {
			cout << "Deleting item " << i << "." << endl;
			try {
				cout << "Deleted item " << (queue->dequeue()) << endl;
			}
		catch (...) {
				cout << "Error dequeueing item : "<<i << " ***" << endl;
			}
		}





	}
	// Done. Let the destructor handle the rest.
	delete list;
	delete queue;
	delete stack;

	return 0;
}

