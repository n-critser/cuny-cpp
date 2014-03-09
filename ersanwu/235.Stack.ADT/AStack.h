/*
 * AStack.h
 *
 *  Created on: Oct 25, 2013
 *      Author: chaos
 */

#ifndef ASTACK_H_
#define ASTACK_H_

#define MAX 50

//#include "StackException.h"
#include "BaseStack.h"
template <class T>
class AStack : public BaseStack<T> {

private:
	T shit[MAX];
	int top;

public:
	AStack<T>();
	virtual ~AStack();
	virtual void push(const T thing) throw (int);
	virtual bool isEmpty() const;
	virtual T pop() throw (int);
	virtual T getTop(T & stackTop) const throw (int);
};
template <class T>
AStack<T>::AStack(): top(0){};

template <class T>
AStack<T>::~AStack() {
	while(!isEmpty())
		pop();
}

template <class T>
void AStack<T>::push(const T  thing) throw (int) {
	if (top >= MAX -1)
		throw -1;
	else{
		++top;
		shit[top]= thing;
	}


}

template <class T>
 T AStack<T>::pop() throw (int){
	if (this->isEmpty())
		throw -1;


	return shit[top--];
}

template <class T>
 T AStack<T>::getTop(T & stackTop) const throw (int){
	return shit[top];
}

template<class T>
bool AStack<T>::isEmpty() const{
	return top<=0;
}

#endif /* ASTACK_H_ */
