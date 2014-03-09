#include "Contact.h"

Contact::Contact(){}

Contact::Contact(std::string first, std::string last){

  fName= first;
  lName= last;
  phone= "";
  eMail= "";
  
}
Contact::Contact(std::string first, std::string last, std::string phoneNum, std::string eM){
   fName= first;
  lName= last;
  phone= phoneNum;
  eMail= eM;
}

Contact::~Contact(){}

std::string Contact::getAll(){
  std::string cont= "";
  cont= cont + fName +","+ lName +","+ phone +","+ eMail;
  return cont;
}

 
 
