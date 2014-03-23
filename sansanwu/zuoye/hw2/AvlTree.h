/*******************************************************************************
  Title          : AvlTree.h
  Author         : Code originally from Stewart Weiss 
  Created on     : 
  Description    : AVLtree 
  Purpose        : 
  Usage          : ./EXECUTABLE
  Build with     : g++ -o 
  Modifications  : 

  FIXME          :  ROTATIONS... elementAt(), traversal, print, ...

*******************************************************************************/

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>


template <class Comp>
class AvlTree;

template <class Comp>
class AvlNode{
        Comp element;
        AvlNode *left;
        AvlNode *right;
        /*height of a node*/
        int height;

        /*AvlNode Constructor Default Node height = 0  */
        AvlNode ( const Comp & elem, AvlNode *lt, AvlNode *rt, int h=0)
                :element(elem), left(lt), right(rt), height(h){}
        friend class AvlTree<Comp>;
};

template <class Comp>
class AvlTree {
public:
        explicit AvlTree (const Comp & notFound): ITEM_NOT_FOUND(notFound){
                // if (find(notFound,root) == NULL)
                std::cout << "fix or remove NOT_FOUND "<<std::endl;
                root = NULL;//new AvlNode<Comp>(notFound,NULL,NULL);
                //else
        }; 
        AvlTree( const AvlTree & rhs); //Copy Constructor
        ~AvlTree();  //Destructor

        /*FIXME: THESE ARE UNFINISHED */
        const Comp & findMin() const;
        const Comp & findMax() const;
        const Comp & find( const Comp & target) const;
        bool isEmpty() const;
        void printTree() const;

        void makeEmpty();
        void insert( const Comp & x );
        void remove( const Comp & x );
        int treeHeight() const;  /*RETURNS OVERALL HEIGHT OF TREE*/
        const AvlTree & operator = ( const AvlTree & rhs );

private:
        AvlNode<Comp> * root;
        // Sentinel Value Representing an Item not present in Tree
        const Comp ITEM_NOT_FOUND;
        
        // I don't like this function CHANGE IT **********
        const Comp & elementAt ( AvlNode<Comp> *t ) const;
        // dont' use this !!!!

        void insert( const Comp & x, AvlNode<Comp> *&t) const;
        void remove( const Comp & x, AvlNode<Comp> *& t ) const ;
        
        AvlNode<Comp> *findMin( AvlNode<Comp> *t ) const;
        AvlNode<Comp> *findMax( AvlNode<Comp> *t ) const;
        AvlNode<Comp> *find( const Comp * x, AvlNode<Comp> *t) const;

        
        void makeEmpty( AvlNode<Comp> *&t ) const; /*DELETES ENTIRE TREE */
        void printTree( AvlNode<Comp> *t ) const;  /*RECURSIVE PRINT*/
        AvlNode<Comp> * clone( AvlNode<Comp> *t ) const; /*DEEP COPY*/
        int height( AvlNode<Comp> *t ) const;      /*HEIGHT OF A NODE*/

        /*THIS MAX FUNCTION ISN'T BEING USED!!!!!!!!! STD::MAX IS  */
        int max( int lhs, int rhs ) const;
        void rotateWithLeftChild( AvlNode<Comp> *& k2 ) const;
        void rotateWithRightChild( AvlNode<Comp> *& k1 ) const;
        void doubleWithLeftChild( AvlNode<Comp> *& k3 ) const;
        void doubleWithRightChild( AvlNode<Comp> *& k1 ) const;
};

/***************PUBLIC MEMBER FUNCTIONS: START HERE*****************/ 
//Copy Constructor
template<class Comp>
AvlTree<Comp>::AvlTree( const AvlTree & rhs){

}

//Destructor
template<class Comp>
AvlTree<Comp>:: ~AvlTree(){
        makeEmpty();

}

template<class Comp>
int AvlTree<Comp>::treeHeight() const{
        return height(root);

}
/*FIXME: STUBS   */
template<class Comp>
const Comp & AvlTree<Comp>::findMin() const{
        return ITEM_NOT_FOUND;
}
template<class Comp>
const Comp & AvlTree<Comp>::findMax() const{

}
template<class Comp>
const Comp & AvlTree<Comp>::find( const Comp & target) const{

}

