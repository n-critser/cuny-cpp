/*
  List.h
  Author: n-critser
  1.1.2014
*/
#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <cstdlib>
#include <exception>
template <typename Object>
class List{
private:
    struct Node{
        Object data;
        Node *prev;
        Node *next;

        Node( const Object & d = Object(), Node *pre = NULL, Node *nex = NULL):
            data( d ), prev( pre ), next( nex ) {}
    };

public:
    List(){
    if (0){
    public:
    class const_iterator {
    public:
            const_iterator() {
                    current = NULL;
            }

            const Object & operator* () const { return retrieve(); }

            const_iterator & operator++ () {
                    current = current->next;
                    return *this;
            }

            const_iterator operator++ ( int ) {
                    const_iterator old = *this;
                    ++( *this );
                    return old;
            }

            bool operator== ( const const_iterator & rhs ) const {
                    return current == rhs.current;
            }

        bool operator!= ( const const_iterator & rhs ) const {
            return !( *this == rhs );
        }
    protected:
        Node *current;
        
        const List<Object> *theList;
        
        Object & retrieve() const {
            return current->data;
        }

        const_iterator( const List<Object> *lst, Node *p ) {
                theList = lst;
                current = p;
        }

        void assertIsValid () const {
                if ( theList == NULL || current == NULL || current == theList->head)
                        throw ("Iterator out of Range");
                
        }
        friend class List<Object>;
    };

    class iterator : public const_iterator {
    public:
        iterator() {}

        Object & operator* () {
            return const_iterator::retrieve();
        }

        const Object & operator* () const {
            return const_iterator::operator*();
        }

        iterator & operator++ () {
            current = current->next;
            return *this;
        }

    protected:
        Node *current;
        List<Object> *theList;
        iterator(  List<Object> lst, Node *p ) {

                current = p;
                theList = lst;
        }

        friend class List<Object>;
    };
  

    
public:
    List () {};

            // if 0
            List(){
        init();
    }
    
    List( const List & rhs) {
        init();
        *this = rhs;
    }
    
    ~List() {
        clear();
        delete head;
        delete tail;
    }
    
    const List & operator=( const List & rhs ) {
        if( this == &rhs )
            return *this;
        clear();
        for( const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr )
            push_back( *itr );
        return *this;
    }

    iterator begin() {
            iterator itr( *this, head ) ;
            return ++itr;
    }
    const_iterator begin() const {
            const_iterator itr(*this, head  );// *this is pointer to a List, head is Node*
            return ++itr;
    }
    iterator end() { return iterator( tail ); }
    const_iterator end() const { return const_iterator( tail ); }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear(){
        while ( !empty() )
            pop_front();
    }

    Object & front() { return *begin(); }
    const Object & front () const { return *begin(); }
    
    Object & back() { return *--end(); }
    const Object & back() const { return *--end(); }

    void push_front( const Object & x ) {
        insert( begin(), x );
    }

    void push_back( const Object & x ) {
        insert( end(), x );
    }

    void pop_front() {
        erase( begin() );
    }

    void pop_back() {
        erase( --end() );
    }

    iterator insert( iterator itr, const Object & x ){
            itr.assertIsValid();
            if( itr.theList != this )
                    throw ("Incorrect List");
        Node *p = itr.current;
        theSize++;
        return iterator( p->prev = p->prev->next = new Node(x,p->prev, p ) );
    }

    iterator erase( iterator itr ) {
            if (itr.current == NULL){
                    return NULL;
            }
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        theSize--;
        return retVal;
    }

    iterator erase( iterator start, iterator to ) {
        for( iterator itr = start; itr!= to; )
            itr = erase( itr );
        return to;
    }

private:
    int theSize;
    Node *head;
    Node *tail;

    void init(){
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    }
};







#endif /* LIST_H_ */
