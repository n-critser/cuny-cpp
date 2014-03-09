/*
 * main.cpp
 *
 *  Created on: Oct 30, 2013
 *      Author: chaos
 */
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
#include<locale>
#include"Contact.h"
#include"ABCList.hpp"
#include"ABList.hpp"
#include"LinkedList.hpp"
#include"ContactController.h"
#include"ContactViewer.h"

using namespace std;

std::vector<std::string> getContactString();
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
bool validAddString(std::vector<std::string> addString);

/*interactiveMode:
 * Where everything happens. Feed it a file name and a ContactController pointer.
 * It will take care of the rest.
 * ***********************************************************************
 * usage=      interactiveMode(myContactListFile, myContactController);
 * ***********************************************************************
 * Most file validation, user input validation, and exception handling
 * is implemented here.  Exceptions from adding or deleting from lists
 * are handled to prevent a catastrophic failure during list operations.
 * User input is also validated using the appropriate testing.
 *
 * ContactController class has implemented the ADT for the contact list.
 * ContactViewer is a friend of ContactController and accepts a reference
 * to a valid controller as an argument to its viewing functions.
 */
void interactiveMode(string  & fileName , ContactController *fullController){
	ifstream inFile;
	inFile.open(fileName.c_str()); // need to open the fileargv[1].c_str()

	if(!inFile){
		std::cout << "Valid File not found:  ** Exiting ** " << std::endl;
		exit(1);
	}

	ContactViewer viewer;// A viewer needs a controller reference for any viewing.
	ofstream backUp ("contactList.bk");
	ofstream outFile("contactList");
/****************************************
 * Build the full list of contacts from the file
 ***********************************************/
	try {
		std::string str;
		while(std::getline(inFile, str, '\n'))	{
			std::vector<std::string> data = split(str,',');
			fullController->addContact(data[0],data[1],data[2],data[3]);
		}
	} catch(...){
		std::cout << "Error Building Working Contact List: Maybe Array is too Small" << std::endl;
	}
/********************************************
 * End of List input to Controller
 *******************************************/
	cout << "You have a working list of  length = "<< fullController->getNumberContacts()<< endl;
	std::cout<< "\n\n\n"<< std::endl;
    inFile.close();
	cout << "What do you want to do with your List?\n"
			<< " options are: \n"
			<< " 1: Nothing Just view it\n"
			<< " 2: Add a contact\n"
			<< " 3: Delete a contact\n"
			<< " 4: Find a contact by First and Last Name\n"
			<< " 5: View choices\n"
			<< "-1: Stop messing with the List and save it\n" ;
	string userInput;
	int input;

	std::vector<std::string> contactString;

	do{
		std::getline(cin,userInput);
		stringstream myStream(userInput);
		 if (myStream >> input){


			 switch (input){
			 case(-1):
					 std::cout<< std::endl;
					 std::cout << "Your List will be saved to the files: contactList and contactList.bk \n"<< std::endl;

					 break;
			 case(1): // Sort the view lister
						try{
							cout << "View the List\n";
							//cout << "Length of List = "<< fullController->getNumberContacts()<< endl;
							//viewer.viewContactList(fullController);
							viewer.viewSortedContacts((*fullController));
						} catch(...){
							std::cout<< "Error Viewing Contact List"<< std::endl;
						}
						std::cout << "Once again pick a number between 1 and 5 or hit -1 to end"<< std::endl;
						break;
			 case(2): //ADD contact
						try{
							cout << "add a contact\n" ;
							contactString=getContactString();
							if (validAddString(contactString))
								fullController->addContact(contactString[0],contactString[1],contactString[2], contactString[3]);
							//fullController.updateContacts(aList);
							else{
								std::cout << "\n***Error:Your contact string was invalid\n"
										  << "***Enter a first and last name for a valid Contact"<< std::endl;
							}
							contactString.clear();
						} catch(...){
							std::cout << "Error Adding Contact to List" << std::endl;
						}
						//viewer.updateList(controller.copyList());
						std::cout << "Once again pick a number between 1 and 5 or hit -1 to end"<< std::endl;
						break;
			 case(3)://Delete contact
						cout << "delete a contact\n";
			 contactString=getContactString();
			 fullController->deleteContact(contactString[1],contactString[0],contactString[2], contactString[3]);
			 contactString.clear();
			 break;
			 case(4):// FIND CONTACT TODO:  find is failing for some reason
						// the Retrieve now fails due to const !!!!
						cout <<" find a contact by first and last w/controller\n";
			 contactString= getContactString();
			 viewer.showMatch((*fullController),contactString[0],contactString[1],contactString[2], contactString[3]);
			 std::cout << "Once again pick a number between 1 and 5 or hit -1 to end"<< std::endl;
			 break;
			 case(5):
						cout << "What do you want to do with your List?\n"
						<< " options are: \n"
						<< " 1: Nothing Just view it\n"
						<< " 2: Add a contact\n"
						<< " 3: Delete a contact\n"
						<< " 4: Find a contact by First and Last Name\n"
						<< " 5: View choices\n"
						<< "-1: Stop messing with the List and save it" << std::endl;
			 break;
			 default:
				 std::cout << "Input Invalid**** Try Again" << std::endl;
				 std::cout << "Once again pick a number between 1 and 5 or hit -1 to end"<< std::endl;
				 //exit(1);
				 break;
			 }


		 } else{
			 //cout << "Invalid number, please try again" << endl;
		 }

	}while (input !=-1 );//TODO: NEED TO VALID SO THAT LOOP STOPS
	outFile << viewer.listToString((*fullController));
	outFile.close();
}