template<class Comp>
bool AvlTree<Comp>::isEmpty() const{
        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        if(root==NULL)
                return true;
        return false;
}

template<class Comp>
void AvlTree<Comp>::printTree() const{
        printTree(root);
}

/*DO YOU WANT A PUBLIC MAKE EMPTY?*/
template<class Comp>
void AvlTree<Comp>::makeEmpty(){
        makeEmpty(root);
}

template<class Comp>
void AvlTree<Comp>::insert( const Comp & x ){
        //std::cout << "FIXME: I'M NOT DONE"<< std::endl;
        insert( x, root);

}

template<class Comp>
void AvlTree<Comp>::remove( const Comp & x ){

        std::cout << "FIXME: I'M NOT DONE"<< std::endl;
}


template<class Comp>
const AvlTree<Comp> & AvlTree<Comp>::operator=( const AvlTree & rhs ){
         std::cout << "FIXME: I'M NOT DONE"<< std::endl;
         return rhs;
}

        


/***************PUBLIC MEMBER FUNCTIONS: END HERE******************
*******************************************************************/ 




/***************PRIVATE MEMBER FUNCTIONS: START HERE*****************/ 

template<class Comp>
int AvlTree<Comp>::height( AvlNode<Comp> *t ) const{
        //std::cout<<"ENTERING HEIGHT METHOD"<<std::endl;
        if ( t == NULL)
                return 0;
        
        //std::cout<<"t->height="<<t->height<<std::endl;
        return t->height;
}

template<class Comp>
void AvlTree<Comp>::makeEmpty( AvlNode<Comp> *&t ) const{
        if ( t != NULL){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
        }       
        t = NULL;
}


template<class Comp>
void AvlTree<Comp>::printTree(  AvlNode<Comp> *t )const {
        std::ostringstream s;
        //std::cout << "FIXME: FIND A WAY WITHOUT STRING STREAM"<< std::endl;
        
        if( t!= NULL) {
                printTree( t->left);
                std::cout << "T="<<(t->element) << "\t";
                //s << (t->element) << "\t";
                printTree( t->right);
        }
        //std::cout << std::endl;
        //std::cout <<"END OF TREE"<<std::endl;
}

        
template<class Comp>
void AvlTree<Comp>::insert( const Comp &x, AvlNode<Comp> *&t ) const{
        // std::cout<< "ENTERING INSERT METHOD"<<std::endl;
        /*Base case */
        if (t== NULL ){
                t = new AvlNode<Comp>( x, NULL, NULL );
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
                ; //duplicate do nothing
        t->height = std::max( height( t->left ), height( t->right )) + 1;
        //std::cout<< "final height of t="<<t->height<<std::endl;
}


template <class Comp>
void AvlTree<Comp>::remove( const Comp & x, AvlNode<Comp> *& t ) const {
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
                        AvlNode<Comp> * oldNode = t;
                        t = (t->left != NULL) ? t->left:t->right;
                        delete oldNode;
                }
        }
        if (NULL != t)
                t->height = max( height(t->left ), height( t->right )) + 1;
}

template<class Comp>
void AvlTree<Comp>::rotateWithLeftChild( AvlNode<Comp> *& k2) const {
        AvlNode<Comp> *k1 = k2->left;
        k2->left = k1->right;
        k1->right= k2;
        k2->height= std::max( height( k2->left ), height( k2->right )) + 1;
        k1->height= std::max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
}

template<class Comp>
void AvlTree<Comp>::rotateWithRightChild( AvlNode<Comp> *&k1 ) const{
        AvlNode<Comp> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = std::max( height( k1->left ), height( k1->right )) + 1;
        k2->height = std::max( height( k2->right ), k1->height) + 1;
        k1 = k2;
}


/*FIXME : UNDERSTAND THIS WELL   */
template<class Comp>
void AvlTree<Comp> ::doubleWithLeftChild( AvlNode<Comp> *& k3 ) const{
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );

}

template<class Comp>
void AvlTree<Comp>::doubleWithRightChild( AvlNode<Comp> *&k1 ) const {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
}

/****************PRIVATE MEMBER FUNCTIONS: END HERE****************
******************************************************************/


#endif /*Thats all*/
