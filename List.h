//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_LIST_H
#define DOUBLYLINKEDLIST_LIST_H

#include "Node.h"

// List.h
template <typename T>
class List {
protected:
    Node<T> *head;
    ​
public:
    List(List another_list) { // Constructor copia

    }

    List(T* arr) { //Constructor  parametro, llena una lista a partir de un array

    }
    ​
    List(Node<T>* node) { //Constructor por parametro, retorna una lista con un nodo

    }
    ​
    List(int n) { //Constructor por parametro, retorna un lista de randoms de tamaño n

    }
    ​
    List() { // Constructor por defecto

    }
    ​
    T& front(void) = 0; // Retorna una referencia al primer elemento
    T& back(void) = 0; // Retorna una referencia al ultimo elemento

    void push_back(const T& element) = 0; // Inserta un elemento al final
    void push_front(const T& element) = 0; // Inserta un elemento al inicio
    ​
    Node<T>* pop_back(void) = 0; // Quita el ultimo elemento de la lista y retorna una referencia
    Node<T>* pop_front(void) = 0; // Quita el primer elemento de la lista y retorna una referencia
    ​
    T& operator[] (const int&); // devuelve el valor de un nodo en una posicion determinada

    bool empty(void) = 0; // la lista esta vacia?
    unsigned int size(void) = 0; // retorna el tamaño de la lista
    void clear(void) = 0; // Elimina toda la lista
    ​
    void erase(Node<T>*) = 0; // Elimina un elemento de la lista en base a un puntero
    void insert(Node<T>*, const T&) = 0; // Inserta un elemento en la lista en base a un puntero
    void drop(const T&) = 0; // Elimina todos los elementos de la lista que tienen el valor igual al parametro
    ​
    ForwardList& sort(void) = 0; // ordena la lista
    ForwardList& reverse(void) = 0; // invierte la lista
    ​
    template<typename __T>
    inline friend std::ostream& operator<< (std::ostream& , const ForwardList<__T>& ) = 0; // Imprime la lista con cout
    ​
    template<typename __T>
    inline friend ForwardList& operator<< (ForwardList<__T>&, const T& ) = 0; // push_back de un elemento
    ​
    template<typename __T>
    inline friend ForwardList& operator>> (ForwardList<__T>&, const T& ) = 0; // pop_back de un elemento

    virtual ~List() {
        clear();
    }
}


#endif //DOUBLYLINKEDLIST_LIST_H
