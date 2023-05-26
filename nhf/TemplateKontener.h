#ifndef TEMPLATEKONTENER_H
#define TEMPLATEKONTENER_H

#include <iostream>
#include "Lista.h"
#include "memtrace.h"

template <typename T>
class TemplateKontener {
private:
    Lista<T>* head;
    Lista<T>* tail;
    int size;

public:
    TemplateKontener() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }


    Lista<T>* getHead() const { return head; }
    Lista<T>* getTail() const { return tail; }
    int getSize() const { return size; }

    void setHead(Lista<T> h) { head = h; }
    void setTail(Lista<T> t) { tail = t; }
    void setSize(int s) { size = s; }

    void vegeBeszur(const T& value) {
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
    void elejeBeszur(T& value) {
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
    void kozepereBeszur(const T& value) {
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
    void torlesVegerol() {
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
    void torlesElejerol() {
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
    void torlesParam(const T& value) {
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
    bool isEmpty() const { return size == 0; }

    void clear() {
        Lista<T>* current = head;

        while (current) {
            Lista<T>* nextLista = current->getNext();
            delete current;
            current = nextLista;
        }

        head = tail = nullptr;
        size = 0;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Lista<T>* current = getHead();
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }

        return current->getData();
    }

    ~TemplateKontener() {
        clear();
    }
};
 

#endif // !TEMPLATEKONTENER_H
