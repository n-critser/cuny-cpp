/* 
  Project        : HW-1-335
  File           : Poly.h
  Author         : n-critser (Nick Critser)
  Created on     : 2/24/14
  Description    : Polynomial output and evaluation program 
  Purpose        : Test file parsing and I/O
  Usage          : ./hw1 <testfile>
  Build with     : make all
  Modifications  : 
 */

#ifndef Poly_H_
#define Poly_H_
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

/* class Term:
   ------------------------------
   usage: poly.terms.push_back(aTerm);
   This class allows each polynomial to construct the
   appropriate amount of polynomials, while also separating the interface
   of a polynomial from the terms. 
 */
class Term {
        friend class Poly;
private:
        int coeff;
        int expo;
        Term(int coeff=0, int expo=0): coeff(coeff), expo(expo){}
        
        /* operator+
           -------------------------------------
           usage: term3 = term1 + term2 ;
           Terms are only added when their exponents are equal. 
         */
        Term operator+(Term &rhs){
                Term newTerm;
                if (this->expo!=rhs.expo){
                        throw -1;                      
                }
                newTerm.coeff= coeff+rhs.coeff;
                newTerm.expo = rhs.expo;
                return newTerm;              
        }
        
public:
        /* operator=
           -------------------------
           usage: lTerm = rTerm;
           This operator often usage in conjunction with the addition
           operator to adjust coefficients.
         */
        Term& operator=(const Term &rhs){
                if (this != &rhs){
                        coeff=rhs.coeff;
                        expo=rhs.expo;
                }
                return  *this;
        }

        /* operator<
           ------------------------------------
           usage: terms.sort();
           Less than operator overloading allows the use of c++ stock sort
           functions on containers of this class.
         */
        bool operator<(Term &rhs) const {
                return(expo < rhs.expo);
        }

        /* operator==
           -----------------------------------
           usage: if(term1==term2)...
           For terms this is most useful for matching exponents
           so it returns the evaluation of comparing the exponent
           of two terms.
         */
        bool operator==(Term &rhs) const {
                return (expo == rhs.expo);
        }

        std::string to_String() const {
                std::stringstream strm;
                std::string output;
                strm << coeff << "x^"<<expo << "\n";
                output =strm.str();
                return output;
        }

        /* operator<< **This is a friend function**
           -------------------------------
           usage: std::cout << aTerm << std::endl;
           This operator works in conjunction with insertion operator
           for Poly to give the full output for a polynomial with
           terms in decreasing exponent orders. 
         */
        friend std::ostream & operator<<(std::ostream & stream , const Term term){

                //int coeff= std::abs(term.coeff);
                if (term.coeff == 0)
                        return stream;
                if ( term.coeff != 1 && term.coeff != -1  && term.expo != 0 && term.expo !=1){
                        stream << term.coeff << "x^" << term.expo;
                        return stream;
                }
                if (term.coeff != 1 && term.coeff != -1 ){
                        if (term.expo == 0  )
                                stream << term.coeff;
                        else if (term.expo ==1 )
                                stream << term.coeff << "x";
                        return stream;
                }
                if (term.expo ==1 )
                        stream << "x";
                else 
                        stream << "x^" << term.expo;
                return stream;
        }

        const int get_coeff()const{
                return coeff;
        }
        
};

/* class Poly:
   -----------------------------
   The Polynomial class containing a list of terms along with methods
   to manipulate polynomials.  
 */
class Poly {
private:
        /* Private Member Variables include a list of Terms and
           and iterator for the list. 
          
         */
        std::list<Term> terms;
        std::list<Term>::iterator listIt;
public:
        Poly();
        Poly(const Poly & rhs);
        Poly(int ex, int coeff);
        Poly(Poly left, Poly right);
        friend std::ostream & operator<<(std::ostream & stream, const Poly poly);
        const int operator()(const int x);
        Poly* operator*(const Poly &rhs);
        Poly& operator=(const Poly &rhs);
        const int size();
        void push_term(int coeff, int exp);

};
#endif /*Poly.h */ 
