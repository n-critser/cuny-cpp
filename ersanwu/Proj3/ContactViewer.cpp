/*
 * ContactViewer.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: NICK CRITSER
 */

#include "ContactViewer.h"
#include <iostream>
#include <sstream>
ContactViewer::ContactViewer() {
	// TODO Auto-generated constructor stub

}

ContactViewer::ContactViewer(LinkedList<Contact> *toList){

	//list = *toList;
}
ContactViewer::~ContactViewer() {
	// TODO Auto-generated destructor stub
	//delete list;
}

/*viewContactList(ContactController &controller)
 * *********************************************
 * An unsorted view of the list being used by the controller
 * This function isn't used in the current main program.
 */
void ContactViewer::viewContactList(ContactController &controller){
	Contact *curr;
	std::string temp;
	std::cout<< "list length in viewer="<< controller.list->getLength()<< "\n";
	for (int i=1; i<= controller.list->getLength(); i++){
		curr = controller.list->retrieve(i);
		temp = curr->getFirstLast();
		std::cout << "list at pos:" << i << " is :" << temp << "\n";
	}
	std::cout << "End of Viewing List\n";
}

/*showMatch(ContactController &controller,std::string &First,std::string &Last,
 *		std::string &Phone, std::string & Mail )
 *********************************************************
 *  Show match works in conjunction with the Controller function
 *  searchForContact(First,Last,Phone,Mail).  It gets the integer position of
 *  the match if it is found and also outputs the Contact information of the
 *  matched Contact.
 */
void ContactViewer::showMatch(ContactController &controller,std::string &First,std::string &Last,
		std::string &Phone, std::string & Mail ){
	Contact *curr;
	int position = controller.searchForContact(First,Last,Phone,Mail);
	if (position > 0){
		curr = controller.list->retrieve(position);
		std::cout<< "Found at position:"<< position << std::endl;
		std::cout<< curr->getAll() << "\n";
	}else {
		std::cout <<" No contact in the list matches that information...Sorry\n";
	}
}

/*listToString(ContactController & controller):
 * ********************************************
 * Creates a string buffer from the controller that includes the
 * entire list formatted but not sorted.  The buffer is returned.
 * This is used as the output file buffer feed.
 */
std::string ContactViewer::listToString(ContactController & controller){
	std::string buffer;
	Contact *curr;
	std::string temp;

	for (int i=1; i<= controller.list->getLength(); i++){
		curr = controller.list->retrieve(i);
		temp = curr->getAll();
		buffer+=temp;
		buffer+="\n";
		std::cout << "List at pos:" << i << " is :" << temp << "\n";
	}
	std::cout<< "Length of Contact List ="<< controller.list->getLength()<< "\n";
	//std::cout << "End of List Buffer\n";
	return buffer;
}

/*
 * viewSortedContacts(ContactController &controller):
 * ****************************************************
 * creates a vector of Contact* from the controller referenced by argument
 * then implements a linear sort of the vector by first name and then by
 * last name (to hopefully sort same last names by first name)
 */
void ContactViewer::viewSortedContacts(ContactController &controller){
	Contact *curr;
	std::string temp;
	//std::cout<< "list length in viewer="<< controller.list->getLength()<< "\n";
	std::vector<Contact*> sorted;//
	for (int b = 1; b <= controller.list->getLength(); b++){
		sorted.push_back(controller.list->retrieve(b));
	}
	//std::cout<< "sorted size = "<< sorted.size()<< "\n";
 	for(size_t i = 0; i < sorted.size(); i++){
		for (size_t j=i+1; j < sorted.size(); j++){
			if (sorted[i]->getFirst()> sorted[j]->getFirst()){
				//std::cout<< "sorted " << i<< " = " << sorted[i]->getFirst()
				//		<< "sorted " << j << " = " << sorted[j]->getFirst() << std::endl;
				 curr = sorted[i];
				 sorted[i]= sorted[j];
				 sorted[j]= curr;
			}
		}
	}
 	for(size_t k = 0; k < sorted.size(); k++){
		for (size_t m=k+1; m< sorted.size(); m++){
			if (sorted[k]->getLast()> sorted[m]->getLast()){
				//std::cout<< "sorted " << k<< " = " << sorted[k]->getLast()
				//		<< "sorted " << m << " = " << sorted[m]->getLast() << std::endl;
				 curr = sorted[k];
				 sorted[k]= sorted[m];
				 sorted[m]= curr;
			}
		}
	}
	for (size_t j = 0; j < sorted.size(); j++){
		curr = sorted[j];
		temp = curr->getFirstLast();
		std::cout << "Sorted List at pos:" << j << " is :" << temp << "\n";
	}
	std::cout<< "Number of Contacts in List ="<< controller.list->getLength()<< "\n";

}


