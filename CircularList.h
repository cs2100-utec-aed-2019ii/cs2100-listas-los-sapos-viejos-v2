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
    Node<T>* get_head() {
        return HEAD;
    }

    Node<T>* get_tail() {
        return TAIL;
    }

    CircularList(CircularList<T>& another_list) {
        if (!another_list.is_empty()) {
            Node<T>* temp = another_list.get_head();
            for (int i = 0; i < another_list.get_size(); i++){
                push_back(temp->value);
                temp = temp->next;
            }
        }
    }

    CircularList(T* arr, const unsigned int& len) {
        for (int *p = arr; p < arr+len; ++p) {
            push_back(*p);
        }
    }

    explicit CircularList(Node<T>* node) {
        HEAD = TAIL = node;
        increase_size;
    }

    explicit CircularList(const int& n) {
        srand((unsigned)time(nullptr));
        for (int i = 0; i < n; ++i) {
            push_back((rand()%100)+1);
        }
    }

    CircularList() = default;

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
        if (SIZE == 0){
            return nullptr;
        } else if (SIZE == 1){
            Node<T>* deleted_node = new Node(TAIL->value);
            delete TAIL;
            TAIL = HEAD = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2){
            Node<T>* deleted_node = new Node(TAIL->value);
            delete TAIL;
            TAIL = HEAD;
            decrease_size;
            return deleted_node;
        } else {
            Node<T>* deleted_node = new Node(TAIL->value);
            Node<T>* temp = HEAD;
            while(temp->next != TAIL){ temp = temp->next; }
            delete TAIL;
            TAIL = temp;
            decrease_size;
            return deleted_node;
        }
    }

    Node<T>* pop_front() override {
        if (SIZE == 0){
            return nullptr;
        } else if (SIZE == 1){
            Node<T>* deleted_node = new Node(HEAD->value);
            delete HEAD;
            TAIL = HEAD = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2){
            Node<T>* deleted_node = new Node(HEAD->value);
            delete HEAD;
            HEAD = TAIL;
            decrease_size;
            return deleted_node;
        } else {
            Node<T>* deleted_node = new Node(HEAD->value);
            TAIL->next = HEAD->next;
            delete HEAD;
            HEAD = TAIL->next;
            decrease_size;
            return deleted_node;
        }
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

    Node<T>* find_node_at(const unsigned int& index) {
        Node<T>* cur = HEAD;
        for (unsigned int i = 0; i < index; ++i)
            cur = cur->next;
        return cur;
    }

    void erase(Node<T>* node_to_delete) override {

        if (node_to_delete == HEAD) {
            pop_front();
        } else if (node_to_delete == TAIL) {
            pop_back();
        } else {
            Node<T>* temp = HEAD;
            while (temp->next != node_to_delete) {
                temp = temp->next;
            }
            Node<T>* aux = temp->next; // aux points to the node to delete
            temp->next = temp->next->next;
            decrease_size;
            delete aux;
        }

    }

    void insert(Node<T>* reference_node, const T& value_to_insert) override {
        Node<T>* new_node = new Node(value_to_insert);
        if (reference_node == HEAD && reference_node == TAIL) {
            TAIL = new_node;
            HEAD->next = TAIL;
            TAIL->next = HEAD;
        } else {
            new_node->next = reference_node->next;
            reference_node->next = new_node;
        }
        increase_size;
    }

    void drop(const T& black_value) override {
        Node<T>* temp = HEAD;
        int size = SIZE;
        for(int i = 0; i < size; i++) {
            if (temp->value == black_value) {
                erase(temp);
            }
            temp = temp->next;
        }

    }

    CircularList& sort() override {
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

    CircularList& reverse() override {
        std::vector<T> reversed;
        int cont = 0;
        Node<T>* curr = HEAD;
        int size = SIZE;
        for (int i = 0; i < size; i++) {
            reversed.push_back(curr->value);
            curr = curr->next;
            ++cont;
        }
        this->clear();
        for (int i = 0; i < cont; ++i){
            push_front(reversed[i]);
        }
        return (*this);
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
