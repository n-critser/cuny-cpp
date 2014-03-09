/*
 * BinaryTree.h
 *
 *  Created on: Nov 23, 2013
 *      Author: chaos
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
//#define NULL 0
#include <cstdlib>
#include<iostream>
//template <class T>
//typedef void (*visit_function)(item_type &);

template <class T>

class BinaryTree {

private:
	//template <class T>
	class node{
	private:
		node(){};
		node(const T & node_item,
				node * left_tree = NULL,
				node * right_tree= NULL):
					item (node_item),
					left(left_tree),
					right(right_tree){}
		T 	item;
		node *left;
		node *right;
		friend class BinaryTree;
	};
	node * root;
	 // allows for pointer to function with a T reference
public:
	typedef void (*visit_function)(T &);
	BinaryTree<T>():root(NULL){};						//default constuctor
	BinaryTree<T>( const T & root_item);   //root item constuctor
	BinaryTree<T>( const T & root_item,
				BinaryTree<T> & left_tree,
				BinaryTree<T> & right_tree);// root plus left and right tree constuctor
	BinaryTree<T>( const BinaryTree & tree);//copy constructor
	virtual ~BinaryTree<T>();
	//Binary tree Methods and Operations
	int size() const;
	int height() const;
	T 	get_root() const;
	void set_root(const T & new_item);

	void attach_left(const T& new_item);
	void attach_right(const T& new_item);

	void attach_left_subtree(BinaryTree<T> & left_tree);
	void attach_right_subtree(BinaryTree<T> & right_tree);
	void detach_left_subtree(BinaryTree<T> & left_tree);
	void detach_right_subtree(BinaryTree<T> & right_tree);

	BinaryTree<T> get_left_subtree() const;
	BinaryTree<T> get_right_subtree() const;

	//traversals: (wrappers)
	void pre_order(visit_function visit);
	void in_order(visit_function visit);
	void post_order(visit_function visit);

	//
	virtual BinaryTree<T>& operator=(const BinaryTree<T> &rhs);

protected:


	BinaryTree<T> (node *nodePtr); // protected constructor
	void copy_tree(node *tree_ptr, node *& new_ptr)const ;
	//helper for destructor
	void destroy (node *& tree_ptr );
	node* get_root_ptr()const;

	//set root point
	void  set_root_ptr( node * new_root);
	void  get_childern(node *node_ptr,
						node *& left_child,
						node *& right_child) const;

	void set_children( node *node_ptr,
						node *left_child,
						node *right_child);

	int get_height(node *tree) const;
	int get_size( node *tree) const;


	void pre_order (node *treePtr, visit_function visit);
	void in_order (node *treePtr, visit_function visit);
	void post_order (node *treePtr, visit_function visit);


};

/*Public Constructors *************************************
 * Usage:  BinaryTree<type> tree1; /implemented above
 * 		   BinaryTree<type> tree2(item);
 * 		   BinaryTree<type> tree3(item,tree2,tree1);
 * *************************************************
 */
template<class T>
BinaryTree<T>::BinaryTree( const T & root_item){   //root item constuctor
	root = new node(root_item);

}
/* root and 2 trees constructor */
template<class T>
BinaryTree<T>::BinaryTree( const T & root_item,
							BinaryTree<T> & left_tree,
							BinaryTree<T> & right_tree){
	root = new node(root_item);
	attach_left_subtree(left_tree);
	attach_right_subtree(right_tree);

}
/* Copy Constructor */
template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree &tree){

	copy_tree(tree.root, root);
}

/*  End Constructors */

/*Desctructor***************************************
 * Usually not explicitly called.
 * destroy(root) method is called to do the pointer
 * deallocation and actual clean up.
 * *************************************************
 */
template<class T>
void BinaryTree<T>::destroy( node *& tree_ptr){
	// postorder traversal
	if ( tree_ptr != NULL ) {
		destroy (tree_ptr->left);
		destroy (tree_ptr->right);
		delete tree_ptr;
		tree_ptr = NULL;
	}
}

template <class T>
BinaryTree<T>::~BinaryTree(){
	destroy(root);
}
/* End Destructor */

/* Public Methods that Build or Alter a Tree
 * *******************************************
 * These methods are often wrappers for other
 * protected methods used internally.
 * *******************************************
 */
template <class T>
void BinaryTree<T>::set_root(const T & new_item){
	if (0!= size())
		root->item=new_item;
	else{
		root = new node(new_item);
	}
}

template <class T>
int BinaryTree<T>::size()const {
	if (root == NULL)
		return 0;
	else//TODO : CALCULATE THE CORRECT SIZE
		return 1;
}


template <class T>
int BinaryTree<T>::height( ) const {
	return get_height(root);
}


/*
 * Attach Left and Right items to a tree:
 * Should this just be attach item and recursively attach an item to the next
 * most available node with an open left or right
 */
template <class T>
void BinaryTree<T>::attach_left(const T & new_item){
	if(0==size())
		throw -1;
	else if( root->left != NULL)
		throw -1;
	else{
		root->left = new node(new_item);
	}
}

template <class T>
void BinaryTree<T>::attach_right(const T & new_item){
	if(0==size())
		throw -1;
	else if( root->right != NULL)
		throw -1;
	else{
		root->right = new node(new_item);
	}
}

/*SUBTREE ATTACH AND DETACH METHODS
 *
 */
template<class T>
void BinaryTree<T>::attach_left_subtree(BinaryTree<T> & left_tree){
	if (0 == size())
		throw -1;
	else if( root->left != NULL)
		throw -1;
	else{
		root->left = left_tree.root;
		left_tree.root = NULL;
	}
}


