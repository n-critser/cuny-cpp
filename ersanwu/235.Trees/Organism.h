/*
 *Organism.h 
 *created on : Dec 5, 2013
 *     Author: chaos
 *
 * Class for organism specification
 * usage: Organism poodle ( "dog" , "13 ) :
 *          Each organism has a name and a score 
 *          If its an ancestor then the score is (child_1 + child_2) / 2
 *          If its an ancestore its name is (name_1 + "loves" + name_2)
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <iostream>
#include <cstdlib>
#include <string>
class Organism{

 private:
  std::string name;
  int score;
  
 public:
  Organism();
  Organism(std::string _name, int _score);
  Organism(const std::string name1, const std::string name2 , const int score1, const int score2);
  Organism(const Organism & organ1, const Organism & organ2);
  bool operator<(const Organism & rhs);
  std::string toString();
  std::string getName();
  const int getScore()const ;


};

#endif /*Organism.h */ 
