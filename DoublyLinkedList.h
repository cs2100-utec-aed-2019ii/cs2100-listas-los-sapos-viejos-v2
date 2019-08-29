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

    T& front() { return head->get_value(); } // fails when size = 0

    T& back() { // fails when size = 0
        Node<T>* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        return cur->get_value();
    }

    T& operator [](int index) {
        Node<T>* cur = head;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
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
            Node<T>* aux = head; // point to head
            head = head->next; // set head to its next value
            delete aux; // delete the contents of the previous head
            return popped; // return a node with the old content of old head
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

    friend std::ostream& operator<< (std::ostream& os, const ForwardList& Lista){
        Node<T>* new_node = Lista.head;
        while (new_node != nullptr){
            os << new_node->value << " ";
            new_node = new_node->next;
        }
        os << "\n";
        return os;
    }

    void clear() {
        while(head != nullptr) {
            Node<T>* curr = head;
            head = head->next;
            delete curr;
        }
    }

    bool empty(){
        if(head==nullptr)
            return 1;
        else
            return 0;
    }

    // Destructor

    ~ForwardList() {
        clear();
    }

};


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
