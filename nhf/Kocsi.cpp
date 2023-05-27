#include <iostream>
#include "Kocsi.h"
#include "TemplateKontener.h"
#include "Lista.h"
#include "memtrace.h"

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
	// Nem v�gez�nk semmilyen m�veletet, csak visszaadjuk a *this referenci�t
	return *this;
}

int Kocsi::getSorSzam() const { return sorSzam; }
int Kocsi::getFerohely() const { return ferohely; }
bool Kocsi::getKerekpar() const { return kerekpar; }

void Kocsi::setSorSzam(int szam) { sorSzam = szam; }
void Kocsi::setFerohely(int hely) { ferohely = hely; }
void Kocsi::setKerekpar(bool vanKerekpar) { kerekpar = vanKerekpar; }

Kocsi& kocsiKeres(int szam, TemplateKontener<Kocsi> kocsik) {
	for (int i = 0; i < kocsik.getSize(); i++) {
		Kocsi kocsi = kocsik[i];
		if (kocsi.getSorSzam() == szam) {
			return kocsi;
		}
	}
	std::cout << "Nincs Tal�lat!" << std::endl;
	Kocsi nincsTalalat = Kocsi(0, 0, false);
	// Ha nem tal�lhat� a megadott sz�m� kocsi, alap objektumot adunk vissza
	return nincsTalalat;

}

void Kocsi::listazas(std::ostream& os) const {
	os << this->getSorSzam();
}

