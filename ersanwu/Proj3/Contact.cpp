/*
 * Contact.cpp
 *
 *  Created on: Nov 5, 2013
 *      Author: chaos
 */

#include "Contact.h"
#include <iostream>
Contact::Contact(){
	std::cout<< "simple Contract constructor"<< std::endl;
}

Contact::Contact( std::string First,std::string Last, std::string Phone, std::string Mail) {
	fName=First;
	lName=Last;
	phoneNumber=Phone;
	eMail=Mail;
}

Contact::~Contact() {
	//std::cout<< "Contact Destructor called\n";
	// TODO Auto-generated destructor stub
}

bool Contact::operator==(const Contact& rhs)const{
	return ((rhs.lName==lName)&& ((rhs.fName== fName)  || (rhs.eMail== eMail) || (rhs.phoneNumber== phoneNumber)));
}

void Contact::setEmail(std::string Mail){
	eMail=Mail;

}

std::string Contact::getEmail(){
	return eMail;

}
std::string Contact::getFirst(){
	return fName;

}
std::string Contact::getLast(){
	return lName;

}
std::string Contact::getPhone(){
	return phoneNumber;

}

std::string Contact::getFirstLast(){
	std::string cont= "";
	cont= cont + fName +","+ lName ;
	return cont;
}

std::string Contact::getAll(){
  std::string cont= "";
  cont= cont + fName +","+ lName +","+ phoneNumber +","+ eMail;
  return cont;
}

void Contact::setPhone(std::string Phone){
	phoneNumber=Phone;
}



//like a type of constructor that fills in values
std::istream &operator>>(std::istream &str,Contact &cnt)
{
	std::cout<< "Reading the operator\n";
	std::string next;
	while (str >> next){
		//if (next == " ")
		//	break;
		if (next == "\n")
			continue;
		str >> cnt.fName
		>> cnt.lName
		>> cnt.phoneNumber
		>> cnt.eMail  ;
	}
	return str;
}
