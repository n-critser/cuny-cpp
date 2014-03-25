/*******************************************************************************
  Title          : EavlTree.h
  Author         : Code originally from Stewart Weiss 
  Created on     : 
  Description    : EavlTree 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o 
  Modifications  : 

  FIXME          :  ROTATIONS... elementAt(), traversal, print, ...

*******************************************************************************/

#ifndef EAVLTREE_H_
#define EAVLTREE_H_
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>


template <class Comp>
class EavlTree;

template <class Comp>
class EavlNode;
template <class Comp>
std::ostream& operator<<( std::ostream& os, const EavlTree<Comp> & T );

template <class Comp>
std::ostream& operator<<( std::ostream & os, const EavlNode<Comp> & T );

template <class Comp>
class EavlNode{
        Comp element;
        EavlNode *left;
        EavlNode *right;
        /*height of a node*/
        int height;
        int frequency;

        const std::string toString() const{
                std::string output="";
                if (!NULL){
                        output+= "node=";
                        output+= element;
                        output+= "(";
                        output+= frequency;
                        output+= ")";
                }
                return output;
        }
        /*EavlNode Constructor Default Node height = 0  */
        EavlNode ( const Comp & elem, EavlNode *lt, EavlNode *rt, int h=0)
                :element(elem), left(lt), right(rt), height(h), frequency(1){}
        friend class EavlTree<Comp>;
        
        /*std::ostream& operator<< ( std::ostream & os, const  EavlNode &T ){
                       os << std::endl;
                       //int size = T.size;
                       os << "PRINTING EavlNode\n";
                       //os<< "node=";
                       // os<< T.element;
                       // os<< "(";
                       //os<< T.frequency;
                       //os<< ")";
                       //os << ;
                       return os;
                

        }
        */
        
};

template <class Comp>
class EavlTree {
public:
        explicit EavlTree (const Comp & notFound): ITEM_NOT_FOUND(notFound){
                // if (find(notFound,root) == NULL)
                std::cout << "fix or remove NOT_FOUND "<<std::endl;
                root = NULL;//new EavlNode<Comp>(notFound,NULL,NULL);
                //else
        }; 
        EavlTree( const EavlTree & rhs); //Copy Constructor
        ~EavlTree();  //Destructor

        /*FIXME: THESE ARE UNFINISHED */
        const Comp & findMin() const;
        const Comp & findMax() const;
        //const Comp & find( const Comp & target) const;
        const int find( const Comp & target , int & freq) const;
        bool isEmpty() const;
        void printTree() const;

        
        int nodeFrequency( const Comp & target) const;

        std::ostream&   in_order(  std::ostream& os) ;
        
        void makeEmpty();
        void insert( const Comp & x );
        void remove( const Comp & x );
        int treeHeight() const;  /*RETURNS OVERALL HEIGHT OF TREE*/
        const EavlTree & operator = ( const EavlTree & rhs );
        // Function to output class to ostream
        
        //std::ostream& operator<< (  std::ostream& os, const EavlTree<Comp> & T );

        // FIXME:  gET THIS WORKING OSTREAM << OPERATOR FOR TEMPLATE 
        friend std::ostream& operator<< <> (  std::ostream& os , const EavlTree<Comp> & T);
	  

private:
        EavlNode<Comp> * root;
        // Sentinel Value Representing an Item not present in Tree
        const Comp ITEM_NOT_FOUND;
        
        // I don't like this function CHANGE IT **********
        const Comp & elementAt ( EavlNode<Comp> *t ) const;
        // dont' use this !!!!


        const std::string toString( EavlNode<Comp> *&t) const;
        void insert( const Comp & x, EavlNode<Comp> *&t) const;
        void remove( const Comp & x, EavlNode<Comp> *& t ) const ;
        
        EavlNode<Comp> *findMin( EavlNode<Comp> *t ) const;
        EavlNode<Comp> *findMax( EavlNode<Comp> *t ) const;
        EavlNode<Comp> *find( const Comp & x, EavlNode<Comp> *t) const;

        
        void makeEmpty( EavlNode<Comp> *&t ) const; /*DELETES ENTIRE TREE */
        void printTree( EavlNode<Comp> *t ) const;  /*RECURSIVE PRINT*/
        EavlNode<Comp> * clone( EavlNode<Comp> *t ) const; /*DEEP COPY*/
        int height( EavlNode<Comp> *t ) const;      /*HEIGHT OF A NODE*/

        /*THIS MAX FUNCTION ISN'T BEING USED!!!!!!!!! STD::MAX IS  */
        int max( int lhs, int rhs ) const;
        void rotateWithLeftChild( EavlNode<Comp> *& k2 ) const;
        void rotateWithRightChild( EavlNode<Comp> *& k1 ) const;
        void doubleWithLeftChild( EavlNode<Comp> *& k3 ) const;
        void doubleWithRightChild( EavlNode<Comp> *& k1 ) const;

