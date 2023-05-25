#include <iostream>
#include "Ido.h"

void Ido::setEv(int y) { ev = y; }
void Ido::setHonap(int m) { honap = m; }
void Ido::setNap(int d) { nap = d; }
void Ido::setOra(int h) { ora = h; }
void Ido::setPerc(int min) { perc = min; }

int Ido::getEv() const { return ev; }
int Ido::getHonap() const { return honap; }
int Ido::getNap() const { return nap; }
int Ido::getOra() const { return ora; }
int Ido::getPerc() const { return perc;}

Ido::Ido(int y, int m, int d, int h, int min) {
    ev = y;
    honap = m;
    nap = d;
    ora = h;
    perc = min;
}

Ido::Ido(int _ora, int _perc) {
    ev = 0;
    honap = 0;
    nap = 0;
    ora = _ora;
    perc = _perc;
}

Ido::Ido(int _ev, int _honap, int _nap) {
    ev = _ev;
    honap = _honap;
    nap = _nap;
    ora = 0;
    perc = 0;
}

void Ido::kiirTeljes() {
    std::cout << "Ev: " << ev << " Honap: " << honap << " Nap: " << nap << " Ora: " << ora << " Perc: " << perc << std::endl;
}

void Ido::kiirOraPerc() {
    std::cout << ora << ":" << perc << std::endl;
}

int Ido::getNapokAHonapban(int honap, int ev) const {
    if (honap == 2) {
        if (ev % 4 == 0 && (ev % 100 != 0 || ev % 400 == 0))
            return 29;
        else
            return 28;
    }
    else if (honap == 4 || honap == 6 || honap == 9 || honap == 11)
        return 30;
    else
        return 31;
}

Ido Ido::operator-(const Ido& t) const {
    Ido temp;
    temp.perc = perc - t.perc;
    temp.ora = ora - t.ora;
    temp.nap = nap - t.nap;
    temp.honap = honap - t.honap;
    temp.ev = ev - t.ev;

    if (temp.perc < 0) {
        temp.perc += 60;
        temp.ora--;
    }
    if (temp.ora < 0) {
        temp.ora += 24;
        temp.nap--;
    }
    if (temp.nap < 0) {
        temp.nap += getNapokAHonapban(temp.honap, temp.ev);
        temp.honap--;
    }
    if (temp.honap < 0) {
        temp.honap += 12;
        temp.ev--;
    }

    return temp;
}