/* Author: Nick Critser
 * main.cpp
 * Binary Tree Code is a conglomeration of code from:
 * Stewart Weiss :  http://www.compsci.hunter.cuny.edu/~sweiss/courses/csci235.php
 * Carrano :  Data Abstractions and Problem Solving in C++
 * Created on: Nov 23, 2013
 *
 */
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cctype>
#include<locale>
#include <vector>
#include <list>
#include "BinaryTree.h"
#include "Organism.h"


/*Log file for collecting output:
 * ********************************
 * usage:  write_Log("string");
 * 		   write_Log(convertDigit(number));
 */
void write_Log(const std::string & text){
	//std::ofstream log_file("log_file.txt",std::ios::out |std::ios::app);// TODO: allow for clobber mode
	//log_file << "\n";
	//log_file << text ;
	std::cout<<  text << std::endl;
}
std::string convertDigit(double number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
/* END OF LOGGER*/

/* split:
 * **********************************************************
 * usage:  std::vector<std::string> data = split(str);
 * **********************************************************
 * The reference string is split using the >> operator
 * and pushed into a vector.  When finished the full vector
 * is returned.
 */
std::vector<std::string> &split(const std::string &s,  std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (ss>>item) {
        elems.push_back(item);
    }
    if (elems.size()>2)
    	throw -1;
    int i = 0;
    const char* score = elems[1].c_str();
    while (score[i]){
    	if ((!ispunct(score[i])) && (!isdigit(score[i]))){
    			throw -1;
    	}
    	i++;
    }
    return elems;
}
std::vector<std::string> split(const std::string &s) {
    std::vector<std::string> elems;

    split(s, elems);

    return elems;
}



/* Display Functions used to display a tree in a traversal
 * ********************************************************
 * usage:  someTree.in_order(display);
 * ********************************************************
 */
void display(int & item){
	std::cout<< "item = " << item << std::endl;
}

void display(Organism * &org){
	std::string name = org->toString();
	double score = org->getScore();
	//std::cout << name << "["<< org->getScore()<< "]"<< std::endl;
	write_Log(name+"["+ convertDigit(score) + "]");
}
/* END OF DISPLAYS       */


/* pairClosestCousin:
 * *******************************************
 * usage: pairClosestCousin(listOfBinaryTreePointers)
 * ***********************************************************************
 * Looping through the list twice, the function locates
 * the pair of organisms with the least difference and creates an organism
 * combining their name and average of theirs scores. This organism then
 * becomes the root node of a new tree and its component trees are added
 * as left and right branches.
 *
 * After the new tree is pushed back into the original list the
 * function calls itself until the size of the list = 1
 */
void pairClosestCousin(std::list< BinaryTree<Organism*> * > & binTreeList){
	if (binTreeList.size()==1){
		//write_Log("One Tree Left ");
		return;
	}
	double diff=999;
	/*List Iterators below allow for traversing the list :
	 * ------------------------------------------------------
	 * it1 & it2 are used inside the loop structure to keep
	 * track of the smallest difference of 2 organisms
	 * ------------------------------------------------------
	 * rm_it_1 & rm_it_2 are used to set the values needed
	 * for created the new ancestor organism outside of the
	 * loops
	 */
	std::list< BinaryTree<Organism*> *>::iterator it1;
	std::list< BinaryTree<Organism*> *>::iterator it2;
	std::list< BinaryTree<Organism*> *>::iterator rm_it_1;
	std::list< BinaryTree<Organism*> *>::iterator rm_it_2;
	it1 = it2 = binTreeList.begin();
	it2++;
	rm_it_1 = it1;
	rm_it_2 = it2;
    // The lead difference value is set HERE.
	try {
		diff = abs((*it1)->get_root()->getScore() - (*it2)->get_root()->getScore() );
	} catch(...){
		write_Log("Exception thrown getting first diff ");
	}
	/*The two loops below search for a difference value smaller the the lead difference
	 * if one is found the difference value is updated and the iterator positions are
	 * reset according to the new value.
	 */
	double newDiff= diff+1.0;
	try{
		for (; it1 != binTreeList.end(); ++it1){
			it2 = binTreeList.begin();
			it2++;
			for (; it2 != binTreeList.end(); ++it2){
				//(*it)->get_root()->toString();
				if (((*it1)->get_root()!=(*it2)->get_root())&& ((*it1)->get_root()!= NULL) && ((*it2)->get_root()!= NULL)){
					newDiff = abs((*it1)->get_root()->getScore() - (*it2)->get_root()->getScore());
					if (newDiff  < diff){
						//std::cout<< "New diff = " << newDiff << std::endl;
						if((*it1)->get_root()->getScore()< (*it2)->get_root()->getScore()){
							rm_it_1 = it1;
							rm_it_2 = it2;
						}else{
							rm_it_1 = it2;
							rm_it_2 = it1;
						}
						diff = newDiff;
						//write_Log("Changed Diff = "+ convertDigit(diff)+ "\n");
					}
				}
			}
		}
		/* MAGIC HAPPENS HERE:  An ancestor is born from 2 children and the family tree
		 * grows upward from the leaves.
		 */
		Organism * newOrg = new Organism((*(*rm_it_1)->get_root()),(*(*rm_it_2)->get_root()));
		//write_Log("new organism created = "+ newOrg->toString());
		//make a new BinaryTree (newNode, leftTree, rightTree);
		BinaryTree<Organism*> * newTree = new BinaryTree<Organism*>(newOrg, *(*rm_it_1),*(*rm_it_2) );
		binTreeList.erase(rm_it_1);
		binTreeList.erase(rm_it_2);
		binTreeList.push_back(newTree);
		/* RECURSIVE CALL TO function: pairClosestCousin !  */
		pairClosestCousin(binTreeList);
		//newTree->in_order(display);
	}catch(...){
		std::cout << "Exception thrown pairing Closest Cousin" << std::endl;
	}

}/*END OF  pairClosestCousin */


/* buildOrgTree:
 * *************************************
 * usage: buildOrgTree(listOfTreePointers, binaryTree);
 * ****************************************************
 * Joins the list of BinaryTree pointers
 * When only one tree is left in the list, this tree
 * is put into the reference to a BinaryTree given as
 * an argument.
 */
void buildOrgTree(std::list< BinaryTree<Organism*> *> treeList, BinaryTree<Organism*> &orgTree){
	std::list< BinaryTree<Organism*> *>::iterator it;
	try {
		/* number of trees > 1 join the trees together  */
		//while (treeList.size()> 1){
			pairClosestCousin(treeList);
			//write_Log("Length of list of trees =  "+convertDigit(treeList.size()));
		//}
	}catch(...){
		std::cout<< "Exception joining Trees" << std::endl;
	}
	//write_Log("Length of list of trees =  "+convertDigit(treeList.size()));
	orgTree = *treeList.front();
}


/* usage:  ./proj5 organisms.txt
 * *******************************************
 * Given a correct file the program takes a list of organisms and
 * constructs its ancestral tree based on the scores in the file.
 * The only output is the string parenthetical expression which
 * represents the closest organisms joined in a tuple of the form
 * ((dog,wolf),mountianGoat)
 *
 */
int main(int argc, char* argv[]){
	std::string addressFile="";
	/*
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 */
	if (argc < 2) {
		std::cerr << "Address File not Found\n";
		std::cerr << "Usage:  " << argv[0] << " adresses.txt" << std::endl;
		return -1;
	}

	addressFile=argv[1];
	std::ifstream inFile;
	inFile.open(addressFile.c_str()); // need to open the fileargv[1].c_str()

	if(!inFile){
		write_Log( "Valid File not found:  ** Exiting ** ");
		exit(1);
	}


	std::list< BinaryTree<Organism*> *> treeList;
	/****************************************
	 * Build a vector of Organisms from the file
	 ***********************************************/
	try {
		std::string str;
		std::vector<std::string> data;
		while(std::getline(inFile, str, '\n'))	{

			try{
				 data = split(str);
			}catch(...){
			    	write_Log("**********Exception Throw splitting string:  Line Skipped********");
			    	write_Log("Error Occured IN: "+str);
			    	continue;
			}
			//double score = std::stod (data[1]);
			Organism * toAdd = new Organism(data[0], atoi(data[1].c_str()));
			//Organism * toAdd = new Organism(data[0], score);
			BinaryTree<Organism*> * tree = new BinaryTree<Organism*> (toAdd);
			treeList.push_front(tree);
		}
	} catch(...){
		write_Log( "*********Exception thrown building Binary Trees: *********");
		write_Log("*********Please correct Invalid Input: ********************");
	}
	/********************************************
	 *Initial List of Binary Trees Built
	 *******************************************/
	//write_Log("Length of list of trees =  "+convertDigit(treeList.size()));

	/*******************************************************************
	 * Build LifeTree:
	 * *****************************************************************
	 */
	BinaryTree<Organism*> orgTree;
	buildOrgTree(treeList,orgTree);

	/*
	 *DISPLAY THE FINAL TREES ROOT NODE
	 */
	orgTree.in_order(display);
	write_Log("orgTree has heigh = " + convertDigit(orgTree.height()));
	write_Log(orgTree.get_root()->toString());
	return 0;
}




