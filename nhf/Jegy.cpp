#include <iostream>
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"
#include "Allomas.h"
#include "Jegy.h"
#include "TemplateKontener.h"
#include "Menetrend.h"
#include "memtrace.h"

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

void ujJegy(TemplateKontener<Jegy> jegyek, TemplateKontener<Menetrend> menetrendek) {
	Jegy j;
	String _utasNev = String();
	std::cout << "Kerem az utas nevet! ";
	std::cin >> _utasNev;
	Ido _szulIdo;
	
	std::cout << "Kerem az utas szuletesi evszamat! ";
	int y;
	std::cin >> y;
	_szulIdo.setEv(y);
	
	std::cout << "Kerem az utas szuletesi honapjat! ";
	int h;
	std::cin >> h;
	_szulIdo.setHonap(h);
	
	std::cout << "Kerem az utas szuletesi napjat! ";
	int d;
	std::cin >> d;
	_szulIdo.setNap(d);
	
	std::cout << "Ha rendelkezik az alabbiakkal, irjon egy 1-est, kulonben 0-at!" << std::endl;
	std::cout << "Diak, Nyugdijas, BKK berlet, Kerekpar" << std::endl;
	String kedvezmenyek;
	std::cin >> kedvezmenyek;

	String kezdo;
	std::cout << "Indulo allomas neve: " << std::endl;
	std::cin >> kezdo;
	Allomas k = Allomas();
	k.setAllomasNev(kezdo);

	String erkezo;
	std::cout << "Erkezo allomas neve: " << std::endl;
	std::cin >> erkezo;
	Allomas e = Allomas();
	e.setAllomasNev(erkezo);

	//jegyFelvetel(m, k, e);
	
	jegyek.elejeBeszur(j);
}


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