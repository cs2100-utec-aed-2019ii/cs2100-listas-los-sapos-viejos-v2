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
        Node<T>* new_node = new Node(element);
        if (size >= 2) {
            tail->next = new_node;
            tail = tail->next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (size == 1) {
            tail = new_node;
            head->next = tail;
            increase_size;
        }
    }

    void push_front(const T& element) override {
        Node<T>* new_node = new Node(element);
        if (size >= 2) {
            Node<T>* temp_head = head;
            Node<T>* temp_head_next = head->next;
            head = new_node;
            head->next = temp_head;
            temp_head->next = temp_head_next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (size == 1) {
            head = new_node;
            head->next = tail;
            increase_size;
        }
    }

    Node<T>* pop_back() override {
        if (size >= 3) {
            Node<T>* deleted_node = new Node(tail->value);
            Node<T>* aux = tail;
            tail = tail->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (size == 1) {
            Node<T>* deleted_node = new Node(tail->value);
            delete tail;
            tail = head = nullptr;
            decrease_size;
            return deleted_node;
        } else if (size == 2) {
            Node<T>* deleted_node = new Node(tail->value);
            delete tail;
            tail = head;
            head->next = nullptr;
            decrease_size;
            return deleted_node;
        }
    }

    Node<T>* pop_front() override {
        if (size >= 3) {
            Node<T>* deleted_node = new Node(head->value);
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (size == 1) {
            Node<T>* deleted_node = new Node(head->value);
            delete head;
            head = tail = nullptr;
            decrease_size;
            return deleted_node;
        } else if (size == 2) {
            Node<T>* deleted_node = new Node(head->value);
            delete head;
            head = tail;
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
            std::cout << "Deleted node with value: " << curr->value << std::endl;
            delete curr;
            head = head->next;
        }
        size = 0;
    }

    // Elimina un elemento de la lista en base a un puntero
    void erase(Node<T>* node_to_delete) override {

    }

    // Inserta un elemento en la lista en base a un puntero
    void insert(Node<T>* reference_node, const T& value) override {

    }

    // Elimina todos los elementos de la lista que tienen el valor igual al parametro
    void drop(const T& black_value) override {

    }

    ForwardList& sort() {

    }

    ForwardList& reverse() {

    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<< (std::ostream& os, const ForwardList<T>& fl) {

    }

    // push_back de un elemento
    inline friend ForwardList& operator<< (ForwardList<T>& self, const T& element_to_add) {

    }

    // pop_back de un elemento
    inline friend ForwardList& operator>> (ForwardList<T>& self, const T& element_to_delete) {

    }

    ~ForwardList() {
        clear();
    }

};

#endif //DOUBLYLINKEDLIST_FORWARDLIST_H
