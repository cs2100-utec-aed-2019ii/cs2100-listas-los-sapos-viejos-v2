//
// Created by Gabriel Spranger Rojas on 2019-09-11.
//

#ifndef DOUBLYLINKEDLIST_ITERATOR_H
#define DOUBLYLINKEDLIST_ITERATOR_H

template <class N>
class Iterator {
public:
    typedef N node_t;
    typedef typename node_t::value_t value_t;

protected:
    node_t* node;

public:
    explicit Iterator(N* node = nullptr): node{node} {}

    // const functions are not allowed to change the object on which they are called

    virtual value_t& operator*() {
        return **node;
    }

    virtual bool operator==(const Iterator& i) const {
        return node == i.node;
    }

    virtual bool operator!=(const Iterator& i) const {
        return node != i.node;
    }

//    virtual Iterator& operator++() const {}
//    virtual Iterator& operator++(int) const {}
//
//    virtual Iterator& operator--() const {}
//    virtual Iterator& operator--(int) const {}

//    virtual bool operator<=(const Iterator& i) const {}
//
//    virtual bool operator>=(const Iterator& i) const {}
//
//    virtual bool operator>(const Iterator& i) const {}
//
//    virtual bool operator<(const Iterator& i) const {}
//
//    virtual void operator=(const value_t&) {}

    ~Iterator() = default;

};

#endif //DOUBLYLINKEDLIST_ITERATOR_H
