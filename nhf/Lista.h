#ifndef LISTA_H
#define LISTA_H

#include "memtrace.h"

template <typename T>
class Lista {
private:
    T data;
    Lista* prev;
    Lista* next;

public:
    Lista(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    Lista() {
        data = NULL;
        prev = nullptr;
        next = nullptr;
    }
    T getData() const {
        return data;
    }
    Lista* getPrev() const {
        return prev;
    }
    Lista* getNext() const {
        return next;
    }

    void setData(const T& value) {
        data = value;
    }
    void setPrev(Lista* pre) {
        prev = pre;
    }
    void setNext(Lista* nex) {
        next = nex;
    }

};

#endif // !LISTA_H
