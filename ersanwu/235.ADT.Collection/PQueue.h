/*
 * Pqueue.h
 *
 *  Created on: Nov 2, 2013
 *      Author: chaos
 */

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include "BaseQueue.h"
template <class T>
class PQueue : public BaseQueue<T> {
	//class ABList : public ABCList<T> {
private:
	class Node {
		friend class PQueue<T>;
	private:
		T data;
		Node * next;

	public:
		Node (T _data, Node * _next=0): data(_data),next(_next){};
	};

	Node *back; 	//pointer to the back of the queue
	Node *front; 	//pointer to the front of the queue
public:
	PQueue<T>(): back(0),front(0){};
	PQueue<T>( PQueue<T> &queue);// copy constructor
	virtual ~PQueue();
	virtual void enqueue(T data);
	virtual T dequeue();
	virtual bool isEmpty();
	virtual T getFront();
};

template <class T>
PQueue<T>::PQueue( PQueue<T> &queue){
	while(!queue.isEmpty()){
		enqueue(queue.dequeue());
	}
}

template <class T>
PQueue<T>::~PQueue(){
	if(!isEmpty())
		dequeue();
}

template <class T>
void PQueue<T>::enqueue(T data){
	Node * Add = new Node(data);// new node created with node->next=0
	if(isEmpty()){
		front = Add;
		back = Add;
	}else{
		back->next=Add;
		back = Add;
	}
}

template <class T>
bool PQueue<T>::isEmpty(){
	if( front== 0) return true;
	return false;
}

template < class T>
T PQueue<T>::dequeue(){
	if(isEmpty())
		throw -1;
	T temp= front->data;
	Node * curr= front;
	if(front->next!=0)
		front=front->next;
	delete curr;
	curr=0;
	return temp;
}

template <class T>
T PQueue<T>::getFront(){
	return front->data;
}


#endif /* PQUEUE_H_ */
