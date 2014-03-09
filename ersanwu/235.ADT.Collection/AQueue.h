/*
 * AQueue.h
 *
 *  Created on: Nov 2, 2013
 *      Author: chaos
 */

#ifndef AQUEUE_H_
#define AQUEUE_H_

#include "BaseQueue.h"
#define QMAX 10

template <class T>
class AQueue: public BaseQueue<T> {
private:
	T spam[QMAX];
	int back;
	int front;

public:
	AQueue<T>(): back(0),front(0) { }
	virtual ~AQueue();
	virtual void enqueue(T data);
	virtual T dequeue();
	virtual bool isEmpty();
	virtual T getFront();
};


template <class T>
AQueue<T>::~AQueue(){
	while (!isEmpty())
		dequeue();
}
template <class T>
void AQueue<T>::enqueue(T data){
	if ((back-front) >= QMAX)
		throw -1;
	spam[(back%QMAX)]=data;
	back++;
}

template <class T>
T AQueue<T>::dequeue(){
	if(isEmpty())
		throw -1;
	T temp= spam[(front%QMAX)];
	front++;
	return temp;
}

template <class T>
bool AQueue<T>::isEmpty(){
	return (front-back)==0;
}

template <class T>
T AQueue<T>::getFront(){
	return spam[(front%QMAX)];
}
#endif /* AQUEUE_H_ */
