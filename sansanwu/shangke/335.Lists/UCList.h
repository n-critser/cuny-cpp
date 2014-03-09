#ifndef UCLIST_H_
#define UCLIST_H_

#include <iostream>
#include <cstdlib>
#include <exception>
#include <cassert>
#include <new>
class UCList;
class Iterator;

class UNode{
public:
        UNode(std::string s);

private:
        std::string data;
        UNode* previous;
        UNode* next;

        friend class UCList;
        friend class Iterator;
};


class UCList{
public:
        UCList();
        void push_back(std::string s);

        void insert(Iterator iter, std::string s);

        Iterator erase(Iterator i);

        Iterator begin();

        Iterator end();

private:
        UNode* first;
        UNode* last;

};

class Iterator {
public:
        Iterator();

        std::string get() const;

        void next();

        void previous();
        bool equals( Iterator b) const;

private:
        UNode* position;
        UNode* last;
        friend class UCList;
};

UNode::UNode(std::string s){
        data = s;
        previous = NULL;
        next = NULL;
}

UCList::UCList(){
        first = NULL;
        last = NULL;
}

void UCList::push_back(std::string s){
        UNode* newnode = new UNode(s);
        if (last == NULL){
                first = newnode;
                last = newnode;
        }
        else {
                newnode->previous = last;
                last->next = newnode;
                last = newnode;
        }
}

void UCList::insert(Iterator iter, std::string s){
        if (iter.position == NULL){
                push_back(s);
                return;
        }

        UNode* after = iter.position;
        UNode* before = after->previous;
        UNode* newnode = new UNode(s);

        newnode->previous = before;
        newnode->next = after;
        after->previous = newnode;
        if (before == NULL)
                first = newnode;
        else
                before->next = newnode;
}

Iterator UCList::erase(Iterator i){
        Iterator iter = i;
        assert(iter.position != NULL);
        UNode* remove = iter.position;
        UNode* before = remove->previous;
        UNode* after = remove->next;
        if (remove == first)
                first = after;
        else
                before->next = after;
        iter.position = after;
        delete remove;
        return iter;
}

Iterator UCList::begin() {
        Iterator iter;
        iter.position = first;
        iter.last = last;
        return iter;
}

Iterator UCList::end() {
        Iterator iter;
        iter.position = NULL;
        iter.last = last;
        return iter;
}

Iterator::Iterator(){
        position = NULL;
        last = NULL;
}

std::string Iterator::get() const{
        assert(position != NULL);
        return position->data;
}

void Iterator::next(){
        assert(position != NULL);
        position = position->next;
}

void Iterator::previous(){
        if (position == NULL)
                position = last;
        else
                position = position->previous;
        assert(position != NULL);
}

bool Iterator::equals(Iterator b) const{
        return position == b.position;
}



#endif /* UCLIST_H_ */

