/*
 * BinaryTree.h
 *
 *  Created on: Nov 23, 2013
 *      Author: chaos
 */

#ifndef BSTREE_H_
#define BSTREE_H_
//#define NULL 0
#include <cstdlib>
#include<iostream>
#include <sstream>
//template <class T>
//typedef void (*visit_function)(item_type &);

template <class T>

class BSTree {

private:
	//template <class N>
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
		friend class BSTree<T>;
	};
	node * root;
	 // allows for pointer to function with a T reference
public:
	typedef void (*visit_function)(T &);
	BSTree<T>():root(NULL){};		   //default constuctor
	BSTree<T>( const T & root_item);   //root item constuctor
	virtual ~BSTree<T>();

	const T & findMin() const;
	const T & findMax() const;
	bool contains(const T & item) const;
	bool isEmpty() const;
	void printTree(std::string &str) const;//TODO:
	void makeEmpty();
	bool isDegenerate() ;
	void insert(const T& item);
	void remove(const T& item);
	const BSTree<T> & operator=(const BSTree & rhs);

 protected:
	int height (node *& _node) const;
	bool isDegenerate( node *& _node) const ;
	void insert(const T& item, node *& _node) const;
	void remove(const T& item, node *& _node) const;
	void removeMin( node*& _node) const;
	bool contains(const T& item, node * _node) const;
	void makeEmpty( node * & _node) ;
	void printTree(node *  _node, std::string & str) const; //TODO:
	node * clone( node * _node) const;
	//Non recursive functions ** special **
	node * findMin(node* _node)const;
	node * findMax(node * _node) const;
		    
};

/*
 * ***************************************************
 * CONSTRUCTORS AND DESCTRUCTORS:
 * ***************************************************
 */
template <class T>
BSTree<T>::BSTree( const T & root_item){
	root = new node(root_item);
}
template <class T>
const BSTree<T> & BSTree<T>::operator=(const BSTree & rhs){
	if (this != rhs){
		makeEmpty();
		root = clone (rhs.root);
	}
	return *this;// this is a pointer so *this (derefrenced)
}
template <class T>
BSTree<T>::~BSTree<T>(){
	makeEmpty(root);
}

/* *******************************************************************
 * PUBLIC FUNCTIONS: MOST ARE WRAPPERS FOR
 * RECURSIVE PROTECTED FUNCTIONS
 * *******************************************************************
 */

template<class T>
bool BSTree<T>::contains(const T & item) const{
  return contains( item, root); 
}

template<class T>
bool BSTree<T>::isDegenerate() {
	return isDegenerate(root);
}

template<class T>
void BSTree<T>::insert(const T& item){
  return insert(item, root);
}

template<class T>
bool BSTree<T>::isEmpty() const{
	if( root != NULL)
		return false;
	return true;
}

template<class T>
void BSTree<T>::remove(const T& item){
  return remove(item,root);
}

template<class T>
void BSTree<T>::printTree(std::string &str) const{
  if (isEmpty())
    std::cout << "Tree is Empty\n";
  else 
    printTree(root, str);

}
/* ****************************************************************
 * PROTECTED FUNCTIONS:
 * RECURSIVE FUNCTIONS USED BY PUBLIC FUNCTIONS
 ******************************************************************
 */

template <class T>
typename BSTree<T>::node * BSTree<T>::clone( node * _node) const{
	if (_node == NULL)
		return NULL;
	return new node(_node,clone(_node->left),clone(_node->right));
}

template<class T>
bool BSTree<T>::isDegenerate(node *& _node) const{
	if( _node->left!=NULL && _node->right!=NULL)
		return false;
	else if(_node->left!=NULL && _node->right==NULL)
		return (true && isDegenerate(_node->left));
	else if(_node->left==NULL && _node->right!=NULL)
			return (true && isDegenerate(_node->right));
	else{ // BOTH LEFT AND RIGHT ARE NULL
		std::cout << "Reached Final Else in isDegenerate()"<<std::endl;
		return true;
	}
}

