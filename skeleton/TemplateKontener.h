#ifndef TEMPLATEKONTENER_H
#define TEMPLATEKONTENER_H

#include <iostream>
#include "Lista.h"

template <typename T>
class TemplateKontener {
private:
    Lista<T>* head;
    Lista<T>* tail;
    int size;

public:
    TemplateKontener();

    ~TemplateKontener() {
        clear();
    }

    void vegeBeszur(const T& value);

    void elejeBeszur(const T& value);

    void kozepereBeszur(const T& value);

    void torlesVegerol();

    void torlesElejerol();

    void torlesParam(const T& value);

    bool isEmpty() const;

    int getSize() const;

    void clear();

    void print(const T& Data);
};

#endif // !TEMPLATEKONTENER_H
