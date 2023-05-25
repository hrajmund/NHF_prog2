#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista {
private:
    T data;
    Lista* prev;
    Lista* next;

public:
    Lista(const T& value);

    T getData() const;
    Lista* getPrev() const;
    Lista* getNext() const;

    void setData(const T& value);
    void setPrev(Lista* pre);
    void setNext(Lista* nex);

};

#endif // !LISTA_H
