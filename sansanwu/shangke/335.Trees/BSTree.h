/*******************************************************************************
  Title          : BSTree.h
  Author         : n-critser 
  Created on     : [2014-02-16]
  Description    : Binary Search Tree Data Structure as per Stewart Weiss
  Purpose        : educational
  Usage          : ./EXECUTABLE
  Build with     : g++ -o 
  Modifications  : 
 
*******************************************************************************/
#ifndef BSTREE_H_
#define BSTREE_H_
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <sstream>


template <class Comp>
class BSTree;

template <class Comp>
class BinaryNode{
        Comp element;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode (const Comp & elem, BinaryNode *lt, BinaryNode *rt): element(elem),
                left(lt), right(rt) {}
        friend class BSTree<Comp>;
};

template<class Comp>
class BSTree{

public:
        explicit BSTree(const Comp & notFound);
        BSTree( const BSTree & rhs);
        ~BSTree();
        const Comp & findMin() const;
        const Comp & find( const Comp & x) const;
        bool isEmpty() const;
        void printTree(std::string &str) const;
        void insert( const Comp & x);
        void remove( const Comp & x)const ;
        const BSTree & operator= ( const BSTree & rhs);

private:
        BinaryNode<Comp> *root;
        const Comp ITEM_NOT_FOUND;
        const Comp & elementAt(BinaryNode<Comp> *t) const;
        void printTree(std::string &str, BinaryNode<Comp> *t) const;
        void insert( const Comp & x, BinaryNode<Comp> * & t)const;
        void remove( const Comp & x, BinaryNode<Comp> * & t)const;
        BinaryNode<Comp> * findMin(BinaryNode<Comp> *t) const;
        BinaryNode<Comp> * find(const Comp & x, BinaryNode<Comp> * t)const;
        BinaryNode<Comp> * clone( BinaryNode<Comp> * t) const;
        void clean( BinaryNode<Comp> *& t) const;
};

/* Constructor and Destructor  */
template <class Comp>
BSTree<Comp>::BSTree( const Comp & notFound): ITEM_NOT_FOUND(-1){
        
        if (find(notFound,root) == NULL)
                root = new BinaryNode<Comp>(notFound,NULL,NULL);
        else
                throw -1;
}

template <class Comp>
BSTree<Comp>::~BSTree<Comp>(){
        clean(root);
}
  



/* PRIVATE METHODS */

/* Method: elementAt
   ------------------
   FUNCTION: used by all public functions as an accessor to *root BinaryNode pointer
   USAGE:
   

 */
template <class Comp>
const Comp & BSTree<Comp>::elementAt(BinaryNode<Comp> *t)const{
        return t == NULL?ITEM_NOT_FOUND: t->element;
}

/* Method: find
   ---------------------
   Usage: find( x, root);
   Function: Finds the element x or NULL starting with the root of the tree
             and searching based on element values. 
   
  
 */
template <class Comp>
BinaryNode<Comp> *BSTree<Comp>::find( const Comp & x, BinaryNode<Comp> *t) const{
        /*  */

        if (t ==NULL)
                return NULL;
        /* x is less than value at root
           so look in the left subtree */
        else if( x< t->element )
                return find(x, t->left);
        /* x is greater than value at root
           so look in the right subtree */
        else if( x> t->element )
                return find(x, t->right);
        else
                return t;  //element x found
}


template<class Comp>
void BSTree<Comp>::insert ( const Comp& x, BinaryNode<Comp> *&t) const {
        if ( t==NULL)
                t = new BinaryNode<Comp>( x, NULL, NULL);
        else if ( x < t->element )
                return insert( x, t->left);
        else if ( x > t->element )
                return insert( x, t->right);
        else
                ;//Duplicate do nothing
}

template<class Comp>
BinaryNode<Comp>* BSTree<Comp>::findMin(BinaryNode<Comp> *t)const{
        if( t== NULL)
                return NULL;
        if( t->left== NULL )
                return t;
        return findMin(t->left);
}


template<class Comp>
void BSTree<Comp>::remove( const Comp &x, BinaryNode<Comp> *&t) const{
        if( t==NULL )
                return; //Item not found
        if( x < t->element )
                remove( x, t->left );
        else if( x > t->element )
                remove( x, t->right );
        else if( t->lef!=NULL && t->right!= NULL){ // Two children
                t->element= findMin(t->right)->element;
                remove( t->element,t->right );
        } else {
                BinaryNode<Comp> *oldNode = t;
                t = ( t->lef!=NULL ) ? t->left : t->right;
                delete oldNode;
        }
}


template <class Comp>
void BSTree<Comp>::clean( BinaryNode<Comp> *& t) const{
	if ( t != NULL){
		clean(t->left);
		clean(t->right);
		delete t;
	}
	t = NULL;
}


/* Recursive printTree:
 * Never used an ostream as argument so ? 
 * Should print inOrder as long as cout works on the object
 * Error Checking ? 
 * #include <sstream>

std::ostringstream s;
s << "select logged from login where id = " << ClientID;
std::string query(s.str());
 */
template <class Comp>
void BSTree<Comp>::printTree(std::string &str, BinaryNode<Comp>*t) const{
	std::ostringstream s;
        if ( t != NULL){
                printTree( str,t->left);
                std::cout << t->element << "\t";
                s<< t->element<< "\t";
                str+=s.str();
                printTree( str, t->right);
        }

}



/*END OF PRIVATE METHODS */

/*PUBLIC WRAPPER METHODS  */

template<class Comp>
const Comp & BSTree<Comp>::find( const Comp & x) const {
        return elementAt( find( x,root) );
}

template<class Comp>
void BSTree<Comp>::insert ( const Comp & x){
        insert( x, root);
}

template<class Comp>
const Comp & BSTree<Comp>::findMin()const{
        return elementAt( findMin( root ));
}


template<class Comp>
void BSTree<Comp>::remove( const Comp & x) const{
        return remove( x, root);
}


template<class Comp>
bool BSTree<Comp>::isEmpty() const{
	if( root != NULL)
		return false;
	return true;
}


template<class Comp>
void BSTree<Comp>::printTree(std::string &str) const{
  if (isEmpty())
    std::cout << "Tree is Empty\n";
  else 
          printTree( str, root);

}

/*END OF PUBLIC METHODS  */
















#endif /*Thats all*/