        std::ostream  in_order( std::ostream& os, EavlNode<Comp> *& t);
        
        
};

/***************PUBLIC MEMBER FUNCTIONS: START HERE*****************/ 

/* Implementation of the overloaded << friend of EavlTree*/
template<class Comp>
std::ostream& operator<<( std::ostream& os, const EavlTree<Comp> &T){
        os << std::endl;
  //int size = T.size;
  os << "PRINTING EavlTree\n";
  // HOW TO TRAVERSE THE TREE AND OUTPUT THE STREAM
  //EavlNode<Comp> * start = T.root;
  
  //
  os << T.in_order(os);
    
  return os;
}

template<class Comp>
std::ostream&  EavlTree<Comp>:: in_order( std::ostream& os) {

       return  in_order( os,root);
}
	  

//Copy Constructor
template<class Comp>
EavlTree<Comp>::EavlTree( const EavlTree & rhs){

}

//Destructor
template<class Comp>
EavlTree<Comp>:: ~EavlTree(){
        makeEmpty();

}

template<class Comp>
int EavlTree<Comp>::nodeFrequency( const Comp & target) const{
        std::cout<< "FIXME: NEED TO FIND FIRST THEN OUTPUT"<<std::endl;
        return -999;
}

template<class Comp>
int EavlTree<Comp>::treeHeight() const{
        return height(root);

}
/*FIXME: STUBS   */
template<class Comp>
const Comp & EavlTree<Comp>::findMin() const{
        return ITEM_NOT_FOUND;
}
template<class Comp>
const Comp & EavlTree<Comp>::findMax() const{

}
template<class Comp>
const int  EavlTree<Comp>::find( const Comp & target , int & freq) const{
        EavlNode<Comp> * found = find(target,root);
        if (found == NULL){
                std::cout<< ITEM_NOT_FOUND << std::endl;
                delete found;
        }
        std::cout<<"Frequncy of found="<<found->frequency<<std::endl;
        freq= found->frequency;
        return freq;
}

template<class Comp>
bool EavlTree<Comp>::isEmpty() const{
        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        if(root==NULL)
                return true;
        return false;
}

template<class Comp>
void EavlTree<Comp>::printTree() const{
        printTree(root);
}

/*DO YOU WANT A PUBLIC MAKE EMPTY?*/
template<class Comp>
void EavlTree<Comp>::makeEmpty(){
        makeEmpty(root);
}

template<class Comp>
void EavlTree<Comp>::insert( const Comp & x ){
        //std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        insert( x, root);

}

template<class Comp>
void EavlTree<Comp>::remove( const Comp & x ){

        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
}


template<class Comp>
const EavlTree<Comp> & EavlTree<Comp>::operator=( const EavlTree & rhs ){
         std::cout << "FIXME: I'M NOT DONE"<< std::endl;
         return rhs;
}

        


/***************PUBLIC MEMBER FUNCTIONS: END HERE******************
*******************************************************************/ 




/***************PRIVATE MEMBER FUNCTIONS: START HERE*****************/
template<class Comp>
std::ostream  EavlTree<Comp>::in_order( std::ostream& os, EavlNode<Comp> *& t){

        os << "CALLING IN_ORDER\n";
	if (t!= NULL){
		in_order(os, t->left);
		os<<t->element;
		in_order(os, t->right);
	}        
        return os;

}
/*        
template<class Comp>
const std::string EavlTree<Comp>::toString( EavlNode<Comp> *&t) const{
        std::string output="";
        if (t != NULL){
                output+= "node=";
                output+= t->element;
                output+= "(";
                output+= t->frequency;
                output+= ")";
        }
        return output;
                


}
*/
        
template<class Comp>
EavlNode<Comp>* EavlTree<Comp>::find( const Comp & x, EavlNode<Comp> *t) const{
        if (t !=NULL){
                if (x == t->element)
                        return t;
                else if( x < t->element)
                        find(x,t->left);
                else
                        find(x,t->right);
        }
        std::cout<<"ITEM_NOT_FOUND"<<std::endl;
        return NULL;

}
        
template<class Comp>
int EavlTree<Comp>::height( EavlNode<Comp> *t ) const{
        //std::cout<<"ENTERING HEIGHT METHOD"<<std::endl;
        if ( t == NULL)
                return 0;
        
        //std::cout<<"t->height="<<t->height<<std::endl;
        return t->height;
}

