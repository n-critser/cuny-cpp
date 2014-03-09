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
	 const Node<T> * find (const int pos)const;

public:
	LinkedList<T> (void) : size(0), head(0) {}
	LinkedList<T> (LinkedList<T> &list);
	virtual ~LinkedList(void);
	virtual bool isEmpty () throw(int);
	virtual int  getLength ();
	virtual void insert (int pos, T item) throw(int);
	virtual T    remove (int pos) throw(int);
	virtual T    retrieve(int pos) throw (int);
	virtual const T    retrieve (int pos) const  throw(int) ;
	virtual LinkedList<T>& operator= (LinkedList<T> const & rhs);
	//virtual LinkedList<T> sort() throw (int);
};

template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &list): size(0), head(0){//doesn't this destroy the initial list

	for (int i =1; i<=list.size;i++){
		insert(size+1,list.retrieve(1));// removes the first list item iteratively
	}
}

template <class T>
LinkedList<T>& LinkedList<T>::operator= (LinkedList<T> const & rhs){
	while(size>1){
		remove(1);
	}
	//Node<T> *curr=rhs.head;

	for ( int i =1;i<=rhs.size;i++){
		insert(size+1,rhs.retrieve(i));
	}
	return *this;
}

template <class T>
LinkedList<T>::~LinkedList(){
	while(!this->isEmpty()){
		this->remove(1);
	}
}
//TODO: can this work on a template?
/*
template <class T>
LinkedList<T> LinkedList<T>::sort() throw (int){
	if (isEmpty())
		throw -1;
	LinkedList<T> list2;
	//Node<T> *curr = head;
	Node<T> *min=head;
	while ( list2.getLength() <= getLength()){
		for (int i = 1; i < getLength(); i++){
			//T temp = min->data;
			//if(temp > (find(i)->data))
				min = find(i);
		}
		list2.insert(list2.getLength()+1, min->data);

	}
	return list2;
}
*/
template <class T>
 Node<T>* LinkedList<T>::find (int pos) {
	 Node<T> *curr = head;
	 int i = 1;
	 while (i<pos){
		 curr=curr->next;
		 i++;
	 }
	 return curr;
 }

template<class T>
const Node<T> * LinkedList<T>::find (const int pos) const{
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
	if (pos<1 || pos > size)
		throw -1;
	Node<T>*curr =0;
	T tData;
	if( pos==1){
		curr=head;
		head = curr->next;
	}else{
		Node<T>* prev= find(pos-1);
		curr= prev->next;
		prev->next= curr->next;
		curr->next=0;
	}
	tData=curr->data;
	delete curr;
	curr = 0;
	size--;
	return tData;
	//return -1;
 }



template <class T>
T    LinkedList<T>::retrieve(int pos) throw (int){
	//return -1;
	if (pos<0 || pos> size)
		throw -1;
	Node<T>* temp=  find(pos);
	return temp->data;
}

template <class T>
 const T    LinkedList<T>::retrieve (int pos)const throw(int) {
	//return -1;
	if (pos<0 || pos> size)
		throw -1;
	const Node<T>* temp=  find(pos);
	return temp->data;
 }
//template <class T>
//LinkedList<T>::LinkedList () : size(0) head(0){

//}





#endif /* LINKEDLIST_HPP_ */
