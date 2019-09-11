//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_FORWARDLIST_H
#define DOUBLYLINKEDLIST_FORWARDLIST_H

#include <cstdlib>
#include <ctime>

#include "List.h"

#define HEAD this->head
#define TAIL this->tail
#define SIZE this->size
#define decrease_size --SIZE
#define increase_size ++SIZE


template <typename T>
class ForwardList : public List<T> {

public:

    /// Constructores

    ForwardList() = default;

    // Constructor copia
    ForwardList(ForwardList& another_list) {
        if (!another_list.is_empty()) {
            Node<T>* temp = another_list.get_head();
            while (temp != nullptr) {
                push_back(temp->value);
                temp = temp->next;
            }
        }
    }

    // Constructor parametro, llena una lista a partir de un array​
    explicit ForwardList(T* arr, const unsigned int& len) {
        for (int *p = arr; p < arr+len; ++p) {
            push_back(*p);
        }
    }

    // Constructor por parametro, retorna una lista con un nodo
    explicit ForwardList(Node<T>* node) {
        HEAD = TAIL = node;
        increase_size;
    }

    // Constructor por parametro, retorna un lista de randoms de tamaño n
    explicit ForwardList(const int& n) {
        srand((unsigned)time(nullptr));
        for (int i = 0; i < n; ++i) {
            push_back((rand()%100)+1);
        }
    }

    /// Métodos de Acceso

    Node<T>* get_head() {
        return HEAD;
    }

    T& front() override {
        return HEAD->value;
    }

    T& back() override {
        return TAIL->value;
    }

    unsigned int get_size() override {
        return SIZE;
    }

    T& operator[](const unsigned int& index) override {
        Node<T>* cur = HEAD;
        for (unsigned int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->value;
    }

    Node<T>* find_node_with_value(const T& value) {
        Node<T>* cur = HEAD;
        while (cur->value != nullptr) {
            if (cur->value == value)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    /// Agregar y eliminar elementos

    void push_back(const T& element) override {
        Node<T>* new_node = new Node(element);
        if (SIZE >= 2) {
            TAIL->next = new_node;
            TAIL = TAIL->next;
            increase_size;
        } else if (is_empty()) {
            HEAD = TAIL = new_node;
            increase_size;
        } else if (SIZE == 1) {
            TAIL = new_node;
            HEAD->next = TAIL;
            increase_size;
        }
    }

    void push_front(const T& element) override {
        Node<T>* new_node = new Node(element);
        if (SIZE >= 2) {
            Node<T>* temp_head = HEAD;
            Node<T>* temp_head_next = HEAD->next;
            HEAD = new_node;
            HEAD->next = temp_head;
            temp_head->next = temp_head_next;
            increase_size;
        } else if (is_empty()) {
            HEAD = TAIL = new_node;
            increase_size;
        } else if (SIZE == 1) {
            HEAD = new_node;
            HEAD->next = TAIL;
            increase_size;
        }
    }

    Node<T>* pop_back() override {
        if (SIZE >= 3) {
            Node<T>* deleted_node = new Node(TAIL->value);
            Node<T>* aux = TAIL;
            TAIL = TAIL->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (SIZE == 1) {
            Node<T>* deleted_node = new Node(TAIL->value);
            delete TAIL;
            TAIL = HEAD = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2) {
            Node<T>* deleted_node = new Node(TAIL->value);
            delete TAIL;
            TAIL = HEAD;
            HEAD->next = nullptr;
            decrease_size;
            return deleted_node;
        }
    }

    Node<T>* pop_front() override {
        if (SIZE >= 3) {
            Node<T>* deleted_node = new Node(HEAD->value);
            Node<T>* aux = HEAD;
            HEAD = HEAD->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (SIZE == 1) {
            Node<T>* deleted_node = new Node(HEAD->value);
            delete HEAD;
            HEAD = TAIL = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2) {
            Node<T>* deleted_node = new Node(HEAD->value);
            delete HEAD;
            HEAD = TAIL;
            decrease_size;
            return deleted_node;
        }
    }

    bool is_empty() override {
        return (SIZE == 0);
    }

    void clear() override {
        while (HEAD != nullptr) {
            Node<T>* curr = HEAD;
            std::cout << "Deleted node with value: " << curr->value << std::endl;
            delete curr;
            HEAD = HEAD->next;
        }
        SIZE = 0;
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

    /// Miscelánea ( estos métodos retornan un ForwardList para que ambos se puedan encadenar: fl.reverse().sort() )

    ForwardList& sort() {

    }

    ForwardList& reverse() {

    }

    /// Sobrecarga de operadores

    // Imprime la lista con cout
    inline friend std::ostream& operator<< (std::ostream& os, const ForwardList<T>& fl) {
        if (fl.size != 0) {
            Node<T>* temp = fl.head;
            for (unsigned int i = 0; i < fl.size; ++i) {
                os << temp->value << " ";
                temp = temp->next;
            }
            return os;
        } else {
            os << "Empty Forward List!\n";
            return os;
        }
    }

    // push_back de un elemento
    inline friend ForwardList& operator<< (ForwardList<T>& self, const T& element_to_add) {
        self.push_back(element_to_add);
        return self;
    }

    // pop_back de un elemento
    inline friend ForwardList& operator>> (ForwardList<T>& self, const T& element_to_delete) {
        for (unsigned int i = 0; i < self.size; ++i) {
            if (self[i] == element_to_delete) {
                Node<T>* node_to_delete = self.find_node_with_value(element_to_delete);
                // TODO: call function that delete node passed as an argument
            }
        }
        return self;
    }

    /// Destructor

    ~ForwardList() {
        clear();
    }

};

#endif //DOUBLYLINKEDLIST_FORWARDLIST_H
