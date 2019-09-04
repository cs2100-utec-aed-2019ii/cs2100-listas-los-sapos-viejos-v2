//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_CIRCULARLIST_H
#define DOUBLYLINKEDLIST_CIRCULARLIST_H

#include "ForwardList.h"

// CircuarList.h
template <typename T>
class CircularList : public List<T>{
protected:
    ForwardListNode<T> *head;
}

#endif //DOUBLYLINKEDLIST_CIRCULARLIST_H
