//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_FORWARDLIST_H
#define DOUBLYLINKEDLIST_FORWARDLIST_H

#include "List.h"

#define head this->head
#define tail this->tail
#define size this->size
#define decrease_size --size
#define increase_size ++size;

template <typename T>
class ForwardList : public List<T> {

public:

    ForwardList() = default;

    T& front() override {
        return head->value;
    }

    T& back() override {
        return tail->value;
    }

    void push_back(const T& element) override {
        /// TODO
    }

    Node<T>* pop_back() override {
        /// TODO
    }

    void push_front(const T& element) override {
        if (size == 0) {
            head = tail = new Node(element);
            increase_size;
        } else if (size == 1) {
            head->next = tail;
            head = new Node(element);
            increase_size;
        } else {
            head->next = head;
            head = new Node(element);
            increase_size;
        }
    }

    Node<T>* pop_front() override {
        if (size == 0) {
            return head;
        } else if (size == 1) {
            Node<T>* deleted_node = new Node(head->value);
            Node<T>* aux = head;
            delete aux;
            head = tail = nullptr;
            decrease_size;
            return deleted_node;
        } else if (size == 2) {
            Node<T>* deleted_node = new Node(head->value);
            Node<T>* aux = head;
            delete aux;
            head = tail;
            decrease_size;
            return deleted_node;
        } else {
            Node<T>* deleted_node = new Node(head->value);
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            decrease_size;
            return deleted_node;
        }
    }

    unsigned int get_size() override {
        return size;
    }

    T& operator[](const unsigned int& index) override {
        Node<T>* cur = head;
        for (unsigned int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->value;
    }

    bool is_empty() override {
        return (size == 0);
    }

    void clear() override {
        while (head != nullptr) {
            Node<T>* curr = head;
            head = head->next;
            delete curr;
        }
    }

    void erase(Node<T>*) override {} // Elimina un elemento de la lista en base a un puntero
    void insert(Node<T>*, const T&) override {} // Inserta un elemento en la lista en base a un puntero
    void drop(const T&) override {} // Elimina todos los elementos de la lista que tienen el valor igual al parametro

    ForwardList& sort() {} // ordena la list
    ForwardList& reverse() {} // invierte la lista
//    template <typename __T>
//    inline friend std::ostream& operator<< (std::ostream& , const ForwardList<__T>& ) override {}  // Imprime la lista con cout
//    ​
//    template<typename __T>
//    inline friend ForwardList& operator<< (ForwardList<__T>&, const T& ) override {} // push_back de un elemento
//    ​
//    template<typename __T>
//    inline friend ForwardList& operator>> (ForwardList<__T>&, const T& ) override {} // pop_back de un elemento

};

#endif //DOUBLYLINKEDLIST_FORWARDLIST_H
