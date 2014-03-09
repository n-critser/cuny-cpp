/*
 * BaseQueue.h
 *
 *  Created on: Nov 2, 2013
 *      Author: chaos
 */

#ifndef BASEQUEUE_H_
#define BASEQUEUE_H_


template <class T>
class BaseQueue {
public:

	virtual ~BaseQueue(){};
	virtual void enqueue(T data)=0;
	virtual T dequeue()=0;
	virtual bool isEmpty()=0;
	virtual T getFront()=0;
};

#endif /* BASEQUEUE_H_ */
