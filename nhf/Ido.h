#pragma once
#ifndef IDO_H
#define IDO_H

#include <iostream>
#include "string5.h"
#include "StringStream.h"
#include "memtrace.h"

class Ido {
private:
    int ev;
    int honap;
    int nap;
    int ora;
    int perc;
public:
    Ido() : ev(0), honap(0), nap(0), ora(0), perc(0) {}
    Ido(int y, int m, int d, int h, int min);

    Ido(int _ora, int _perc);

    Ido(int _ev, int _honap, int _nap);

    void kiirTeljes();

    void kiirOraPerc();

    void setEv(int y);
    void setOra(int h);
    void setPerc(int min);
    void setHonap(int m);
    void setNap(int d);

    int getEv() const;
    int getHonap() const;
    int getNap() const;
    int getOra() const;
    int getPerc() const;

    int getNapokAHonapban(int honap, int ev) const;
    Ido operator-(const Ido& t) const;

};

String convertIdoToString(const Ido& ido);

#endif // !IDO_H

