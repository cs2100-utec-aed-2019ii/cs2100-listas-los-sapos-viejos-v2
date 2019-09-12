//
// Created by Gabriel Spranger Rojas on 2019-09-11.
//

#ifndef DOUBLYLINKEDLIST_ITERATOR_H
#define DOUBLYLINKEDLIST_ITERATOR_H

#include "Node.h"

template <class N, class T>
class Iterator {
protected:
    N* node;

public:
    // const functions are not allowed to change the object on which they are called
    virtual Iterator&operator++() const = 0;
    virtual Iterator&operator++(int) const = 0;

    virtual Iterator&operator--() const = 0;
    virtual Iterator&operator--(int) const = 0;

    virtual T& operator*() = 0;

    virtual bool operator==(const Iterator&) const = 0;
    virtual bool operator!=(const Iterator&) const = 0;
    virtual bool operator<=(const Iterator&) const = 0;
    virtual bool operator>=(const Iterator&) const = 0;
    virtual bool operator>(const Iterator&) const = 0;
    virtual bool operator<(const Iterator&) const = 0;

    virtual void operator=(const T&) = 0;

};

#endif //DOUBLYLINKEDLIST_ITERATOR_H
