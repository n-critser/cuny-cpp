/*
 * LinkedList.hpp
 *
 *  Created on: Oct 16, 2013
 *      Author: chaos
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_
#include "ABCList.hpp"
template <class T>
struct Node{
	T data;
	Node<T> * next;
};
template <class T>
class LinkedList : public ABCList<T> {
private:

	int size;
	Node<T>* head;

	Node<T> * find(const int pos);


public:
	LinkedList (void) : size(0), head(0) {}
	virtual ~LinkedList(void);
	virtual bool isEmpty () throw(int);
	virtual int  getLength ();
	virtual void insert (int pos, T item) throw(int);
	virtual T    remove (int pos) throw(int);
	virtual T    retrieve (int pos) throw(int);
};

template <class T>
LinkedList<T>::~LinkedList(){
	while(!this->isEmpty()){
		this->remove(1);
	}
}
template <class T>
Node<T>* LinkedList<T>::find (int pos){
	 Node<T> *curr = head;
	 int i = 1;
	 while (i<pos){
		 curr=curr->next;
		 i++;
	 }
	 return curr;
 }

template <class T>
bool LinkedList<T>::isEmpty (void) throw (int){
	if (size < 0) throw -1;
	 return (size==0);
 }


template <class T>
 int  LinkedList<T>::getLength (){
	 return size;
 }

template <class T>
 void LinkedList<T>::insert (int pos, T item) throw(int){
	if (pos < 0 || pos > size+1)
		throw -1;
	Node<T> *curr= new Node<T>;
	curr->data=item;
	curr->next=0;

	if (pos==1){
		curr->next= head;
		head=curr;
	} else {
		Node<T> *prev = find(pos-1);
		curr->next = prev->next;//error seg fault
		prev->next = curr;
	}
	size++;
	//return tData;
 }

template <class T>
 T    LinkedList<T>::remove (int pos) throw(int){
	if (pos<0 || pos> size)
		throw -1;
	if (size == 0)
		return 0;

	Node<T>* prev= find(pos-1);
	Node<T>* curr= prev->next;
	T tData = curr->data;
	prev->next= curr->next;
	curr->next=0;
	delete curr;
	curr = 0;
	size--;
	return tData;
	//return -1;
 }

template <class T>
 T    LinkedList<T>::retrieve (int pos) throw(int){
	//return -1;
	if (pos<0 || pos> size)
		throw -1;
	Node<T>* temp=find(pos);
	return temp->data;
 }
//template <class T>
//LinkedList<T>::LinkedList () : size(0) head(0){

//}





#endif /* LINKEDLIST_HPP_ */
