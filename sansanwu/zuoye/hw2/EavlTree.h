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
#include <iomanip>


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
        int node_height;
        int frequency;
        int depth;

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
        /*EavlNode Constructor Default node_height = 0  */
        EavlNode ( const Comp & elem, EavlNode *lt, EavlNode *rt, int h=0)
                :element(elem), left(lt), right(rt), node_height(h), frequency(1),depth(0){}
        friend class EavlTree<Comp>;


        /*REMOVE THIS SOON !  */
        friend std::ostream& operator<< ( std::ostream & os, const  EavlNode &T ){
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
        
        
};

template <class Comp>
class EavlTree {
public:
        explicit EavlTree (const Comp & notFound): root(NULL),
                ITEM_NOT_FOUND(notFound),
                tree_size(0) ,
                tree_height(0),
                total_finds(0),
                nodes_searched(0)
                {
                // if (find(notFound,root) == NULL)
                std::cout << "fix or remove NOT_FOUND "<<std::endl;
                //root = NULL;//new EavlNode<Comp>(notFound,NULL,NULL);
                // size = 0;
                //height = 0;
                //else
        };
        EavlTree( const EavlTree & rhs); //Copy Constructor
        ~EavlTree();  //Destructor


        void insert( const Comp & x );
        int remove( const Comp & x );
        int height() const;  /*INTEGER OVERALL HEIGHT OF TREE*/
        int int_pathlength() ; /*INTEGER INTERNAL PATH LENGTH OF TREE  */
        double ave_nodevisits() const; /* DOUBLE AVE. NODES VISITED BY FIND */
        int size()const; /*INTEGER NUMBER OF NODES IN TREE */
        void report ();      /*PRINTS THE METRICS FOR THE TREE  */
        
        /*FIXME: THESE ARE UNFINISHED */
        const Comp & findMin() const;
        const Comp & findMax() const;
        //const Comp & find( const Comp & target) const;
        int find( const Comp & target , int & freq) ;
        bool isEmpty() const;
        void display(std::ostream &os) const;

        
 
        
        int nodeFrequency( const Comp & target) const;

        std::ostream&   in_order(  std::ostream& os) ;
        
        void makeEmpty();
 
        
        const EavlTree & operator = ( const EavlTree & rhs );

        // FIXME:  gET THIS WORKING OSTREAM << OPERATOR FOR TEMPLATE
        template <typename X>
        friend std::ostream& operator<< (  std::ostream& os , const EavlTree<X>& T);

private:
        EavlNode<Comp> * root;
        /*Sentinel Value Representing an Item not present in Tree*/
        const Comp ITEM_NOT_FOUND;
        int tree_size; // Number of nodes in the tree
        int tree_height;
        int total_finds;
        int nodes_searched;
        
        int int_pathlength(EavlNode<Comp> *&t, int&  lengths);  /*INTEGER SUM OF PATH  */
        // I don't like this function CHANGE IT **********
        const Comp & elementAt ( EavlNode<Comp> *t ) const;
        // dont' use this !!!!


        const std::string toString( EavlNode<Comp> *&t) const;
        void insert( const Comp & x, EavlNode<Comp> *&t, int &freq) ;
        void remove( const Comp & x, EavlNode<Comp> *& t, int & freq ) ;
        
        EavlNode<Comp> *findMin( EavlNode<Comp> *t ) const;
        EavlNode<Comp> *findMax( EavlNode<Comp> *t ) const;
        int find( const Comp & x, EavlNode<Comp> *t, int & freq) const;

        
        void makeEmpty( EavlNode<Comp> *&t ) const; /*DELETES ENTIRE TREE */
        void printTree( std::ostream& os, EavlNode<Comp> *t ) const;  /*RECURSIVE PRINT*/

        /*DEBUGGING PRE-ORDER PRINT  */
        void preOrderPrint( std::ostream &os,  EavlNode<Comp> *t )const ;
        EavlNode<Comp> * clone( EavlNode<Comp> *t ) const; /*DEEP COPY*/
        int n_height( EavlNode<Comp> *t ) const;      /*HEIGHT OF A NODE*/

