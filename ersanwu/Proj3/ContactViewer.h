/*
 * ContactViewer.h
 *  Created on: Nov 5, 2013
 *  Author: NICK CRITSER
 * SEE THE .CPP FILE FOR DETAILS ON FUNCTIONS LISTED BELOW
 * ALSO SEE THE .CPP FILE FOR THE CONTACTCONTROLLER FOR
 * INFORMATION ON CONTROLLER FUNCTIONALITY
 */


#ifndef CONTACTVIEWER_H_
#define CONTACTVIEWER_H_
#include "ABCList.hpp"
#include "Contact.h"
#include "LinkedList.hpp"
#include <vector>
#include "ContactController.h"
class ContactViewer {

public:
	ContactViewer();
	ContactViewer(LinkedList<Contact> *toList);
	virtual ~ContactViewer();
	void viewContactList(ContactController &controller);
	void viewSortedContacts(ContactController &controller);
	std::string listToString(ContactController & controller);
	void showMatch(ContactController &controller,std::string &First,std::string &Last, std::string &Phone, std::string & Mail );
};

#endif /* CONTACTVIEWER_H_ */
