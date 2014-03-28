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
        int node_height;
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
        /*EavlNode Constructor Default node_height = 0  */
        EavlNode ( const Comp & elem, EavlNode *lt, EavlNode *rt, int h=0)
                :element(elem), left(lt), right(rt), node_height(h), frequency(1){}
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
        void remove( const Comp & x );
        int height() const;  /*INTEGER OVERALL HEIGHT OF TREE*/
        int int_pathlength() const; /*INTEGER INTERNAL PATH LENGTH OF TREE  */
        double ave_nodevisits() const; /* DOUBLE AVE. NODES VISITED BY FIND */
        int size()const; /*INTEGER NUMBER OF NODES IN TREE */
        void report ();      /*PRINTS THE METRICS FOR THE TREE  */
        
        /*FIXME: THESE ARE UNFINISHED */
        const Comp & findMin() const;
        const Comp & findMax() const;
        //const Comp & find( const Comp & target) const;
        int find( const Comp & target , int & freq) ;
        bool isEmpty() const;
        void printTree(std::ostream &os) const;

        
 
        
        int nodeFrequency( const Comp & target) const;

        std::ostream&   in_order(  std::ostream& os) ;
        
        void makeEmpty();
 
        
        const EavlTree & operator = ( const EavlTree & rhs );
        // Function to output class to ostream
        
        //std::ostream& operator<< (  std::ostream& os, const EavlTree<Comp> & T );

        // FIXME:  gET THIS WORKING OSTREAM << OPERATOR FOR TEMPLATE
        template <typename X>
        friend std::ostream& operator<< (  std::ostream& os , const EavlTree<X>& T);


        /* TESTING  
        if (DEBUG == TRUE){
                bool assert_size ( int t_size ){
                        assert
        }

        */

private:
        EavlNode<Comp> * root;
        /*Sentinel Value Representing an Item not present in Tree*/
        const Comp ITEM_NOT_FOUND;
        int tree_size; // Number of nodes in the tree
        int tree_height;
        int total_finds;
        int nodes_searched;
        
        int int_pathlength(EavlNode<Comp> *&t)const;  /*INTEGER SUM OF PATH  */
        // I don't like this function CHANGE IT **********
        const Comp & elementAt ( EavlNode<Comp> *t ) const;
        // dont' use this !!!!


        const std::string toString( EavlNode<Comp> *&t) const;
        void insert( const Comp & x, EavlNode<Comp> *&t) ;
        void remove( const Comp & x, EavlNode<Comp> *& t ) ;
        
        EavlNode<Comp> *findMin( EavlNode<Comp> *t ) const;
        EavlNode<Comp> *findMax( EavlNode<Comp> *t ) const;
        EavlNode<Comp> *find( const Comp & x, EavlNode<Comp> *t, int & counter) const;

        
        void makeEmpty( EavlNode<Comp> *&t ) const; /*DELETES ENTIRE TREE */
        void printTree( std::ostream& os, EavlNode<Comp> *t ) const;  /*RECURSIVE PRINT*/
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

/* Implementation of the overloaded << friend of EavlTree*/
template<class Comp>
void EavlTree<Comp>::report() {
        std::cout<< "REPORT FOR EAVLTREE CLASS INSTANCE"<< std::endl;
        std::cout<< "size=" << size()<<std::endl;
        std::cout<< "height=" << height()<<std::endl;
        std::cout<< "Internal Path Length" << int_pathlength()<<std::endl;
        std::cout<< "Ave. Nodes hit with Find=" << ave_nodevisits()<<std::endl;


}

template<class Comp>
int EavlTree<Comp>::int_pathlength()const{
        return -999;
}

template<class Comp>
double EavlTree<Comp>::ave_nodevisits()const{
        double nodes = double(nodes_searched);
        double finds = double(total_finds);
        std::cout << "nodes searched="<<nodes<<std::endl;
        std::cout << "finds = " <<finds<<std::endl;
        return nodes/finds;
        
}

template<class Comp>
int EavlTree<Comp>::size() const{
        return tree_size;
}

