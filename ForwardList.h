//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_FORWARDLIST_H
#define DOUBLYLINKEDLIST_FORWARDLIST_H

#include <cstdlib>
#include <ctime>
#include <vector>

#include "List.h"

#define SIZE this->size
#define decrease_size --SIZE
#define increase_size ++SIZE

template <typename T>
class ForwardListNode : public Node<T> {
    ForwardListNode<T>* next;
public:
    ForwardListNode(T value): Node<T>(value) {}
    template <class U>
    friend class ForwardList;
};

template <typename T>
class ForwardList : public List<T> {
    ForwardListNode<T>* head = nullptr;
    ForwardListNode<T>* tail = nullptr;
public:

    /// Constructores
    ForwardList() = default;

    // Constructor copia
    ForwardList(ForwardList& another_list) {
        if (!another_list.is_empty()) {
            ForwardListNode<T>* temp = another_list.get_head();
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
    explicit ForwardList(ForwardListNode<T>* node) {
        head = tail = node;
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

    ForwardListNode<T>* get_head() {
        return head;
    }

    T& front() override {
        return head->value;
    }

    T& back() override {
        return tail->value;
    }

    unsigned int get_size() override {
        return SIZE;
    }

    T& operator[](const unsigned int& index) override {
        ForwardListNode<T>* cur = head;
        for (unsigned int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->value;
    }

    ForwardListNode<T>* find_node_at(const unsigned int& index) {
        if (index < SIZE) {
            ForwardListNode<T>* cur = head;
            for (unsigned int i = 0; i < index; ++i)
                cur = cur->next;
            return cur;
        } else {
            return nullptr;
        }
    }

    /// Agregar y eliminar elementos

    void push_back(const T& element) override {
        ForwardListNode<T>* new_node = new ForwardListNode(element);
        if (SIZE >= 2) {
            tail->next = new_node;
            tail = tail->next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (SIZE == 1) {
            tail = new_node;
            head->next = tail;
            increase_size;
        }
    }

    void push_front(const T& element) override {
        ForwardListNode<T>* new_node = new ForwardListNode(element);
        if (SIZE >= 2) {
            ForwardListNode<T>* temp_head = head;
            ForwardListNode<T>* temp_head_next = head->next;
            head = new_node;
            head->next = temp_head;
            temp_head->next = temp_head_next;
            increase_size;
        } else if (is_empty()) {
            head = tail = new_node;
            increase_size;
        } else if (SIZE == 1) {
            head = new_node;
            head->next = tail;
            increase_size;
        }
    }

    ForwardListNode<T>* pop_back() override {
        if (SIZE >= 3) {
            ForwardListNode<T>* aux = tail;
            ForwardListNode<T>* deleted_node = new ForwardListNode(back());
            ForwardListNode<T>* temp = head;
            while (temp->next != tail) { temp = temp->next; }
            tail = temp;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (SIZE == 1) {
            ForwardListNode<T>* deleted_node = new ForwardListNode(tail->value);
            delete tail;
            tail = head = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2) {
            ForwardListNode<T>* deleted_node = new ForwardListNode(tail->value);
            delete tail;
            tail = head;
            head->next = nullptr;
            decrease_size;
            return deleted_node;
        }
    }

    ForwardListNode<T>* pop_front() override {
        if (SIZE >= 3) {
            ForwardListNode<T>* deleted_node = new ForwardListNode(head->value);
            ForwardListNode<T>* aux = head;
            head = head->next;
            delete aux;
            decrease_size;
            return deleted_node;
        } else if (is_empty()) {
            return nullptr;
        } else if (SIZE == 1) {
            ForwardListNode<T>* deleted_node = new ForwardListNode(head->value);
            delete head;
            head = tail = nullptr;
            decrease_size;
            return deleted_node;
        } else if (SIZE == 2) {
            ForwardListNode<T>* deleted_node = new ForwardListNode(head->value);
            delete head;
            head = tail;
            decrease_size;
            return deleted_node;
        }
    }

    bool is_empty() override {
        return (SIZE == 0);
    }

    void clear() override {
        if (head != nullptr && tail != nullptr) {
            while (head != tail) {
                ForwardListNode<T> *curr = head;
                std::cout << "Deleted node with value: " << curr->value << std::endl;
                delete curr;
                head = head->next;
            }
            delete tail;
            head = nullptr;
            tail = nullptr;
            SIZE = 0;
        }
    }

    // Elimina un elemento de la lista en base a un puntero
    void erase(ForwardListNode<T>* node_to_delete) {
        if (node_to_delete != nullptr) {
            if (node_to_delete == head) {
                pop_front();
            } else if (node_to_delete == tail) {
                pop_back();
            } else {
                ForwardListNode<T>* temp = head;
                while (temp->next != node_to_delete) {
                    temp = temp->next;
                }
                ForwardListNode<T> *aux = temp->next; // aux points to the node to delete
                temp->next = temp->next->next;
                delete aux;
                decrease_size;
            }
        }
    }

    // Inserta un elemento en la lista en base a un puntero
    void insert(ForwardListNode<T>* reference_node, const T& value_to_insert) {
        ForwardListNode<T>* new_node = new ForwardListNode(value_to_insert);
        if (reference_node == head && reference_node == tail) {
            head->next = new_node;
            tail = new_node;
            increase_size;
        } else {
            new_node->next = reference_node->next;
            reference_node->next = new_node;
            increase_size;
        }
    }

    // Elimina todos los elementos de la lista que tienen el valor igual al parametro
    void drop(const T& black_value) override {
        ForwardListNode<T>* temp = head;
        while (temp != nullptr) {
            if (temp->value == black_value) {
                erase(temp);
                decrease_size;
            }
            temp = temp->next;
        }
    }

    /// Miscelánea (estos métodos retornan un ForwardList para que ambos se puedan encadenar: fl.reverse().sort())

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

    ForwardList<T>& reverse() {
        std::vector<T> reversed;
        int cont = 0;
        ForwardListNode<T>* curr = head;
        unsigned int size = SIZE;
        for (unsigned int i = 0; i < size; ++i) {
            reversed.push_back(curr->value);
            curr = curr->next;
            ++cont;
        }
        this->clear();
        for (int i = 0; i < cont; ++i) {
            push_front(reversed[i]);
        }
        return *this;
    }

    /// Sobrecarga de operadores

    // Imprime la lista con cout
    inline friend std::ostream& operator<< (std::ostream& os, const ForwardList<T>& fl) {
        if (fl.size != 0) {
            ForwardListNode<T>* temp = fl.head;
            for (unsigned int i = 0; i < fl.size; ++i) {
                os << temp->value << " ";
                temp = temp->next;
            }
            return os;
        } else {
            os << "Empty Forward List!";
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
                ForwardListNode<T>* node_to_delete = self.find_node_with_value(element_to_delete);
                self.erase(node_to_delete);
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
