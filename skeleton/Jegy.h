#pragma once
#ifndef JEGY_H
#define JEGY_H

#include <iostream>
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"
#include "Allomas.h"

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
	Jegy() = default;
	Jegy(String _nev, Ido _szulIdo, String _kedvez, Vonat _train, Allomas _indulas, Allomas _erkezes);
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

#endif // !JEGY_H
