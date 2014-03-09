/*
 * ContactController.h
 *
 *  Created on: Nov 5, 2013
 *      Author: Nick Critser
 * SEE THE .CPP FILE FOR DETAILS ON FUNCTIONS LISTED BELOW
 * ALSO SEE THE .CPP FILE FOR THE CONTACTVIEWER FOR
 * INFORMATION ON VIEWER FUNCTIONALITY
 */

#ifndef CONTACTCONTROLLER_H_
#define CONTACTCONTROLLER_H_
#include "Contact.h"
#include "ABCList.hpp"
#include "ABList.hpp"
#include "LinkedList.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
class ContactController {

private:
	ABCList<Contact*> *list;
	std::vector<Contact*> contacts;
public:
	ContactController();
	ContactController(int Max);
	virtual ~ContactController();
	void updateContacts(ABCList<Contact*> *aList)throw(int);
	int getNumberContacts();
	int searchForContact(std::string &First,std::string &Last,  std::string &Phone, std::string & Mail);
	Contact* addContact(std::string &First,std::string &Last, std::string &Phone, std::string &Mail);
	Contact* deleteContact(std::string &Last,std::string First="", std::string Phone="", std::string Mail="" );
	friend class ContactViewer;// FRIENDS WORK TOGETHER
};

#endif /* CONTACTCONTROLLER_H_ */
