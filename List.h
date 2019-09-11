//
// Created by Gabriel Spranger Rojas on 2019-09-03.
//

#ifndef DOUBLYLINKEDLIST_LIST_H
#define DOUBLYLINKEDLIST_LIST_H

#include <iostream>

#include "Node.h"

// List.h
template <typename T>
class List {
protected:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    unsigned int size = 0;
public:
    List() = default; // Constructor por defecto​
    explicit List(List& another_list) {} // Constructor copia
    explicit List(T* arr, const unsigned int& len) {} //Constructor  parametro, llena una lista a partir de un array​
    explicit List(Node<T>* node) {} //Constructor por parametro, retorna una lista con un nodo
    explicit List(const int& n) {} //Constructor por parametro, retorna un lista de randoms de tamaño n

    virtual T& front() = 0; // Retorna una referencia al primer elemento
    virtual T& back() = 0; // Retorna una referencia al ultimo elemento
    virtual void push_back(const T& element) = 0; // Inserta un elemento al final
    virtual void push_front(const T& element) = 0; // Inserta un elemento al inicio
    virtual Node<T>* pop_back() = 0; // Quita el ultimo elemento de la lista y retorna una referencia
    virtual Node<T>* pop_front() = 0; // Quita el primer elemento de la lista y retorna una referencia
    virtual T& operator[] (const unsigned int&) = 0; // devuelve el valor de un nodo en una posicion determinad
    virtual bool is_empty() = 0; // la lista esta vacia?
    virtual unsigned int get_size() = 0; // retorna el tamaño de la lista
    virtual void clear() = 0; // Elimina toda la lista
    virtual void erase(Node<T>*) = 0; // Elimina un elemento de la lista en base a un puntero
    virtual void insert(Node<T>*, const T&) = 0; // Inserta un elemento en la lista en base a un puntero
    virtual void drop(const T&) = 0; // Elimina todos los elementos de la lista que tienen el valor igual al parametro
    virtual List& sort() = 0; // ordena la lista
    virtual List& reverse() = 0; // invierte la lista

//    inline friend std::ostream& operator<< (std::ostream&, const List<T>&) {} // Imprime la lista con cout
//    inline friend List& operator<< (List<T>& , const T&) {} // push_back de un elemento
//    inline friend List& operator>> (List<T>& , const T&) {} // pop_back de un elemento
};


#endif //DOUBLYLINKEDLIST_LIST_H
