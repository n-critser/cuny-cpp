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

#include <iostream>
#include "Organism.h"

Organism::Organism(){}
Organism::Organism(std::string _name, double _score):name(_name), score(_score){}



Organism::Organism(std::string name1, std::string name2, 
		double score1, double  score2){
  name = name1+"_loves_"+name2;
  score = (score1+score2)/2;

}

Organism::Organism(const Organism & organ1, const Organism & organ2){
	name = "(" +organ1.name+","+organ2.name + ")";
	score = (organ1.score + organ2.score)/2;

}


bool  Organism::operator<(const Organism & rhs){
  return this->score< rhs.score;

} 

std::string Organism::toString() {
  return name;
}

const double Organism::getScore() const {
	return score;
}
