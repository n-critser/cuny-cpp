#include<iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Contact.h"

using namespace std;

/*
Contact makeContact(std::string line, Contact & cont){
  return

}
*/
int main(int argc,  char*argv[] ){
  string contact[4];
  ofstream nameList;
  vector<Contact> contactVec;
  nameList.open ("people.txt");
  //nameList << "Writing this to a file.\n";
  std::string nextText("hello,name,939393,luca@secondFloor.com");
  std::string text2("micky,mouse,56664,micky@shitBalls.com");
 
  std::istringstream str(nextText);
  std::istringstream second(text2);
  std::string split;
  int i = 0;
  while(getline(str, split, ','))
    {
      std::cout << split  << std::endl;
      contact[i] = split;
      i++;
      //nameList << split;
    }
  Contact cont1 = Contact(contact[0],contact[1], contact[2], contact[3]);
  contactVec.push_back(cont1);
  cout << cont1.getAll() << endl;
  nameList<< cont1.getAll();
  nameList.close();

}
