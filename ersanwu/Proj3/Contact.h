/*
 * Contact.h
 *
 *  Created on: Nov 5, 2013
 *      Author: chaos
 */

#ifndef CONTACT_H_
#define CONTACT_H_
#include <string>
#include <vector>
class Contact {  // TODO: add the object creation to make file

private:
	std::string fName;
	std::string lName;
	std::string phoneNumber;
	std::string eMail;
public:
	Contact();
	Contact( std::string First,std::string Last, std::string Phone="", std::string Mail="");
	virtual ~Contact();
	void setEmail(std::string Mail);
	void setPhone(std::string Phone);
	std::string getFirst();
	std::string getLast();
	std::string getEmail();
	std::string getPhone();
	std::string getFirstLast();
	std::string getAll();
	bool operator==(const Contact& rhs)const;
	friend std::istream &operator>>(std::istream &str,Contact &cnt);
};

#endif /* CONTACT_H_ */
