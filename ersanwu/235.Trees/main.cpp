/*
 * main.cpp
 * Binary Tree Code is a conglomeration of code from:
 * Stewart Weiss :  http://www.compsci.hunter.cuny.edu/~sweiss/courses/csci235.php
 * Carrano :  Data Abstractions and Problem Solving in C++
 *  Created on: Nov 23, 2013
 *      Author: chaos
 */
/* DEBUG MACRO */
//#define NDEBUG
#include<assert.h>
/* END DEBUG MACRO */


#include<cstdlib>
#include<fstream>
#include<sstream>
#include<string>
#include<cctype>
#include<locale>
#include <list>
#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include "BSTree.h"
#include "Organism.h"




/*Log file for collecting output:
 * ********************************
 * usage:  write_Log("string");
 * 		   write_Log(convertDigit(number));
 */
void write_Log(const std::string & text){
	std::ofstream log_file("log_file.txt",std::ios::out |std::ios::app);// TODO: allow for clobber mode
	log_file << "\n";
	log_file << text ;
	std::cout<<  text << std::endl;
}
std::string convertDigit(double number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
/* END OF LOGGER*/
void display(Organism & org){
  std::string name = org.toString();
 std::cout << name << "["<< org.getScore()<< "]"<< std::endl;
}

void display(int & item){
	std::cout<< "item = " << item << std::endl;
}


int main(){
	const int NUMBERS = 100;
	BinaryTree<int>  left, right;
	BinaryTree<int> tree1(1);
	BSTree<int> root(12);
	BSTree<int> punk(0);
	srand(time(0));
	std::string output="";
	std::string punk_out="";

	try {
		punk.insert(10);
		punk.insert(3);
		punk.insert(6);
		punk.insert(8);
		punk.printTree(punk_out);
		std::cout<< "Is the tree degenerate? : " << punk.isDegenerate()<< std::endl;
		//ASSERTION THAT THE ABOVE IS TRUE
		assert(punk.isDegenerate()== true);

	}catch(...){
		write_Log("Exception thrown inserting in PUNK");
	}
	try {
		for ( int i = 0; i < 13; i++)
			root.insert(rand()%NUMBERS-i*2);
		root.insert(7);
		root.insert(66);
		root.insert(24);
		root.printTree(output);
		std::cout<< std::endl;
		std::cout<< output<< std::endl;
	} catch(...){
		write_Log( "Exception occured inserting");
	}
	std::cout<< "Is the tree degenerate? : " << root.isDegenerate()<< std::endl;

	try {
		//root.remove(23);
		root.remove(24);

		root.printTree(output);
		std::cout<< std::endl;
		root.remove(66);
		std::cout<< std::endl;
		root.printTree(output);
		root.remove(12);
		std::cout<< std::endl;
		root.printTree(output);
		std::cout<< std::endl;
		std::cout<< output<< std::endl;
	} catch(...){
		write_Log( "Exception occured removing");
	}
	std::cout<< std::endl;
	Organism poodle("dog",35);
	Organism ralph("man",10);
	Organism gorilla("ape", 12);
	Organism dolphin("dolphin", 66);
	Organism jaws("shark", 70);

	//std::vector< BinaryTree<Organism>* > treeVec;
	std::vector<Organism> orgVec;
	orgVec.push_back(poodle);
	orgVec.push_back(ralph);
	orgVec.push_back(gorilla);
	orgVec.push_back(dolphin);
	orgVec.push_back(jaws);
	//BinaryTree<Organism>* orgs;
	BinaryTree<Organism> poo(orgVec[0]);
	BinaryTree<Organism> dude(orgVec[1]);
	//BinaryTree<Organism> gor(orgVec[2]);
	poo.in_order(display);
	dude.in_order(display);
	Organism pood_dude(poodle.toString(),ralph.toString(),poodle.getScore(),ralph.getScore());
	Organism gor_poo_doo(pood_dude,gorilla);
	BinaryTree<Organism> poo_du(pood_dude);
	BinaryTree<Organism>gored(gor_poo_doo);
	poo_du.in_order(display);
	gored.in_order(display);
	//treeVec.push_back(poo);
	//treeVec.push_back(dude);

	/*
	tree1.attach_left(2);
	//tree1.attach_right(3);
	//tree2.in_order(display);
	left.set_root(4);
	left.attach_left(6);
	left.attach_right(8);

	right.set_root( 3);
	right.attach_right(5);
	right.attach_left(7);
	BinaryTree<int>tree5(0,left,right);

	std::cout << "\ntree5 traversing in post_order\n"<< std::endl;
	//tree5.post_order(display);

	std::cout << "\ntree5 traversing in pre_order\n"<< std::endl;
	//tree5.pre_order(display);

	std::cout << "\ntree5 traversing in in_order\n"<< std::endl;
	//tree5.in_order(display);

	std::cout << "\ntree1 traversing in in_order\n"<< std::endl;
	//tree1.in_order(display);

	std::cout << "\nAdding tree5 to the right of tree1 \n"<< std::endl;
	tree1.attach_right_subtree(tree5);
	std::cout << "\ntree1 traversing in in_order\n"<< std::endl;
	tree1.in_order(display);



	//tree2.in_order(tree2.display());
	*/

	return 0;
}