/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 *Instantiation of ContactController
 */
int main(int argc, char* argv[]){


	//cout << "number of args =" << argc << endl;
	ContactController * fullController;
	string addressFile="";

	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 */
	 if (argc < 2) {
		cerr << "Address File not Found\n";
	    cerr << "Usage:  " << argv[0] << " adresses.txt" << endl;
	    cerr << "**** or  with integer for array size "<< std::endl;
	    cerr << "Usage:  " << argv[0] << " addresses.txt 20 " << endl;
	    return -1;
	  }

   switch (argc){

   case(2):
		 // No 2nd param so LinkedList is implemented in the ContactController
		cout<< "creating an pointer linkedlist from  : " << argv[1] <<" contacts."<< endl;
   	    fullController= new ContactController();
   	    addressFile= argv[1];
   	    cout << "addressFile ="<< addressFile << endl;

   	    break;
   case(3):
		// No 2nd param so LinkedList is implemented in the ContactController
		cout<< "creating an array based list from: " << argv[1]<< " with space for "<< argv[2]<<" contacts."<< endl;
   	    const int MAX= atoi(argv[2]);//strtol(argv[2], ,0);
		fullController = new ContactController(MAX);
		addressFile= argv[1];
    	cout<< "addressFile ="<< addressFile<< "\nList Array Size =" << argv[2] << endl;
    	//inFile.open(addressFile.c_str()); // need to open the fileargv[1].c_str()
    	break;
    }
   /* Call to interactiveMode means a file name has been given
    * And a ContractController was instantiated.
    */
   interactiveMode(addressFile,fullController);
   std::cout << "		See you Later		"<< std::endl;
   return 0;

}

bool validAddString(std::vector<std::string> addString){

	//std::cout << addString[0]<< addString[1]<<addString[2]<<addString[3]<< std::endl;
	//std::cout<< ((addString[0].size()>2) && (addString[1].size()>2)) << "bool test " << std::endl;
	if ((addString[0].size()>2) && (addString[1].size()>2))
		return true;
	return false;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<std::string> getContactString(){
	std::vector<std::string> contStr;
	contStr.clear();
	std::cout<< "Enter a string in the following format\n"
			<< "First Name, Last Name, Phone number, eMail address\n"
			<< "Enter double quotes \"\" to skip a line.  \n";
	//std::cin>>first>> last>>phone>>email;
	std::string str;
	std::locale loc;
	while(cin >> str){
		cout << "You entered: [" << str << "]"<< std::endl;
		contStr.push_back(str);
		if (contStr.size()>3)
			break;
		std::cout<<"Enter double quotes \"\" to skip phone or email.  \n";
	}
	contStr[0][0]=std::toupper(contStr[0][0],loc);// upper case the first letter of first name
	contStr[1][0]=std::toupper(contStr[1][0],loc);// upper case the first letter of last name
	return contStr;
}