template <class T>
void BSTree<T>::makeEmpty( node * & _node) {
	if ( _node != NULL){
		makeEmpty(_node->left);
		makeEmpty(_node->right);
		delete _node;
	}
	_node = NULL;
}

template<class T>
bool BSTree<T>::contains(const T& item, node * _node) const{
    if( _node == NULL) 
      return false; //no match found , end of the tree 
    else if ( item < _node->item)
      return contains( item, _node->left);
    else if ( item > _node->item)
      return contains( item, _node->right);
    return true; //match found
}


template<class T>
void BSTree<T>::insert(const T& item, node *& _node) const{

	   if( _node == NULL)
	     _node = new node(item); //no match found , end of the tree
	    else if ( item < _node->item)
	      return insert( item, _node->left);
	    else if ( item > _node->item)
	      return insert( item, _node->right);
	    //FIXME : change to exceptional case
	    else ;//duplicate does nothing but returns 
}

/* removeMin:
 * *******************************************************
 * usage:  removeMin( _node);
 * *******************************************************
 * removes the smallest value in the tree rooted at _node
 *
 */
template<class T>
void BSTree<T>::removeMin(node *& _node) const{
	if ( _node == NULL)
		throw -1; //FIXME:  CHANGE TO INVALID ARGUMENT FROM #include<except> ?
	else if( _node->left !=NULL)
		removeMin(_node->left);
	else {
		node * tmp = _node;
		_node = _node->right;
		delete tmp;
	}
}

template <class T>
void BSTree<T>::remove(const T& item, node *& _node) const{
		std::cout<<"Removing : " << item << "\n";
		if ( _node == NULL)
			throw -1;
	    else if ( item < _node->item){
	    	std::cout<<"Item < "<< _node->item<< "\t";
	      return remove( item, _node->left);
	    }
	    else if ( item > _node->item){
	    	std::cout<<"Item > "<< _node->item<< "\t";
	      return remove( item, _node->right);
	    }
		//implicitly found : check if right and left are NULL
	    else if ( _node->left != NULL && _node->right != NULL){
	    	//get the pointer  to min value of right subtree
	    	std::cout<<"Item = "<< _node->item<< std::endl;
	    	// the item to be removed is replaced with the next logical item
	    	// then that item is removed by the call to remove below.
	    	// So this kind of remove is move of a reconoider.
	    	_node->item = findMin(_node->right)->item;
	    	std::cout<<"New item at this node= "<< _node->item << "\n";
	    	remove(_node->item, _node->right);
	    	// Falls through to the next statement
	    }else {

	    	node * oldNode = _node;
	    	_node = (_node->left != NULL) ? _node->left : _node->right;
	    	std::cout<<"update node  "<< _node<< std::endl;
	    	delete oldNode;
	    }
		std::cout<< std::endl;
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
template <class T>
void BSTree<T>::printTree( node * _node, std::string &str)const {
	std::ostringstream s;
  if (_node != NULL){
    printTree( _node->left, str);
    std::cout << _node->item << "\t";
    s<< _node->item<< "\t";
    str+=s.str();
    printTree( _node->right, str);
  }
  //std::cout<<std::endl;
}

/* ******************************************************************
 * findMin and findMax are not recurssive...just iterative loops
 * ******************************************************************
 * The site below gave me the information to make this function work
 * https://wiki.engr.illinois.edu/display/cs225/lab_trees
 * typename BSTree<T>::node * BSTree<T>::findMin(node * _node)const
 */
template <class T>
typename BSTree<T>::node * BSTree<T>::findMin(node * _node)const{
  if (_node != NULL)
    while( _node->left!=NULL)
      _node=_node->left;

  return _node;
    
}

template<class T>
typename BSTree<T>::node * BSTree<T>:: findMax(node* _node) const{
  if(_node != NULL)
    while (_node->right != NULL)
      _node= _node->right;

  return _node;

}

#endif /* BSTREE_H_ */
