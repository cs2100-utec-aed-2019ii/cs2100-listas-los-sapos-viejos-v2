//
// Created by Gabriel Spranger Rojas on 2019-08-28.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <iostream>

template <class T>
struct Node {
    T value;
    Node* next = nullptr;

    Node() = default;
    explicit Node(T value): value{value} {}

    // Methods

    T& get_value() { return value; }
    void set_value(T new_value) { this->value = new_value; }

};

template <class T>
class ForwardList {
    Node<T>* head = nullptr;
    int size = get_size();
public:

    // Initializers

    ForwardList() = default;
    explicit ForwardList(T value) {
        head = new Node(value);
    }

    // Methods

    T& operator[](const int& index) {
        Node<T>* cur = head;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->value;
    }

    ForwardList<T>& sort() {
        int i, j;
        for (i = 0; i < this->get_size()-1; ++i) {
            for (j = 0; j < this->get_size()-i-1; ++j) {
                if ((*this)[j] > (*this)[j+1]) {
                    T temp = (*this)[j];
                    (*this)[j] = (*this)[j+1];
                    (*this)[j+1] = temp;
                }
            }
        }
        return (*this);
    }

    T& front() { return head->get_value(); } // fails when size = 0

    T& back() { // fails when size = 0
        Node<T>* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur->get_value();
    }

    int get_size() {
        Node<T> *cur = head;
        int size = 0;
        while (cur != nullptr) {
            ++size;
            cur = cur->next;
        }
        return size;
    }

    void push_front(T value) {
        Node<T>* new_node = new Node(value);

        if (head == nullptr) {
            head = new_node;
        } else {
            Node<T>* temp_head = head;
            Node<T>* temp_head_next = head->next;

            head = new_node;
            head->next = temp_head;
            temp_head->next = temp_head_next;
        }
    }

    void push_back(T value) {
        Node<T>* new_node = new Node(value);

        if (head == nullptr) { // size = 0
            head = new_node;
        } else if (head->next == nullptr) { // size = 1
            head->next = new_node;
        } else { // size = 2...∞
            Node<T>* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new_node;
        }
    }

    Node<T>* pop_front() {
        if (head == nullptr) {
            return head;
        } else {
            Node<T> deleted_node = Node(head->get_value());
            Node<T>* popped = &deleted_node;
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            return popped;
        }
    }

    Node<T>* pop_back() {
       if (head == nullptr) {
           return nullptr;
       } else if (head->next == nullptr) {
           T temp_value = head->get_value();
           Node<T> deleted_node = Node(temp_value);
           Node<T>* popped = &deleted_node;
           delete head;
           head = nullptr;
           return popped;
       } else {
           Node<T>* temp = head;
           while (temp->next->next != nullptr) {
               temp = temp->next;
           }
           // temp es el penultimo
           T temp_value = temp->next->get_value();
           Node<T> deleted_node = Node(temp_value);
           Node<T>* popped = &deleted_node;

           delete temp->next;
           temp->next = nullptr;

           return popped;
       }
    }

    void clear() {
        while(head != nullptr) {
            Node<T>* curr = head;
            head = head->next;
            delete curr;
        }
    }

    // Destructor

    ~ForwardList() {
        clear();
    }

};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
