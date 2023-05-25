/*#include <iostream>
#include "TemplateKontener.h"
#include "memtrace.h"
#include "Lista.h"



template <typename T>
Lista<T>* TemplateKontener<T>::getHead() const { return head; }
template <typename T>
Lista<T>* TemplateKontener<T>::getTail() const { return tail; }
template <typename T>
int TemplateKontener<T>::getSize() const { return size; }

template <typename T>
void TemplateKontener<T>::setHead(Lista<T> h) { head = h; }
template <typename T>
void TemplateKontener<T>::setTail(Lista<T> t) { tail = t; }
template <typename T>
void TemplateKontener<T>::setSize(int s) { size = s; }


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
void TemplateKontener<T>::elejeBeszur(T& value) {
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
    Lista<T>* newLista = new Lista<T>(value);

    if (isEmpty()) {
        head = tail = newLista;
    }
    else {
        int middleIndex = size / 2;
        Lista<T>* current = head;

        for (int i = 0; i < middleIndex; i++) {
            current = current->getNext();
        }

        Lista<T>* nextLista = current->getNext();

        newLista->setPrev(current);
        newLista->setNext(nextLista);
        current->setNext(newLista);

        if (nextLista) {
            nextLista->setPrev(newLista);
        }
        else {
            tail = newLista;
        }
    }

    size++;
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
                tmp->getPrev()->setNext(tmp->getNext());
                tmp->getNext()->setPrev(tmp->getPrev());
                delete tmp;
                size--;
            }

            return;
        }

        tmp = tmp->getNext();
    }
}

template <typename T>
bool TemplateKontener<T>::isEmpty() const { return size == 0; }




template <typename T>
void TemplateKontener<T>::print(const T& Data) {}

*/