#ifndef JEGY_H
#define JEGY_H

#include <iostream>
#include "TemplateKontener.h"
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"
#include "Allomas.h"
#include "Menetrend.h"
#include "memtrace.h"

class Jegy {
	String utasNev;
	Ido szulIdo;
	String kedvezEsEgyeb;
	Vonat train;
	Allomas indulas;
	Allomas erkezes;
	int ar = 0;
	int teljesTav = 0;
	String uloHely = "";
public:
	Jegy() : ar(0), teljesTav(0) {}
	Jegy(String _nev, Ido _szulIdo, String _kedvez, Vonat _train, Allomas _indulas, Allomas _erkezes);
	Jegy(String _nev, Ido _szulIdo, String _kedvez, Vonat _train, Allomas _indulas, Allomas _erkezes, int _ar, int _teljesTav, String _ulohely);
	~Jegy();

	String getUtasNev() const;
	Ido getSzulIdo() const;
	String getKedvezEsEgyeb() const;
	Vonat getTrain() const;
	Allomas getIndulas() const;
	Allomas getErkezes() const;
	int getAr() const;
	int getTeljesTav() const;
	String getUloHely() const;

	void setUtasNev(const String nev);
	void setSzulIdo(const Ido& ido);
	void setKedvezEsEgyeb(const String& kedvez);
	void setTrain(const Vonat& vonat);
	void setIndulas(const Allomas& allomas);
	void setErkezes(const Allomas& allomas);

	void adatKiir(std::ostream& os) const;
	int teljesT(Allomas indulas, Allomas erkezes);
	int arKiszamolasa(String kedvez, int teljesTav);
	String uloHelyGen();
	void kesesKezeles();
};

void ujJegy(TemplateKontener<Jegy> jegyek);

#endif // !JEGY_H
