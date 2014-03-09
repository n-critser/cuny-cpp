/*
 * BaseStack.h
 *
 *  Created on: Oct 25, 2013
 *      Author: chaos
 */

#ifndef BASESTACK_H_
#define BASESTACK_H_

//#include"StackException.h"
template <class T>
class BaseStack {
public:
	//BaseStack();
	virtual ~BaseStack() {} ;
	virtual void push(const T  thing)=0;
	virtual bool isEmpty() const =0  ;
	virtual T pop()=0;
	virtual T getTop(T & stackTop)const  =0;
};

#endif /* BASESTACK_H_ */
