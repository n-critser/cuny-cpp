/* 
  Project        : HW-1-335
  File           : Poly.cpp
  Author         : n-critser (Nick Critser)
  Created on     : 2/24/14
  Description    : Polynomial output and evaluation program 
  Purpose        : Test file parsing and I/O
  Usage          : ./hw1 <testfile>
  Build with     : make all
  Modifications  : 
 */

#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <cmath>
#include "Poly.h"


/* CONSTRUCTORS FOR POLY CLASS */
/* Default Constructor   */
Poly::Poly() {

}
/* Copy Constructor */
Poly::Poly ( const Poly & rhs){
        
        *this = rhs;

}
/* Singel Term Constructor */
Poly:: Poly(int ex, int coeff) {
        Term first;
        first.expo = ex;
        first.coeff = coeff;
        terms.push_front(first);
}

/* Method: size
   ---------------------------
   usage: int size = poly1.size();
   Returns the size of the list of terms in a polynomial
 */
const int Poly::size(){
        return terms.size();
}

/* Method: push_term
   ----------------------------------------------
   usage: poly1.push_term(coeff,expo);
   This is the workhorse of all the polynomial methods. 
   It  checks for coefficients of zero, and for
   equal exponents and treats them correctly.  It also keeps
   terms in reverse sorted order (decending by exponent). 
 */
void Poly:: push_term(int coeff, int exp){        
        if (coeff == 0)
                return;
        for (listIt=terms.begin(); listIt!=terms.end();listIt++){
                if (exp  == (*listIt).expo){
                        (*listIt).coeff+=coeff;
                        return;
                }               
        }
        Term term;
        term.coeff=coeff;
        term.expo=exp;
        terms.push_back(term);  
        terms.sort();
        terms.reverse();
}


/* Methd: operator()
   ------------------------------
   usage:  poly(3);
   Evaluates the polynomial according to the given scalar
   double pow (double base, double exponent);
 */
const int Poly::operator() (const int x)  {
        int temp= 1;
        int result = 0;
        for ( listIt = terms.begin(); listIt != terms.end(); ++listIt){
                temp = pow(x, (*listIt).expo);
                temp *= (*listIt).coeff;
                result+=temp;
        }
        return result;
}


/* Method: operator*
   ------------------------------
   usage: Poly p3 = p1 * p2
   creates a new Poly which is the product of two previous Poly's
   requires: operator= and possible  operator+ 
 */
Poly* Poly::operator*(const Poly & rhs) {
        int newCoeff=0;
        int newExpo =0;
        Poly* build= new Poly();
        std::list<Term>::const_iterator rhsIt=rhs.terms.begin();
        for (listIt=terms.begin(); listIt!= terms.end(); listIt++){
                for( ; rhsIt!=rhs.terms.end();rhsIt++){
                        newCoeff= (*listIt).coeff * (*rhsIt).coeff;
                        newExpo = (*listIt).expo + (*rhsIt).expo;
                        build->push_term(newCoeff, newExpo);

                }
        }
        return build;
}

/* operator=
   -------------------------------------
   usage: Poly x = y;
   Assingment operator used with operator* when multiplying polynomials
 */
Poly& Poly::operator=(const Poly &rhs) {
        if (this != &rhs){
                this->terms.clear();
                this->terms=rhs.terms;
        }
        return  *this;

}


/* operator<<  **This is a friend function **
   ---------------------------------------------
   usage: std::cout << poly1 << std::endl;
   << operator for Poly class adds the terms of the polynomial
   to an output stream in correct polynomial presentation
   ex: 5x^2-2x+1

 */
std::ostream&  operator<<(std::ostream & stream, const Poly poly){

        std::list<Term>::const_iterator polyIt=poly.terms.begin();
        /*If the polynomial has not terms then return the stream&  */
        if (poly.terms.size()<1)
                return stream<< 0 ;

        /*Use const iterator to read through the terms in poly.terms  */
        polyIt = poly.terms.begin();
        if (poly.terms.size()<1)
                return stream;
        for ( polyIt = poly.terms.begin(); polyIt != poly.terms.end(); ++polyIt){
               
                char sign= '+';
                const int test_coeff= (*polyIt).get_coeff();
                /*Make sure negative coefficients are displayed correctly  */
                sign= test_coeff <0 ?  '\0' : '+';
                if (polyIt == poly.terms.begin()){
                        stream << (*polyIt);
                }
                else{
                        stream << sign << (*polyIt);
                }
        }
         return stream;

}
