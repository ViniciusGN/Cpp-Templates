#include "Set.h"
#include <iostream>

template <typename T>
Set<T>::Set(): list(nullptr) {} // Default constructor

template <typename T>
Set<T>::Set(T param): list(new Node(param)) {} // Param Constructor

template <typename T>
Set<T>::~Set() { clear() } // Destructor

template <typename T>
void Set<T>::clear() {
    while (list != nullptr) {
        Node *temp = list;
        list = list.getNext();
        delete  temp;
    }
}
// void Set<T>::clear() {
//     Node *current = list
//     while (current != nullptr)
//     {
//         Node *nextNode = current.getValue();
//         delete current;
//         current = nextNode;
//     }
//     list = nullptr;
// }

template <typename T>
Set<T>::~Set(){}

