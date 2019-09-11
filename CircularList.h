#ifndef DOUBLYLINKEDLIST_CIRCULARLIST_H
#define DOUBLYLINKEDLIST_CIRCULARLIST_H

#include <iostream>
#include "List.h"

#define HEAD this->head
#define TAIL this->tail
#define SIZE this->size
#define decrease_size --SIZE
#define increase_size ++SIZE



template <typename T>
class CircularList : public List<T> {
protected:

public:
    explicit CircularList(List<T>& another_list) {

    }

    explicit CircularList(T* arr) {

    }

    explicit CircularList(Node<T>* node) {

    }

    explicit CircularList(T n) {
        HEAD = TAIL = new Node(n);
    }

    CircularList() = default;

    void print()  {
        std::cout << "Head: " <<HEAD->value << std::endl;
        std::cout << "Tail: " <<TAIL->value << std::endl;

    }

    T& front() override {
        return HEAD->value;
    }

    T& back() override {
        return TAIL->value;
    }

    void push_back(const T& element) override {
        Node<T>* new_node = new Node(element);
        if (HEAD == nullptr){
            HEAD = TAIL = new_node;
            HEAD->next = HEAD;
            TAIL->next = HEAD;
            increase_size;
        } else if (HEAD == TAIL){
            TAIL = new_node;
            HEAD->next = TAIL;
            TAIL->next = HEAD;
            increase_size;
        } else {
            TAIL->next = new_node;
            TAIL = TAIL->next;
            TAIL->next = HEAD;
            increase_size;
        }
    }

    void push_front(const T& element) override {
        Node<T>* new_node = new Node(element);
        if (SIZE == 0){
            HEAD = TAIL = new_node;
            increase_size;
        } else if (SIZE == 1){
            HEAD = new_node;
            HEAD->next = TAIL;
            TAIL->next = HEAD;
            increase_size;
        } else if (SIZE >= 2){
            Node<T>* temp = HEAD;
            HEAD = new_node;
            HEAD->next = temp;
            TAIL->next = HEAD;
            increase_size;
        }
    }

    Node<T>* pop_back() override {

    }

    Node<T>* pop_front() override {

    }

    bool is_empty() override {
        return (SIZE == 0);
    }

    unsigned int get_size() override {
        return SIZE;
    }

    void clear() override {
        while (HEAD != TAIL) {
            Node<T>* curr = HEAD;
            //std::cout << "Deleted node with value: " << curr->value << std::endl;
            delete curr;
            HEAD = HEAD->next;
        }
        delete TAIL;
        HEAD = TAIL = nullptr;
        SIZE = 0;
    }

    void erase(Node<T>*) override {

    }

    void insert(Node<T>*, const T&) override {

    }

    void drop(const T&) override {

    }

    CircularList& sort() override {

    }

    CircularList& reverse() override {

    }

    //Busqueda por index
    T& operator[](const unsigned int& index) override {
        Node<T> *cur = HEAD;
        for (unsigned int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->value;

    }

    //Push_back
    inline friend CircularList& operator<< (CircularList<T>& self, const T& element_to_add) {
        self.push_back(element_to_add);
        return self;
    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<< (std::ostream& os, const CircularList<T>& fl){
        if (fl.size != 0) {
            std::cout << "Los valores son: ";
            Node<T>* temp = fl.head;
            for (unsigned int i = 0; i < fl.size; ++i) {
                os << temp->value << " ";
                temp = temp->next;
            }
            return os;
        } else {
            os << "Empty Circular List!";
            return os;
        }
    }





    ~CircularList(){
        clear();
    }
};

#endif //DOUBLYLINKEDLIST_CIRCULARLIST_H
