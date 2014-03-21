/*******************************************************************************
  Title          : main.cpp
  Author         : n-critser 
  Created on     : 
  Description    : 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o main main.cpp 
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
/* me   */
#include "Logger.h"
#include "BSTree.h"
#include "AvlTree.h"
#include "EavlTree.h"
/*
 * ********************************
 * usage:  write_Log("string");
 * 		   write_Log(convertDigit(number));
 */


debug::Logger log("Trees", "main.debug") ;
/* Log file  
 ***************************************************
 * usage: <log-name> << debug::Logger::DEBUG << " char* or string\n";
 * Change the type of Log 3 possible choices 
 *  {DEBUG, WARNING, INFO }  
 */

/*
 *int main(int argc, char* argv[]):
 ************************************
 *First round of error checking for correct program arguments.
 */
int main(int argc, char* argv[]){
       log << debug::Logger::DEBUG << "\nDebug-Log: Line 1!";

	std::cout << "number of args =" << argc << std::endl;
        std::string addressFile="";

	/* THIS SECTION IS FOR FILE INPUT
	 * If the program is ran without sufficient arguments it Will exit gracefully
	 * with suggestions for the usage of the program.
	 *
	 if (argc < 2) {
                 std::cerr << "Address File not Found\n";
                 std::cerr << "Usage:  " << argv[0] << " filename.txt" << std::endl;
	    return -1;
	  }
        */

        
        const int NOT_FOUND= -999;
        int head = 3;
        std::cout <<NOT_FOUND<<"not found"<<std::endl;
        BSTree<int> number_tree(head);
        AvlTree<int> avl_nums(NOT_FOUND);
        EavlTree<std::string> eavl_strings( "NOT-FOUND");
        std::string tree_string="";
        try {
                /*An int tree instantiated  */
                for (long long  k = 1; k> 0; k=k<<1){
                         avl_nums.insert(k);
                }
                //avl_nums.printTree();
                std::cout<<std::endl;
                std::cout <<"Total Tree height ="<<avl_nums.treeHeight()<<std::endl;
                number_tree.insert(12);
                number_tree.insert(-6);
                std::string test2 = "test2";
                int testFreq = 0;
                for (int m = 0; m <20; m++){
                        std::string one = "--";
                        std::string next = "XX";
                        std::string input = "start";
                        input= input+next+one;
                        eavl_strings.insert(input);
                        eavl_strings.insert(next+test2);
                        eavl_strings.find(input,testFreq);
                        std::cout <<"test freq="<<testFreq<<std::endl;
                        
                }
                std::cout<< eavl_strings.find("startXX--", testFreq);
                std::cout<<std::endl;
                eavl_strings.printTree();
                //number_tree.printTree(tree_string);
                //std::cout << "\nSpace\n"<<std::endl;
                // number_tree.find(3);
                //std::cout<< number_tree.find(head) <<std::endl;
        } catch (...) {
                log << debug::Logger::DEBUG << "\nEXCEPTION BUILDING TREE\n";
        }

        
         return 0;
}