template<class Comp>
void EavlTree<Comp>::makeEmpty( EavlNode<Comp> *&t ) const{
        if ( t != NULL){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
        }       
        t = NULL;
}


template<class Comp>
void EavlTree<Comp>::printTree(  EavlNode<Comp> *t )const {
        //std::cout << "FIXME: FIND A WAY WITHOUT STRING STREAM"<< std::endl;
        
        if( t!= NULL) {
                printTree( t->left);
                std::cout << "T="<<(t->element) << "("<<(t->frequency)<< ")\t";
                //s << (t->element) << "\t";
                printTree( t->right);
        }
        //std::cout << std::endl;
        //std::cout <<"END OF TREE"<<std::endl;
}

        
template<class Comp>
void EavlTree<Comp>::insert( const Comp &x, EavlNode<Comp> *&t ) const{
        // std::cout<< "ENTERING INSERT METHOD"<<std::endl;
        /*Base case */
        if (t== NULL ){
                t = new EavlNode<Comp>( x, NULL, NULL );
                //std::cout<< "initial height of t="<<t->height<<std::endl;
        }
        /* x goes left of root  */
        else if( x< t->element ){
                insert( x, t->left );

                /* Balance Test  */
                if( height( t->left ) - height( t->right ) == 2 ){
                        if( x< t->left->element )
                                rotateWithLeftChild( t );
                        else
                                doubleWithLeftChild( t );
                }
        }
        /* x goes right of root  */
        else if ( x > t->element ){
                insert( x, t->right );

                /* Balance Test */
                if( height(t->right) - height( t->left ) == 2){
                        if( x > t->right->element )
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }
        else
               t->frequency++ ; //duplicate do nothing
        t->height = std::max( height( t->left ), height( t->right )) + 1;
        //std::cout<< "final height of t="<<t->height<<std::endl;
}


template <class Comp>
void EavlTree<Comp>::remove( const Comp & x, EavlNode<Comp> *& t ) const {
        std::cout<<"ENTERING REMOVE METHOD"<<std::endl;
        
        if (t == NULL )
                //can't delete from an empty tree
                return;

        /* Delete from Left Subtree  */
        if ( x < t->element ){
                //delete from left subtree
                remove( x, t->left );

                if( height( t->right )- height( t->left ) ==2 ){
                        /*Find the correct balance condition LL LR RL RR  */
                        if( height((t->right)->right) >= height((t->right)->left ))
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }

        /* Delete from Right Subtree */
        else if( x > t->element ){
                remove( x,t->right );
                /*Balance Test  */
                if (height( t->left )  - height( t->right ) ==2 ) {
                        if( height((t->left)->left) >= height((t->left)->right))
                                rotateWithLeftChild( t );
                        else
                                doubleWithLeftChild( t );
                }
        }

        /* Shazam delete this sucker  */
        else{
                /*Both subtrees have stuff  */
                if(( t->left != NULL ) && (t->right != NULL )) {
                        /*replace element  with next inorder successor */
                        t->element = findMin(t->right)->element;
                        /* get rid of the duplicate */
                        remove( t->element, t->right );
                        /* Balance Test again  */
                        if (height( t->left ) - height( t->right ) == 2){
                                if( height((t->left)->left) >= height((t->left)->right))
                                        rotateWithLeftChild( t );
                                else
                                        doubleWithLeftChild( t );
                        }
                }

                else {
                        EavlNode<Comp> * oldNode = t;
                        t = (t->left != NULL) ? t->left:t->right;
                        delete oldNode;
                }
        }
        if (NULL != t)
                t->height = max( height(t->left ), height( t->right )) + 1;
}

template<class Comp>
void EavlTree<Comp>::rotateWithLeftChild( EavlNode<Comp> *& k2) const {
        EavlNode<Comp> *k1 = k2->left;
        k2->left = k1->right;
        k1->right= k2;
        k2->height= std::max( height( k2->left ), height( k2->right )) + 1;
        k1->height= std::max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
}

template<class Comp>
void EavlTree<Comp>::rotateWithRightChild( EavlNode<Comp> *&k1 ) const{
        EavlNode<Comp> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = std::max( height( k1->left ), height( k1->right )) + 1;
        k2->height = std::max( height( k2->right ), k1->height) + 1;
        k1 = k2;
}


/*FIXME : UNDERSTAND THIS WELL   */
template<class Comp>
void EavlTree<Comp> ::doubleWithLeftChild( EavlNode<Comp> *& k3 ) const{
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );

}

template<class Comp>
void EavlTree<Comp>::doubleWithRightChild( EavlNode<Comp> *&k1 ) const {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
}

/****************PRIVATE MEMBER FUNCTIONS: END HERE****************
******************************************************************/


#endif /*Thats all*/
