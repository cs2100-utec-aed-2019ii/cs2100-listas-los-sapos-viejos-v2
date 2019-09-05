#ifndef DOUBLYLINKEDLIST_CIRCULARLIST_H
#define DOUBLYLINKEDLIST_CIRCULARLIST_H

#include <iostream>
#include "List.h"

template <typename T>
class CircularList : public List<T> {
protected:

public:
    CircularList(List<T>& another_list) {

    }

    CircularList(T* arr) {

    }

    CircularList(Node<T>* node) {

    }

    CircularList(T n) {
        this->head = this->tail = new Node(n);
    }

    void print()  {
        std::cout << this->head->value << std::endl;
    }

    CircularList() {

    }

    T& front() {

    }

    T& back(){

    }

    void push_back(const T& element){

    }

    void push_front(const T& element){

    }

    Node<T>* pop_back(){

    }

    Node<T>* pop_front(){

    }

    T& operator[] (const int&) {

    }

    bool is_empty() {

    }

    unsigned int get_size(){
        return 0;
    }

    void clear(){

    }

    void erase(Node<T>*){

    }

    void insert(Node<T>*, const T&){

    }

    void drop(const T&){

    }

//    CircularList& sort(){
//
//    }
//
//    CircularList& reverse() {
//
//    }
};

#endif //DOUBLYLINKEDLIST_CIRCULARLIST_H
