//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H

template <typename T>
class Node {
protected:
    T value;​
public:
    Node(T value) {
        this->value = value;
    }
    ​
    virtual ~Node() {

    }
};

#endif //DOUBLYLINKEDLIST_NODE_H
