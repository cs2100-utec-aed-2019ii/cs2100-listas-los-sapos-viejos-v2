//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H

template <class T>
struct Node {
    T value;
    Node* next = nullptr;

    Node() = default;
    explicit Node(T value): value{value} {}
};

#endif //DOUBLYLINKEDLIST_NODE_H