template<class T>
void BinaryTree<T>::attach_right_subtree(BinaryTree<T> & right_tree){
	if (0 == size())
		throw -1;
	else if( root->right != NULL)
		throw -1;
	else{
		root->right = right_tree.root;
		right_tree.root = NULL;
	}
}

template<class T>
void BinaryTree<T>::detach_left_subtree(BinaryTree<T>& left_tree){
	if (0 == size())
		throw -1;
	else {
		left_tree = BinaryTree<T>(root->left);
		root->left = NULL;
	}
}

template<class T>
void BinaryTree<T>::detach_right_subtree(BinaryTree<T>& right_tree){
	if (0 == size())
		throw -1;
	else {
		right_tree = BinaryTree<T>(root->right);
		root->right = NULL;
	}
}
/* END ATTACH AND DETACH METHODS */


/* GETTERS FOR LEFT AND RIGHT SUBTREES
 * *******************************************
 * TODO: test !!!
 * usage:
 * 		 tree2 = tree1.get_left_subtree();
 *
 */
template<class T>
BinaryTree<T> BinaryTree<T>::get_left_subtree() const{
	node *sub_tree_Ptr;
	if (0== size())
		return BinaryTree<T>();
	else{
		copy_tree(root->left, sub_tree_Ptr);
		return BinaryTree<T>(sub_tree_Ptr);
	}

}
template<class T>
BinaryTree<T> BinaryTree<T>::get_right_subtree() const{
	node *sub_tree_Ptr;
	if (0== size())
		return BinaryTree<T>();
	else{
		copy_tree(root->right, sub_tree_Ptr);
		return BinaryTree<T>(sub_tree_Ptr);
	}

}
/*  END OF GETTERS FOR SUBTREES */


/* PUBLIC TRAVERSAL METHODS
 * ****************************************************************
 * visit functions must be implemented by client:
 * void display(int & item){
 *	std::cout<< "item = " << item << std::endl;
 *	}
 * ****************************************************************
 * usage:
 * 		 tree2.in_order(display);
 */
template<class T>
void BinaryTree<T>::in_order(visit_function visit){
	in_order(root,visit);
}

template<class T>
void BinaryTree<T>::pre_order(visit_function visit){
	pre_order(root,visit);
}

template<class T>
void BinaryTree<T>::post_order(visit_function visit){
	post_order(root,visit);
}
/* END PUBLIC TRAVERSAL SECTION */

/*OVERLOADED "=" OPERATOR FOR ASSIGNMENT
 *
 */
template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T> &rhs){
	if(this != &rhs){
		destroy(root);
		copy_tree(rhs.root, root);
	}
	return *this;
}
/* END OPERATOR OVERLOADING */

/*************** END PUBLIC METHOD SECTION*************/



/* PROTECTED METHODS THAT BUILD OR ALTER TREES
 * *******************************************
 * These methods are often recursive.  They do
 * the work for the Public wrappers.
 * TODO: finish protected methods
 */

/* protected constructor
 *
 */
template <class T>
BinaryTree<T>::BinaryTree (node *nodePtr){ // protected constructor
	root = nodePtr;
}

template <class T>
void BinaryTree<T>::copy_tree(node *tree_ptr, node *& new_ptr)const{
	//pre order traversal
	if(tree_ptr != NULL) {
		new_ptr = new node(tree_ptr->item, NULL, NULL);
		copy_tree (tree_ptr->left, new_ptr->left);
		copy_tree (tree_ptr->right, new_ptr->right);
	}else
		new_ptr = NULL;
}

template <class T>
typename BinaryTree<T>::node* BinaryTree<T>::get_root_ptr()const{
	return root;
}

template <class T>//set root pointer
void  BinaryTree<T>::set_root_ptr( node * new_root){
	root = new_root;

}
template <class T>
void  BinaryTree<T>::get_childern(node *node_ptr,
					node *& left_child,
					node *& right_child) const{
	left_child =node_ptr->left;
	right_child = node_ptr->right;
}
template <class T>
void BinaryTree<T>::set_children( node *node_ptr,
					node *left_child,
					node *right_child){
	node_ptr->left = left_child;
	node_ptr->right = right_child;

}


template <class T>
int BinaryTree<T>::get_height(node *tree)const {
	//int max=0;
	if (NULL == tree)
		return 0;
	else {// max(int 1, int 2) returns the greater of the 2 ints?
		int side1 = get_height(tree->left);
		int side2 = get_height(tree->right);
		return 1+ (side1 > side2 ? side1:side2) ;
	}
}





/* PROTECTED TRAVERSALS START HERE:
 * Notice the only difference in the 3 functions is the order of the
 * recursive calls and/or calls to the visit function.  This matches
 * the order of the outputs desired from these traversals.
 * *******************************
 * The left subtree receives the first treatment for
 * in_order and post_order
 * The root comes first for
 * pre_order
 */
//In order recursive traversal
template <class T>
void BinaryTree<T>::in_order(node *treePtr, visit_function visit){
	if (treePtr!= NULL){
		in_order(treePtr->left, visit);
		visit(treePtr->item);
		in_order(treePtr->right,visit);
	}
}

template <class T>
void BinaryTree<T>::pre_order(node *treePtr, visit_function visit){
	if (treePtr!= NULL){
		visit(treePtr->item);
		in_order(treePtr->left, visit);
		in_order(treePtr->right,visit);
	}
}

template <class T>
void BinaryTree<T>::post_order(node *treePtr, visit_function visit){
	if (treePtr!= NULL){
		in_order(treePtr->left, visit);
		in_order(treePtr->right,visit);
		visit(treePtr->item);
	}
}

#endif /* BINARYTREE_H_ */