        /*THIS MAX FUNCTION ISN'T BEING USED!!!!!!!!! STD::MAX IS  */
        int max( int lhs, int rhs ) const;
        void rotateWithLeftChild( EavlNode<Comp> *& k2 ) const;
        void rotateWithRightChild( EavlNode<Comp> *& k1 ) const;
        void doubleWithLeftChild( EavlNode<Comp> *& k3 ) const;
        void doubleWithRightChild( EavlNode<Comp> *& k1 ) const;

        std::ostream  in_order( std::ostream& os, EavlNode<Comp> *& t);
        
        
};

/***************PUBLIC MEMBER FUNCTIONS: START HERE*****************/ 


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
/* Implementation of the overloaded << friend of EavlTree*/
template<class Comp>
void EavlTree<Comp>::report() {
        std::cout<<std::endl;
        std::cout<<std::setw(15)<< " "<< "EAVLTREE INSTANCE REPORT"<< std::endl;
        std::cout<<std::setw(15)<< " "<<std::setw(18)<<"size "<<"= "<< size()<<std::endl;
        std::cout<<std::setw(15)<< " "<<std::setw(18)<<"height "<<"= " << height()<<std::endl;
        std::cout<<std::setw(15)<< " "<<std::setw(18)<<"Int. Path Length "<<"= "<<int_pathlength()  <<std::endl;
        std::cout<<std::setw(15)<< " "<<std::setw(18)<<"Ave. Nodes hit with Find  " <<"= "<< ave_nodevisits()  <<std::endl;
        std::cout<<std::endl;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
int EavlTree<Comp>::int_pathlength(){
        int lengths = 0;
        int_pathlength(root,lengths );
        return lengths;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
double EavlTree<Comp>::ave_nodevisits()const{
        double nodes = double(nodes_searched);
        double finds = double(total_finds);
        //std::cout << "nodes searched =  "<<nodes<<std::endl;
        //std::cout << "finds = " <<finds<<std::endl;
        return nodes/finds;
        
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
int EavlTree<Comp>::size() const{
        return tree_size;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
std::ostream& operator<< (  std::ostream& os , const EavlTree<Comp> & T){

                os << std::endl;
                //int size = T.size;
                //os << "PRINTING EavlTree\n";
                T.display(os);
                return os;


}



/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
std::ostream&  EavlTree<Comp>:: in_order( std::ostream& os) {

       return  in_order( os,root);
}
	  


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
//Copy Constructor
template<class Comp>
EavlTree<Comp>::EavlTree( const EavlTree & rhs){

}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
//Destructor
template<class Comp>
EavlTree<Comp>:: ~EavlTree(){
        makeEmpty();

}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
int EavlTree<Comp>::nodeFrequency( const Comp & target) const{
        std::cout<< "FIXME: NEED TO FIND FIRST THEN OUTPUT"<<std::endl;
        return -999;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
int EavlTree<Comp>::height() const{
        return n_height(root);

}




/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
/*FIXME: STUBS   */
template<class Comp>
const Comp & EavlTree<Comp>::findMin() const{
        return findMin(root);
}

/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
const Comp & EavlTree<Comp>::findMax() const{

}




/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
/* FIXME:  MIGHT HAVE TO REWRITE TO MAKE MATCH THE PDF SPECS  */
template<class Comp>
int  EavlTree<Comp>::find( const Comp & target , int &freq ) {
        int found=1;
        //int freq=-1;
        total_finds++;
        //std::cout << "Entered Search for ["<<target<<"]"<<std::endl;
        found = find(target,root,freq);
        /*if (freq == 0){
                std::cout << target<<"\t"<<0;
                //std::cout<< ITEM_NOT_FOUND << std::endl;
                delete found;
                
        }
        */
        //std::cout << " found frequency ="<<found->frequency<<std::endl;
        std::cout<<target<<"\t"<<freq<<std::endl;
        nodes_searched+=found;
        return found;
}



/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
bool EavlTree<Comp>::isEmpty() const{
        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        if(root==NULL)
                return true;
        return false;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
void EavlTree<Comp>::display(std::ostream & os) const{
        printTree(os, root);
        std::cout<<std::endl;
        preOrderPrint(os,root);
}




/*DO YOU WANT A PUBLIC MAKE EMPTY?*/
/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
void EavlTree<Comp>::makeEmpty(){
        makeEmpty(root);
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION:
   Public wrapper for recursive insert method. 

  
 */
template<class Comp>
void EavlTree<Comp>::insert( const Comp & x ){
        //std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        int freq;
        insert( x, root , freq);
        std::cout<<x<<"\t"<< freq<<std::endl;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: remove ( x )
   --------------------------------------------------------------------
   DESCRIPTION:
   Public wrapper for recursive remove method.  

  
 */
template<class Comp>
int EavlTree<Comp>::remove( const Comp & x ) {
        int freq =-1;
        //std::cout << "remove called on ["<<x<<"]"<< std::endl;
        remove (x,root, freq);
        if (freq > 0 )
                std::cout << x << "\t"<<freq <<std::endl;
        else
                std::cout << x << "\t" << ITEM_NOT_FOUND<< std::endl;
        return freq;
}


/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
const EavlTree<Comp> & EavlTree<Comp>::operator=( const EavlTree & rhs ){
         std::cout << "FIXME: I'M NOT DONE"<< std::endl;
         return rhs;
}

        


/*************************************************************************************
                       PUBLIC MEMBER FUNCTIONS: END HERE
**************************************************************************************/ 




/*****************************************************************************************
                       PRIVATE MEMBER FUNCTIONS START HERE
******************************************************************************************/



/* FUNCTION: int_pathlength
   --------------------------------------------------------------------
   USAGE: int_pathlength( nodePtr );
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
int  EavlTree<Comp>::int_pathlength(EavlNode<Comp> *&t, int&  lengths){
        //int lenth = 0;
        if (t == NULL)
                return 0;
        //if (t != NULL){
        //       if (t->node_height>0){
        lengths++;

        std::cout<< "FIXME: TEST THIS AGAIN "<<std::endl;
                       
                        //         }
                        // }
        return int_pathlength(t->left, lengths)  + int_pathlength(t->right,lengths)+ lengths-1;
        
}
        

/* FUNCTION:
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
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


/* FUNCTION: find
   --------------------------------------------------------------------
   USAGE: find( string, nodePtr, freqRef );
   --------------------------------------------------------------------
   DESCRIPTION:
   Iterative find function called by public wrapper.  Returns the
   integer number of nodes searched for x.  Also, updates the frequency
   of using the frequency of the node holding x or 0 if x isn't in the
   tree. Iterative version found at the site below.  Just slightly different
   than the recursive version in the text book and class pdf.s
   http://www.uow.edu.au/~nabg/ABC/C24.pdf
 */
template<class Comp>
int EavlTree<Comp>::find( const Comp & x, EavlNode<Comp> *t, int & freq) const{
        int counter = 1;
        while ( t!= NULL){ 
                if ( x == t->element){
                        freq = t->frequency;
                        break;
                }
                else if( x < t->element){
                        counter++;
                        t  = t->left;
                }
                else if ( x> t->element){
                        counter++;
                        t = t->right;
                }
        }
        if(t== NULL){
                freq = 0;
        }
        return counter;
}

/* FUNCTION: findMin
   --------------------------------------------------------------------
   USAGE: findMin( nodePtr );
   --------------------------------------------------------------------
   DESCRIPTION: 
   Returns a pointer to the minimum element in the tree. Used in
   removal of elements. This is an iterative function, not
   recursive. 
 */
template<class Comp>
EavlNode<Comp> * EavlTree<Comp>::findMin( EavlNode<Comp> *t) const{
        // std::cout<<"ENTERING FINDMIN FUNCTION"<<std::endl;
        if( t!= NULL){
                while( t->left != NULL){
                        //std::cout<<t->element<<std::endl;
                        t = t->left;
                }
        }
        return t;
}


/* FUNCTION: n_height
   --------------------------------------------------------------------
   USAGE: n_height( nodePtr);
   --------------------------------------------------------------------
   DESCRIPTION:
   Returns the integer height of a node. Used in calculating the
   overall height of the tree and checking for imbalance.
 */
template<class Comp>
int EavlTree<Comp>::n_height( EavlNode<Comp> *t ) const{
        //std::cout<<"ENTERING HEIGHT FUNCTION"<<std::endl;
        if (t == NULL )
                return -1;
        if ( t->left == NULL && t->right==NULL)
                return 0;
        
        //std::cout<<"t->node_height="<<t->node_height<<std::endl;
        return t->node_height;
}


/* FUNCTION: makeEmpty
   --------------------------------------------------------------------
   USAGE: makeEmpty(nodePtr);
   --------------------------------------------------------------------
   DESCRIPTION:
   Called by wrapper function and by destructor.
   Empties the tree of elements and sets all pointers to NULL by
   recursive calls. 
 */
template<class Comp>
void EavlTree<Comp>::makeEmpty( EavlNode<Comp> *&t ) const{
        //std::cout<<"ENTERING MAKEEMPTY FUNCTION"<<std::endl;
        if ( t != NULL){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
        }       
        t = NULL;
}


/* FUNCTION: IS THIS STILL USED?
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
void EavlTree<Comp>::printTree( std::ostream &os,  EavlNode<Comp> *t )const {
        //std::cout << "FIXME: FIND A WAY WITHOUT STRING STREAM"<< std::endl;
        
        if( t!= NULL) {
                printTree(os,  t->left);
                os<<std::setiosflags(std::ios::left);
                os<<std::setw(15)<<(t->element)
                  << "("<<(t->frequency)<< ")"<<std::endl;
                //s << (t->element) << "\t";
                printTree( os,t->right);
        }
        //std::cout << std::endl;
        //std::cout <<"END OF TREE"<<std::endl;
}

/* FUNCTION: IS THIS STILL USED?
   --------------------------------------------------------------------
   USAGE: 
   --------------------------------------------------------------------
   DESCRIPTION: 

  
 */
template<class Comp>
void EavlTree<Comp>::preOrderPrint( std::ostream &os,  EavlNode<Comp> *t )const {
        //std::cout << "FIXME: FIND A WAY WITHOUT STRING STREAM"<< std::endl;
        
        if( t!= NULL) {
                os <<(t->element) << "("<<(t->frequency)<< ")"<<"h="<<t->node_height << std::endl;
                preOrderPrint(os,  t->left);
                
                //s << (t->element) << "\t";
                preOrderPrint( os,t->right);
        }
        //std::cout << std::endl;
        //std::cout <<"END OF TREE"<<std::endl;
}





/* FUNCTION: insert
   --------------------------------------------------------------------
   USAGE: insert( string, nodePtr);
   --------------------------------------------------------------------
   DESCRIPTION: 
   Called by the insert wrapper function.
   If x doesn't exist in tree, then create node for x and adjust tree
   size.  Otherwise, increase the frequency of x in the tree. Each
   nodes height is adjusted as the stack unwinds.
 */        
template<class Comp>
void EavlTree<Comp>::insert( const Comp &x, EavlNode<Comp> *&t , int & freq ) { //removed const to update tree_size
        // std::cout<< "ENTERING INSERT FUNCTION"<<std::endl;
        /*Base case */
        /*This Node doesn't exist in the tree*/
        if (t== NULL ){
                t = new EavlNode<Comp>( x, NULL, NULL );
                tree_size++; /*ADD ONE NODE TO SIZE  */
                freq = t->frequency;
                //std::cout<<x<<"\t"<< t->frequency<<std::endl;
                //std::cout << "node_height="<<t->node_height<<std::endl;
               
        }
        /* x goes left of root  */
        else if( x< t->element ){
                insert( x, t->left, freq );

                /* Balance Test  */
                if(n_height( t->left ) - n_height( t->right ) == 2 ){
                        if( x< t->left->element )
                                rotateWithLeftChild( t );
                        else
                                doubleWithLeftChild( t );
                }
        }
        /* x goes right of root  */
        else if ( x > t->element ){
                insert( x, t->right, freq );

                /* Balance Test */
                if( n_height(t->right) - n_height( t->left ) == 2){
                        if( x > t->right->element )
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }
        else  {/*DUPLICATE INCREASE FREQUENCY*/
                t->frequency++ ; 
                //std::cout<<x<<"\t"<< t->frequency<<std::endl;
               freq = t->frequency;
        }
        /*ADJUST HEIGHT OF NODE  */
        t->node_height = std::max( n_height( t->left ), n_height( t->right )) + 1;
        //std::cout<< "final height of t="<<t->node_height<<std::endl;
}


/* FUNCTION: remove
   --------------------------------------------------------------------
   USAGE: remove( string, nodePtr);
   --------------------------------------------------------------------
   DESCRIPTION:
   Called by the remove wrapper function.
   Removes the string from the tree by recussively searching for the
   right position and if found, and frequency = 1 remove the node,
   otherwise decrease the frequency by 1. Each nodes height is
   adjusted as the stack unwinds.
 */
template <class Comp>
void EavlTree<Comp>::remove( const Comp & x, EavlNode<Comp> *& t, int & freq ) { //removed const to update tree_size
        //std::cout<<"ENTERING REMOVE FUNCTION"<<std::endl;
        //int freq = -1;
        if (t == NULL )
                //can't delete from an empty tree or a non-existant node
                //freq = 0;
                return;

        /* Call remove on Left Subtree  */
        if ( x < t->element ){
                //delete from left subtree
                remove( x, t->left, freq );

                if( n_height( t->right )- n_height( t->left ) ==2 ){
                        /*Find the correct balance condition LL LR RL RR  */
                        if( n_height((t->right)->right) >= n_height((t->right)->left ))
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }
        /* Call remove on Right Subtree */
        else if( x > t->element ){
                remove( x,t->right, freq );
                /*Balance Test  */
                if (n_height( t->left )  - n_height( t->right ) ==2 ) {
                        if( n_height((t->left)->left) >= n_height((t->left)->right))
                                rotateWithLeftChild( t );
                        else
                                doubleWithLeftChild( t );
                }
        }
        /* Shazam delete this sucker or decrease frequency */
        else{
                //std::cout << "CORRECT NODE FOUND"<<std::endl;
                //std::cout <<t->element<<"\t"<<t->frequency<<std::endl;
                /*Found the word but frequency > 1 so decrease by 1  */
                if ( t->frequency > 1){
                        
                        t->frequency--;
                        freq = t->frequency;
                        //std::cout << x << "\t" << freq<<std::endl;
                        //std::cout <<" New Frequency of ["<<t->element<<"]("<<t->frequency<<")"<<std::endl;
                        return;
                }
                /*Both subtrees have stuff  */
                else  if(( t->left != NULL ) && (t->right != NULL )) {
                        /*REPLACE ELEMENT WITH INORDER SUCCESSOR
                          MUST UPDATE FREQUENCY FOR NEW POSITION OF
                          SUCCESSOR. AND SET FREQUENCY FOR REMOVAL OF
                          CORRECT NODE TO 1 FOR ALGORITHM TO FUNCTION.
                         */
                        std::cout << "Deleting Min Node for 2 Subtree"<<std::endl;
                        /*SET RETURN FREQUENCY TO 0 SINCE THE NODE IS BEING DELETED */
                        //freq = 0;
                        EavlNode<Comp> * flip = findMin(t->right);
                        t->element = flip->element;
                        t->frequency = flip->frequency;
                        flip->frequency  = 1;
                        // t->element = findMin(t->right)->element;
                        //std::cout << "t->element="<<t->element<<std::endl;
                        //findMin(t->right)->frequency++;
                       
                        /* REMOVE THE ELEMENT COPIED INTO THIS POSITION */
                        remove( t->element, t->right, freq );
                        /* Balance Test again  */
                        if (n_height( t->left ) - n_height( t->right ) == 2){
                                if( n_height((t->left)->left) >= n_height((t->left)->right))
                                        rotateWithLeftChild( t );
                                else
                                        doubleWithLeftChild( t );
                        }
                }
                else {
                        EavlNode<Comp> * oldNode = t;
                        t = (t->left != NULL) ? t->left:t->right;
                        delete oldNode;
                        tree_size--;  /*SUBTRACT ONE NODE FROM SIZE  */
                        freq = 0;
                        //std::cout << x << "\t" << 0<<std::endl;
                }
        }
        /*ADJUST HEIGHT OF NODE*/
        if (NULL != t)
                t->node_height = std::max( n_height(t->left ), n_height( t->right )) + 1;
        // std::cout << "LEAVING REMOVE"<<std::endl;
        //return ;
}

/* FUNCTION: rotateWithLeftChild
   --------------------------------------------------------------------
   USAGE: rotateWithLeftChild( nodePtr );
   --------------------------------------------------------------------
   DESCRIPTION: 
   Single rotation on node 2N.  2N->left gets a new pointer N, then 
   2N->left is shifted to point to N->right.  And N->right shifts to
   point at 2N.  Effectively reducing the size of the tree to its
   previous height.    
 */
template<class Comp>
void EavlTree<Comp>::rotateWithLeftChild( EavlNode<Comp> *& k2) const {
        std::cout<<"ENTERING ROTATE WITH LEFT CHILD"<<std::endl;
        EavlNode<Comp> *k1 = k2->left;
        k2->left = k1->right;
        k1->right= k2;
        k2->node_height= std::max( n_height( k2->left ), n_height( k2->right )) + 1;
        k1->node_height= std::max( n_height( k1->left ), k2->node_height ) + 1;
        k2 = k1;
}

/* FUNCTION: rotateWithRightChild
   --------------------------------------------------------------------
   USAGE: rotateWithRightChild( eavlNode );
   --------------------------------------------------------------------
   DESCRIPTION: 
   Single rotation on node N.  N->right gets a new pointer 2N, then 
   N->right is shifted to point to 2N->left.  And 2N->left shifts to
   point at N.  Effectively reducing the size of the tree to its
   previous height. 
 */
template<class Comp>
void EavlTree<Comp>::rotateWithRightChild( EavlNode<Comp> *&k1 ) const{
        std::cout<<"ENTERING ROTATE WITH RIGHT CHILD"<<std::endl;
        EavlNode<Comp> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->node_height = std::max( n_height( k1->left ), n_height( k1->right )) + 1;
        k2->node_height = std::max( n_height( k2->right ), k1->node_height) + 1;
        k1 = k2;
}


/*FIXME : UNDERSTAND THIS WELL   */
/* FUNCTION: doubleWithLeftChild
   --------------------------------------------------------------------
   USAGE: doubleWithLeftChild( eavlNode );
   --------------------------------------------------------------------
   DESCRIPTION: 
   Double rotation, 1st on left child of node, then on node itself.
  
 */
template<class Comp>
void EavlTree<Comp> ::doubleWithLeftChild( EavlNode<Comp> *& k3 ) const{
        //std::cout<<"ENTERING DOUBLE WITH LEFT CHILD"<<std::endl;
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );

}


/* FUNCTION: doubleWithRightChild
   --------------------------------------------------------------------
   USAGE: doubleWithRightChild( eavlNode);
   --------------------------------------------------------------------
   DESCRIPTION:
   Double rotation on right child of node then rotation on node itself. 

  
 */
template<class Comp>
void EavlTree<Comp>::doubleWithRightChild( EavlNode<Comp> *&k1 ) const {
        //std::cout<<"ENTERING DOUBLE WITH RIGHT CHILD"<<std::endl;
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
}

/****************PRIVATE MEMBER FUNCTIONS: END HERE****************
******************************************************************/


#endif /*Thats all*/
