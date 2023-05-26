#include <iostream>
#include "Kocsi.h"

Kocsi::Kocsi() {
	sorSzam = 0;
	ferohely = 0;
	kerekpar = 0;
}
Kocsi::Kocsi(int _sorszam, int _ferohely, bool _kerekpar) : sorSzam(_sorszam), ferohely(_ferohely), kerekpar(_kerekpar) {}
Kocsi::~Kocsi() {}

bool Kocsi::operator!=(std::nullptr_t) const {
	return (this != nullptr);
}

Kocsi& Kocsi::operator=(std::nullptr_t) {
	// Nem végezünk semmilyen mûveletet, csak visszaadjuk a *this referenciát
	return *this;
}

int Kocsi::getSorSzam() const { return sorSzam; }
int Kocsi::getFerohely() const { return ferohely; }
bool Kocsi::getKerekpar() const { return kerekpar; }

void Kocsi::setSorSzam(int szam) { sorSzam = szam; }
void Kocsi::setFerohely(int hely) { ferohely = hely; }
void Kocsi::setKerekpar(bool vanKerekpar) { kerekpar = vanKerekpar; }

void Kocsi::listazas(std::ostream& os) const {}

