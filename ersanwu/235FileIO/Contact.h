#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <string>
class Contact{

 private:
  std::string fName, lName, phone, eMail;



 public:

  Contact();
  Contact(std::string first, std::string last, std::string phoneNum,
	  std::string eM =""); // default arg given in .h not in .cpp
  Contact(std::string first, std::string last);
  ~Contact();

  std::string getAll();

};

#endif /*CONTACT_H_*/
