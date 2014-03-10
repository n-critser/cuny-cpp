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
        int height;

        AvlNode ( const Comp & elem, AvlNode *lt, AvlNode *rt, int h=0)
                :element(elem), left(lt), right(rt), height(h){}
        friend class AvlTree<Comp>;
};

template <class Comp>
class AvlTree {
public:
        explicit AvlTree (const Comp & notFound); 
        AvlTree( const AvlTree & rhs); //Copy Constructor
        ~AvlTree();  //Destructor

        const Comp & findMin() const;
        const Comp & findMax() const;
        const Comp & find( const Comp & target) const;
        bool isEmpty() const;
        void printTree() const;

        void makeEmpty();
        void insert( const Comp & x );
        void remove( const Comp & x );

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

        void makeEmpty( AvlNode<Comp> *&t ) const;
        void printTree( AvlNode<Comp> *t ) const;
        AvlNode<Comp> * clone( AvlNode<Comp> *t ) const;

        

        int height( AvlNode<Comp> *t ) const;
        int max( int lhs, int rhs ) const;
        void rotateWithLeftChild( AvlNode<Comp> *& k2 ) const;
        void rotateWithRightChild( AvlNode<Comp> *& k1 ) const;
        void doubleWithLeftChild( AvlNode<Comp> *& k3 ) const;
        void doubleWithRightChild( AvlNode<Comp> *& k1 ) const;
};


template<class Comp>
void AvlTree<Comp>::insert( const Comp &x, AvlNode<Comp> *&t ) const{
        if (t== NULL)
                t = new AvlNode<Comp>( x, NULL, NULL );
        /* x goes left of root  */
        else if( x< t->element ){
                insert( x, t->left );

                /* Balance Test  */
                if( height( t->left ) - height( t->right ) == 2 ){
                        if( x< t->left->element )
                                rotateWithLeftChile( t );
                        else
                                doubleWithLeftChile( t );
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
        t->height = max( height( t->left ), height( t->right )) + 1;
}


template <class Comp>
void AvlTree<Comp>::remove( const Comp & x, AvlNode<Comp> *& t ) const {
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
        k2->height= max( height( k2->left ), height( k2->right )) + 1;
        k1->height= max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
}

template<class Comp>
void AvlTree<Comp>::rotateWithRightChild( AvlNode<Comp> *&k1 ) const{
        AvlNode<Comp> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right )) + 1;
        k2->height = max( height( k2->right ), k1->height) + 1;
        k1 = k2;
}


/*FIXME : UNDERSTAND THIS WELL   */
template<class Comp>
void AvlTree<Comp> ::doubleWithLeftChild( AvlNode<Comp> *& k3 ) const{
        rotateWithRightChild( k3->left );
        rotateWithLeftChile( k3 );

}

template<class Comp>
void AvlTree<Comp>::doubleWithRightChild( AvlNode<Comp> *&k1 ) const {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
}










#endif /*Thats all*/
