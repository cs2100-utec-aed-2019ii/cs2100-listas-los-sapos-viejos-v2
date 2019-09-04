//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_DOUBLELIST_H
#define DOUBLYLINKEDLIST_DOUBLELIST_H

#include "List.h"

// DoubleListNode.h
template <typename T>
class DoubleListNode : public Node<T>{
protected:
    Node<T> * next;
    Node<T> * prev;
    ​
public:
    Node(void){
    }
    ​
    ~Node(void){
    }
};

// DoubleList.h
template <typename T>
class DoubleList : public List<T>{
protected:
    DoubleListNode<T> *head;
    DoubleListNode<T> *tail;
    ​
}


#endif //DOUBLYLINKEDLIST_DOUBLELIST_H
