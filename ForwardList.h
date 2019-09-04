//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_FORWARDLIST_H
#define DOUBLYLINKEDLIST_FORWARDLIST_H

#include "List.h"

// ForwardListNode.h
template <typename T>
class ForwardListNode : public Node<T> {
protected:
    Node<T> * next;
    ​
public:
    Node(void){
    }
    ​
    ~Node(void){
    }
};

// ForwardList.h
template <typename T>
class ForwardList : public List<T>{
protected:
    ForwardListNode<T>* head;
    ForwardListNode<T>* tail;
    ​
}

#endif //DOUBLYLINKEDLIST_FORWARDLIST_H
