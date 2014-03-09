#ifndef _BRIZAN_ABLIST_H_
#define _BRIZAN_ABLIST_H_


#define LIST_MAX 500

#include "ABCList.hpp"
#include <iostream>

template <class T>
class ABList : public ABCList<T> {
private:
	int max;
	T    a [LIST_MAX];
	int  size;


public:
	     ABList<T> ();
	     ABList<T> (int _max);
	     virtual ~ABList();
	//virtual int  getSize();
	virtual void setMax(int Max);
	virtual bool isEmpty ()throw (int);
	virtual int  getLength () throw (int);
	virtual void insert (int pos, T item) throw(int);
	virtual T    remove (int pos) throw(int);
	virtual const T    retrieve (int pos)const throw(int);
	virtual T 	retrieve(int pos) throw(int);
};

template <class T>
ABList<T>::ABList () {
	size = 0;
	max = LIST_MAX;

}


template <class T>
ABList<T>::ABList(int _max){
	size = 0;
	max = _max;
}

template <class T>
ABList<T>:: ~ABList(){
	while (!this->isEmpty()){
		remove(1);

	}
}

template <class T>
void ABList<T>::setMax(int Max){
	max = Max;
}
template <class T>
bool ABList<T>::isEmpty () throw (int){
	if (size<0) throw -1;
	if (size == 0)
		return true;
	return false;
}

template <class T>
int ABList<T>::getLength () throw (int) {
	if (size<0) throw -1;
	return size;
}

template <class T>
void ABList<T>::insert (int pos, T item) throw (int ) {
	if (pos <= 0 || pos > size+1 || pos > max-1)
		throw -1;
	int addPos=pos-1;
  // Obviously not.
	if(size>0){
		for (int i=size-1; i >addPos; i--){// arr[0] = listPos(1) , arr[1] = listPos(2)
			//std::cout<< "reordering list in insert\n";
			a[i]= a[i-1];
		}
	}

	a[addPos] = item;
	//std::cout <<"incrementing size \n";
	++size;
}

template <class T>
T ABList<T>::remove (int pos) throw(int) {// shuffling is a problem
	if (pos <= 0 || pos > size)
		throw -1;
	T temp;
	int remPos=pos-1;
	try {
		 temp= a[pos-1];
		 //std::cout<< "temp: " <<temp << "\n";
	} catch (...){
		std::cout<< "error occured putting data into variable\n";
	}
	try {
		for (int i=remPos; i < size-1; i++){// arr[0] = listPos(1) , arr[1] = listPos(2)
			//std::cout << "i: "<<i<< "a[i]=" << a[i] << "\n";
			a[i]= a[i+1];
			//std::cout << "i: "<<i<< "a[i+1]=" << a[i+1] << "new value \n";
		}
	} catch(...){
		std::cout<< "error occured reordering list\n";
	}
	size--;
	return temp;
}

template <class T>
const T ABList<T>::retrieve (int pos)const throw(int) {
	if (pos <= 0 || pos > size)
		throw -1;
		//return -1;   // Obviously not.
	return a[pos - 1];
}

template <class T>
T ABList<T>::retrieve (int pos) throw (int){
	if (pos <= 0 || pos > size)
			throw -1;
			//return -1;   // Obviously not.
		return a[pos - 1];
}

#endif
