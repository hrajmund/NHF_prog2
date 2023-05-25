#include <iostream>
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"
#include "Allomas.h"
#include "Jegy.h"

Jegy::Jegy(String _nev, Ido _szulIdo, String _kedvez, Vonat _train, Allomas _indulas, Allomas _erkezes) :
	utasNev(_nev),
	szulIdo(_szulIdo),
	kedvezEsEgyeb(_kedvez),
	train(_train),
	indulas(_indulas),
	erkezes(_erkezes) {}

Jegy::~Jegy() {

}

String Jegy::getUtasNev() const { return utasNev; }
Ido Jegy::getSzulIdo() const { return szulIdo; }
String Jegy::getKedvezEsEgyeb() const { return kedvezEsEgyeb; }
Vonat Jegy::getTrain() const { return train; }
Allomas Jegy::getIndulas() const { return indulas; }
Allomas Jegy::getErkezes() const { return erkezes; }
int Jegy::getAr() const { return ar; }
int Jegy::getTeljesTav() const { return teljesTav; }
String Jegy::getUloHely() const { return uloHely; }

void Jegy::setUtasNev(const String nev) { utasNev = nev; }
void Jegy::setSzulIdo(const Ido& ido) { szulIdo = ido; }
void Jegy::setKedvezEsEgyeb(const String& kedvez) { kedvezEsEgyeb = kedvez; }
void Jegy::setTrain(const Vonat& vonat) { train = vonat; }
void Jegy::setIndulas(const Allomas& allomas) { indulas = allomas; }
void Jegy::setErkezes(const Allomas& allomas) { erkezes = allomas; }

void Jegy::adatKiir(std::ostream& os) const {

}

int Jegy::teljesT(Allomas indulas, Allomas erkezes) {
	return 1;
}
int Jegy::arKiszamolasa(String kedvez, int teljesTav) {
	return 1;
}

String Jegy::uloHelyGen() {
	return "";
}

void Jegy::kesesKezeles() {

}