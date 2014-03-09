/*
 * PStack.h
 *
 *  Created on: Oct 26, 2013
 *      Author: chaos
 */

#ifndef PSTACK_H_
#define PSTACK_H_
#include<assert.h>

template <class T>
class PStack : public BaseStack<T>{
private:

	class Node {
		friend class PStack<T>;
	private:
		T	intel;
		Node*prev;
	public:
		Node( T d, Node* n=0) : intel(d), prev(n){};

	};
	Node * pntTop;
	int top;

public:
	PStack<T>():  pntTop(0),top(0) {};
	virtual ~PStack();
	virtual void push(const T  thing) throw (int);
	virtual bool isEmpty() const;
	virtual T pop() throw (int);
	virtual T getTop(T & stackTop) const throw (int);
};

template <class T>
PStack<T>::~PStack(){
	while(!isEmpty()){
		this->pop();
	}
}

template <class T>
void PStack<T>::push( const T  thing) throw (int){
	Node *node= new Node(thing, pntTop);// creates a new node and sets its prev to pntTop

	pntTop=node;//changes pntTop to point at new node
	top++;
	//pntTop->intel= *thing;
}

template<class T>
bool PStack<T>::isEmpty() const{
	return (top<=0);
}

template<class T>
T PStack<T>::pop() throw (int){
	if (top <= 0)
		throw -1;
	Node *temp= pntTop;
	pntTop=temp->prev;
	top--;
	return temp->intel;
}

template <class T>
T PStack<T>::getTop(T & stackTop) const throw (int){
	if (top <= 0)
		throw -1;
	return pntTop->intel;
}

#endif /* PSTACK_H_ */
