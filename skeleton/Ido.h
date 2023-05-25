#pragma once
#ifndef IDO_H
#define IDO_H

#include <iostream>

class Ido {
private:
    int ev;
    int honap;
    int nap;
    int ora;
    int perc;
public:
    Ido(int y, int m, int d, int h, int min);

    Ido(int _ora, int _perc);

    Ido(int _ev, int _honap, int _nap);

    void kiirTeljes();

    void kiirOraPerc();

    int getNapokAHonapban(int honap, int ev) const;

    Ido operator-(const Ido& t) const;
};

#endif // !IDO_H

