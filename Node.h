//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H

template <class T>
class Node {
protected:
    T value;
public:
    Node(T value): value{value} {}
    ~Node() = default;
};

#endif //DOUBLYLINKEDLIST_NODE_H
