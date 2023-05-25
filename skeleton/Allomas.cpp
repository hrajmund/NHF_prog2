#include <iostream>
#include "Allomas.h"
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"

Allomas::Allomas(String _allomasNev, Vonat* _vonatMegall, Ido _idok) : allomasNev(_allomasNev), vonatMegall(_vonatMegall), idok(_idok) {}
Allomas::~Allomas() {}

String Allomas::getAllomasNev() const { return allomasNev; }
Vonat* Allomas::getVonatMegall() const { return vonatMegall; }
Ido Allomas::getIdok() const { return idok; }

void Allomas::setAllomasNev(const String& nev) { allomasNev = nev; }
void Allomas::setVonatMegall(Vonat* vonat) { vonatMegall = vonat; }
void Allomas::setIdok(const Ido& ido) { idok = ido; }