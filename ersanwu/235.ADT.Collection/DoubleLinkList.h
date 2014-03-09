/*
 * DoubleLinkList.h
 *
 *  Created on: Oct 23, 2013
 *      Author: chaos
 */

#ifndef DOUBLELINKLIST_H_
#define DOUBLELINKLIST_H_

#include "ABCList.hpp"
//TODO: RESEARCH why or not to use private nodes and proper usage
template<class T>
struct NodeL{
	T data;
	NodeL<T> * next;
	NodeL<T> * prev;
};

template<class T>
class DoubleLinkList : public ABCList<T> {

private:

	int size;
	NodeL<T>* head;
	//NodeL<T> dummyHead;
	NodeL<T> * find(const int pos);

public:
	virtual bool isEmpty();
	virtual int  getLength ();
	virtual void insert (int pos, T item) throw (int);
	virtual T    remove (int pos);
	virtual T    retrieve (int pos);
	// constructor makes a dummyHead node, head point to that and dummyHead points both ways to NULL

	DoubleLinkList();
	virtual ~DoubleLinkList();
	void insert(int pos, T &data) throw (int);
};

template<class T>
DoubleLinkList<T>::DoubleLinkList(){
	head = 0;
	size =0 ;
}

template<class T>
DoubleLinkList<T>::~DoubleLinkList(){
	while(!this->isEmpty()){
		remove(1);
	}
}

template<class T>
NodeL<T> * DoubleLinkList<T>::find(const int pos){
	if(pos<1 || pos>size)
		throw -1;
	NodeL<T> *curr=head;
	int i = 1;
	while (i < pos){
		//std::cout<< "i = "<< i << "pos= " << pos << std::endl;
		curr=curr->next;
		i++;
	}
	return curr;
}
template<class T>
int  DoubleLinkList<T>::getLength (){
	return size;
}

template<class T>
bool  DoubleLinkList<T>::isEmpty(){
	return (size <= 0);
}

template<class T>
T    DoubleLinkList<T>::remove (int pos){
	//FIXME
	if(pos<1 || pos>size)
		throw -1;
	NodeL<T>*curr;
	T temp;
	if (pos==1){
		curr=head;
		head=curr->next;
		//std::cout << "head data =  " << head->data << std::endl;
		temp = curr->data;
		delete curr;
		curr = 0;
		return temp;

	}else {
		std::cout << "pos= " << pos << std::endl;
		curr = find(pos);
		T stuff = curr->data;
		NodeL<T> *_prev=curr->prev;
		NodeL<T> *nextThing= curr->next;
		_prev->next=nextThing;
		if (_prev->next!=0)
			nextThing->prev= _prev;
		//TODO: delete pointers prev and next
		delete curr->next;
		curr =0;
		return stuff;
	}

}


template<class T>
	//FIXME:
T    DoubleLinkList<T>::retrieve (int pos){
	NodeL<T> *thing= find(pos);
	return thing->data;
}



template<class T>
void DoubleLinkList<T>::insert(int pos, T data) throw (int){
	if (pos < 1 || pos > size+1)
		throw -1;
	NodeL<T> *curr= new NodeL<T>;
	curr->data=data;
	curr->prev= 0;
	curr->next= 0;

	if (pos==1){
		curr->next=head;
		if (curr->next!=0)
			curr->next->prev=curr;
		head= curr;
	} else {
		NodeL<T>* prevPos= find (pos-1);
		curr->next=prevPos->next;
		prevPos->next=curr;
		if (curr->next!=0)
			curr->next->prev=curr;
	}
	size++;
}

#endif /* DOUBLELINKLIST_H_ */
