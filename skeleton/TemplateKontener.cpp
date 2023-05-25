#include <iostream>
#include "TemplateKontener.h"
#include "memtrace.h"
#include "Lista.h"

template <typename T>
TemplateKontener<T>::TemplateKontener() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
void TemplateKontener<T>::vegeBeszur(const T& value) {
    Lista<T>* newLista = new Lista<T>(value);
    
    if (isEmpty()) {
        head = tail = newLista;
    }
    else {
        tail->setNext(newLista);
        newLista->setPrev(tail);
        tail = newLista;
    }

    size++;
}

template <typename T>
void TemplateKontener<T>::elejeBeszur(const T& value) {
    Lista<T>* newLista = new Lista<T>(value);

    if (isEmpty()) {
        head = tail = newLista;
    }
    else {
        newLista->setNext(head);
        head->setPrev(newLista);
        head = newLista;
    }

    size++;
}

template <typename T>
void TemplateKontener<T>::kozepereBeszur(const T& value) {
    
}

template <typename T>
void TemplateKontener<T>::torlesVegerol() {
    if (isEmpty()) { return; }

    if (size == 1) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        Lista<T>* prevLista = tail->getPrev();
        prevLista->setNext(nullptr);
        delete tail;
        tail = prevLista;
    }

    size--;
}

template <typename T>
void TemplateKontener<T>::torlesElejerol() {
    if (isEmpty()) {
        return;
    }

    if (size == 1) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Lista<T>* nextLista = head->getNext();
        nextLista->setPrev(nullptr);
        delete head;
        head = nextLista;
    }

    size--;
}

template <typename T>
void TemplateKontener<T>::torlesParam(const T& value) {
    Lista<T>* tmp = head;

    while (tmp) {
        if (tmp->getData() == value) {
            if (tmp == head) {
                torlesElejerol();
            }
            else if (tmp == tail) {
                torlesVegerol();
            }
            else {
                /*Lista<T>* temp = tmp->getPrev();
                temp->setNext(tmp->getNext());
                temp->setPrev(tmp->getPrev());
                delete tmp;
                size--;*/
            }

            return;
        }

        tmp = tmp->getNext();
    }
}

template <typename T>
bool TemplateKontener<T>::isEmpty() const { return size == 0; }

template <typename T>
int TemplateKontener<T>::getSize() const { return size; }

template <typename T>
void TemplateKontener<T>::clear() {
    Lista<T>* current = head;

    while (current) {
        Lista<T>* nextLista = current->getNext();
        delete current;
        current = nextLista;
    }

    head = tail = nullptr;
    size = 0;
}

template <typename T>
void TemplateKontener<T>::print(const T& Data) {}