template<class Comp>
std::ostream& operator<< (  std::ostream& os , const EavlTree<Comp> & T){

        //EavlNode<Comp> * temp = T.root;
                os << std::endl;
                //int size = T.size;
                os << "PRINTING EavlTree\n";
                //if ( temp != NULL)
                //      os << temp->left;
                // HOW TO TRAVERSE THE TREE AND OUTPUT THE STREAM
                //EavlNode<Comp> * start = T.root;
                
                //
                //

                T.printTree(os);
    
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
int EavlTree<Comp>::height() const{
        return n_height(root);

}
/*FIXME: STUBS   */
template<class Comp>
const Comp & EavlTree<Comp>::findMin() const{
        return findMin(root);
}
template<class Comp>
const Comp & EavlTree<Comp>::findMax() const{

}
template<class Comp>
int  EavlTree<Comp>::find( const Comp & target , int & freq) {
        int findCount=1;
        total_finds++;
        std::cout << "Entered Search for ["<<target<<"]"<<std::endl;
        EavlNode<Comp> * found = find(target,root,findCount);
        if (found == NULL){
                std::cout << "found ==NULL PUBLIC FIND"<<std::endl;
                std::cout<< ITEM_NOT_FOUND << std::endl;
                delete found;
                
        }
        //std::cout << " found frequency ="<<found->frequency<<std::endl;
        std::cout<<"findCount="<<findCount<<std::endl;
        nodes_searched+=findCount;
        return findCount;
}

template<class Comp>
bool EavlTree<Comp>::isEmpty() const{
        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        if(root==NULL)
                return true;
        return false;
}

template<class Comp>
void EavlTree<Comp>::printTree(std::ostream & os) const{
        printTree(os, root);
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

        std::cout << "remove called on ["<<x<<"]"<< std::endl;
        return remove (x,root);
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
        //std::stringstream  output="";
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


/* find
   -------------------------------------------------------------------
   Iterative find function called by the find(target) wrapper function
   -------------------------------------------------------------------
   Iterative version found at the site below.  Just slightly different
   than the recursive version in the text book and class pdf.s
   http://www.uow.edu.au/~nabg/ABC/C24.pdf
*/
template<class Comp>
EavlNode<Comp>* EavlTree<Comp>::find( const Comp & x, EavlNode<Comp> *t, int & counter) const{
        while ( t!= NULL){ 
                if ( x == t->element)
                        return t;
                else if( x < t->element){
                        counter++;
                        //std::cout<< "target = "<<x<<"\t t->element="<<t->element<<std::endl;
                        //find(x,t->left,counter);
                        t  = t->left;
                }
                else if ( x> t->element){
                        counter++;
                        //find(x,t->right,counter);
                        t = t->right;
                }
        }
        return NULL;
}


template<class Comp>
EavlNode<Comp> * EavlTree<Comp>::findMin( EavlNode<Comp> *t) const{
        std::cout<<"ENTERING FINDMIN METHOD"<<std::endl;
        if( t!= NULL){
                while( t->left != NULL){
                        std::cout<<t->element<<std::endl;
                        t = t->left;
                }
        }
        return t;


}

/*WHATS THIS FOR?   */
template<class Comp>
int EavlTree<Comp>::n_height( EavlNode<Comp> *t ) const{
        //std::cout<<"ENTERING HEIGHT METHOD"<<std::endl;
        if ( t == NULL)
                return 0;
        
        //std::cout<<"t->node_height="<<t->node_height<<std::endl;
        return t->node_height;
}

template<class Comp>
void EavlTree<Comp>::makeEmpty( EavlNode<Comp> *&t ) const{
        //std::cout<<"ENTERING MAKEEMPTY METHOD"<<std::endl;
        if ( t != NULL){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
        }       
        t = NULL;
}


template<class Comp>
void EavlTree<Comp>::printTree( std::ostream &os,  EavlNode<Comp> *t )const {
        //std::cout << "FIXME: FIND A WAY WITHOUT STRING STREAM"<< std::endl;
        
        if( t!= NULL) {
                printTree(os,  t->left);
                os << "T="<<(t->element) << "("<<(t->frequency)<< ")\t";
                //s << (t->element) << "\t";
                printTree( os,t->right);
        }
        //std::cout << std::endl;
        //std::cout <<"END OF TREE"<<std::endl;
}

        
template<class Comp>
void EavlTree<Comp>::insert( const Comp &x, EavlNode<Comp> *&t ) { //removed const to update tree_size
        // std::cout<< "ENTERING INSERT METHOD"<<std::endl;
        /*Base case */
        /*This Node doesn't exist in the tree*/
        if (t== NULL ){
                t = new EavlNode<Comp>( x, NULL, NULL );
                std::cout<<"INCREMENTING SIZE"<<std::endl;
                tree_size++; /*ADD ONE NODE TO SIZE  */
                //std::cout<< "initial node_height of t="<<t->node_height<<std::endl;
        }
        /* x goes left of root  */
        else if( x< t->element ){
                insert( x, t->left );

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
                insert( x, t->right );

                /* Balance Test */
                if( n_height(t->right) - n_height( t->left ) == 2){
                        if( x > t->right->element )
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }
        else
               t->frequency++ ; //duplicate increase frequency
        t->node_height = std::max( n_height( t->left ), n_height( t->right )) + 1;
        //std::cout<< "final height of t="<<t->node_height<<std::endl;
}


template <class Comp>
void EavlTree<Comp>::remove( const Comp & x, EavlNode<Comp> *& t ) { //removed const to update tree_size
        //std::cout<<"ENTERING REMOVE METHOD"<<std::endl;
        
        if (t == NULL )
                //can't delete from an empty tree
                return;

        /* Delete from Left Subtree  */
        if ( x < t->element ){
                //delete from left subtree
                remove( x, t->left );

                if( n_height( t->right )- n_height( t->left ) ==2 ){
                        /*Find the correct balance condition LL LR RL RR  */
                        if( n_height((t->right)->right) >= n_height((t->right)->left ))
                                rotateWithRightChild( t );
                        else
                                doubleWithRightChild( t );
                }
        }

        /* Delete from Right Subtree */
        else if( x > t->element ){
                remove( x,t->right );
                /*Balance Test  */
                if (n_height( t->left )  - n_height( t->right ) ==2 ) {
                        if( n_height((t->left)->left) >= n_height((t->left)->right))
                                rotateWithLeftChild( t );
                        else
                                doubleWithLeftChild( t );
                }
        }

        /* Shazam delete this sucker  */
        else{
                std::cout << "CORRECT NODE FOUND"<<std::endl;
                std::cout <<"Frequency of ["<<t->element<<"]("<<t->frequency<<")"<<std::endl;
                /*Found the word but frequency > 1 so decrease by 1  */
                if ( t->frequency > 1){
                        
                        t->frequency--;
                        std::cout <<" New Frequency of ["<<t->element<<"]("<<t->frequency<<")"<<std::endl;
                        return;
                }
                                
                /*Both subtrees have stuff  */
                else  if(( t->left != NULL ) && (t->right != NULL )) {
                        std::cout << "REMOVE WITH 2 SUBTREES"<<std::endl;
                        /*replace element  with next inorder successor */
                        t->element = findMin(t->right)->element;
                        /* get rid of the duplicate */
                        remove( t->element, t->right );
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
                }
        }
        if (NULL != t)
                t->node_height = std::max( n_height(t->left ), n_height( t->right )) + 1;
        // std::cout << "LEAVING REMOVE"<<std::endl;
}

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
template<class Comp>
void EavlTree<Comp> ::doubleWithLeftChild( EavlNode<Comp> *& k3 ) const{
        std::cout<<"ENTERING DOUBLE WITH LEFT CHILD"<<std::endl;
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );

}

template<class Comp>
void EavlTree<Comp>::doubleWithRightChild( EavlNode<Comp> *&k1 ) const {
        std::cout<<"ENTERING DOUBLE WITH RIGHT CHILD"<<std::endl;
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
}

/****************PRIVATE MEMBER FUNCTIONS: END HERE****************
******************************************************************/


#endif /*Thats all*/
