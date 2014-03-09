/*
 * ContractController.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: chaos
 */

#include "ContactController.h"
#include <sstream>
#include <fstream>
#include <iostream>

/*Constructor for a LinkedList based ContractController
 *
 */
ContactController::ContactController() {
	list= new LinkedList<Contact*>();
}
/*Constructor for a ArrayBasedList based ContractController
 *
 */
ContactController::ContactController(int Max){
	list = new ABList<Contact*>(Max);
}

//Destroy all the dynamic objects created
ContactController::~ContactController() {
	size_t size = contacts.size();
	size_t count = list->getLength();
	for (size_t i = 0; i < size; i++){
		delete contacts[i];
	}
	for (size_t j = 1; j <= count;j++){
		delete list->remove(1);
	}
	delete list;
}

/*
 * updateContacts(ABCList<Contact*> *aList)throw(int)
 * ************************************************
 * Could be used if a raw copy of the Controllers working
 * List is desired for some reason.
 * Tries to update the contacts for an ABCList pointer
 * by filling it with the list from the controller
 */
void ContactController::updateContacts(ABCList<Contact*> *aList)throw(int){
	//clear the previous list
	while (!aList->isEmpty()){
		aList->remove(1);
	}
	try{
		while(aList->getLength()!=list->getLength()){
			aList->insert(aList->getLength()+1,list->retrieve(aList->getLength()+1));
		}
	}catch(...){
		std::cout << "Error unable to update complete List" << std::endl;
		throw -1;
	}
}

/* searchForContact(std::string &First,std::string &Last,  std::string &Phone, std::string & Mail)
 * *************************************************************************************************
 * Searches for a contact and returns the position in list if found else returns 0
 * This is a helper function for the ContactViewer to find a matching Contact
 * Also helps with deletion.
 * TODO: COULD be used to validate existing Contacts during Contact addition
 */
int ContactController::searchForContact(std::string &First,std::string &Last,  std::string &Phone, std::string & Mail){
	int found = 0;
	Contact * curr;
	for ( int i =1; i<= list->getLength(); i++){
		curr = list->retrieve(i);
		//std::cout << curr->getAll() << std::endl;
		if ((curr->getFirst()==First)|| (curr->getLast() == Last) ||(curr->getPhone()==Phone)||(curr->getEmail()==Mail)){
					//std::cout << "Found matching contact\n";
					found = i;
				}
	}
	//if (found > 0)std::cout<< "Found at position:"<< found << std::endl;
	return found;
}

/*
 * addContact(std::string &First,std::string &Last, std::string &Phone, std::string &Mail)
 * ***************************************************************************************
 * Adds a contact with by creating a new pointer to a valid
 * New Contact and pushing that into the list.
 */
Contact* ContactController::addContact(std::string &First,std::string &Last, std::string &Phone, std::string &Mail){
	Contact * cnt= new Contact(First,Last,Phone,Mail);
	//contacts.push_back(cnt);
	list->insert(list->getLength()+1,cnt);
	return cnt;
}

/*
 * deleteContact(std::string &Last,std::string First, std::string Phone, std::string Mail )
 * ****************************************************************************************
 * Must have at least lastName + 1 other string to match a Contact
 * takes all the strings for a valid contact as args
 * Removes the Contact that matches and returs a pointer to that Contact
 * or 0 if no match is found.
 */
Contact* ContactController::deleteContact(std::string &Last,std::string First, std::string Phone, std::string Mail ){
	Contact * curr=0;
	for (int i = 1; i<= list->getLength();i++){
		curr= list->retrieve(i);
		if ( (curr->getLast() == Last) && ((curr->getEmail()==Mail) || (curr->getFirst()==First)|| (curr->getPhone()==Phone))){
			std::cout << "Found matching contact:  \n";
			std::cout << "Removing from List\n";
			curr=list->remove(i);
			return curr;
		}
	}
	return curr=0;
}

//return the number of contacts
int ContactController::getNumberContacts(){
	return list->getLength();
}
