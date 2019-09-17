//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H

template <class T>
class Node {
public:
    typedef T value_t;

protected:
    T value;

public:
    explicit Node(T value): value{value} {}

    template <class U>
    friend class Iterator;

    T& operator*() { return value; }

    ~Node() = default;
};

#endif //DOUBLYLINKEDLIST_NODE_H
