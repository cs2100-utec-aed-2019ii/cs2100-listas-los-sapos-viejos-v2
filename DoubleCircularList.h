//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_DOUBLECIRCULARLIST_H
#define DOUBLYLINKEDLIST_DOUBLECIRCULARLIST_H

#include "DoubleList.h"

// DoubleCircularList.h
template <typename T>
class DoubleCircularList : public List<T>{
protected:
    DoubleListNode<T> *head;
}

#endif //DOUBLYLINKEDLIST_DOUBLECIRCULARLIST_H
