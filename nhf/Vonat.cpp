#include <iostream>
#include "Vonat.h"
#include "string5.h"

Vonat::Vonat() {
	vonatNev = "";
	vonatTipus = "";
	kocsik = nullptr;
}

Vonat::Vonat(const String& _vonatNev, const String& _vonatTipus, Kocsi* _kocsik) :
	vonatNev(_vonatNev),
	vonatTipus(_vonatTipus),
	kocsik(_kocsik) {}

String Vonat::getVonatNev() const { return vonatNev; }
String Vonat::getVonatTipus() const { return vonatTipus; }
Kocsi* Vonat::getKocsik() const { return kocsik; }

void Vonat::setVonatNev(const String& nev) { vonatNev = nev; }
void Vonat::setVonatTipus(const String& tipus) { vonatTipus = tipus; }
void Vonat::setKocsik(Kocsi* kocsik) { this->kocsik = kocsik; }

void Vonat::kocsiAdd() {}