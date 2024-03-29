
#ifndef DOUBLYLINKEDLIST_DOUBLELIST_H
#define DOUBLYLINKEDLIST_DOUBLELIST_H

#include "List.h"

#define head this->head
#define tail this->tail
#define size this->size
#define decrease_size --size
#define increase_size ++size;



template <typename T>
class DoubleList : public List<T> {


public:


    T& front() override {
        return head->value;
    }

    T& back() override {
        return tail->value;
    }

    void push_back(const T& element) override {
        auto* new_node = new Node<T>(element);
        if (size >= 2) {
            tail->next = new_node;
            auto aux = tail;
            new_node->previous=aux;
            tail = tail->next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (size == 1) {
            tail = new_node;
            head->next = tail;
            tail->previous = head;
            increase_size;
        }
    }

    void push_front(const T& element) override {
        auto* new_node = new Node<T>(element);
        if (size >= 2) {
            Node<T>* temp_head = head;
            Node<T>* temp_head_next = head->next;
            head = new_node;
            head->next = temp_head;
            temp_head->previous = head;
            temp_head->next = temp_head_next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (size == 1) {
            head = new_node;
            head->next = tail;
            tail->previous = head;
            increase_size;
        }
    }

    Node<T>* pop_back() override {
        if (size >= 3) {
            auto* deleted_node = new Node<T>(tail->value);
            Node<T>* aux = tail;
            tail = tail->previous;
            tail->next=nullptr;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (size == 1) {
            auto* deleted_node = new Node<T>(tail->value);
            delete tail;
            tail = head = nullptr;
            decrease_size;
            return deleted_node;
        } else if (size == 2) {
            auto* deleted_node = new Node<T>(tail->value);
            delete tail;
            tail = head;
            head->next = nullptr;
            decrease_size;
            return deleted_node;
        }
    }

    void print_backwards_test_to_test_previous_linking(){
        auto temp = tail;
        std::cout<<std::endl;
        while(temp->previous!=nullptr){
            std::cout<<temp->value<<" ";
            temp=temp->previous;
        }
        std::cout<<temp->value<<" ";


        std::cout<<std::endl;
    }
    void print_forward(){
        auto temp = head;
        std::cout<<std::endl;
        while(temp->next!=nullptr){
            std::cout<<temp->value<<" ";
            temp=temp->next;
        }
        std::cout<<temp->value<<" ";


        std::cout<<std::endl;
    }

    Node<T>* pop_front() override {
        if (size >= 3) {
            auto* deleted_node = new Node<T>(head->value);
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (size == 1) {
            auto* deleted_node = new Node<T>(head->value);
            delete head;
            head = tail = nullptr;
            decrease_size;
            return deleted_node;
        } else if (size == 2) {
            auto* deleted_node = new Node<T>(head->value);
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

    DoubleList& sort() {

    }

    DoubleList& reverse() {

    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<< (std::ostream& os, const DoubleList<T>& fl) {

    }

    // push_back de un elemento
    inline friend DoubleList& operator<< (DoubleList<T>& self, const T& element_to_add) {

    }

    // pop_back de un elemento
    inline friend DoubleList& operator>> (DoubleList<T>& self, const T& element_to_delete) {

    }
};


#endif //DOUBLYLINKEDLIST_DOUBLELIST_H
