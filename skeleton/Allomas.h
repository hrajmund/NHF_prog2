#pragma once
#ifndef ALLOMAS_H
#define ALLOMAS_H

#include <iostream>
#include "Ido.h"
#include "string5.h"
#include "Vonat.h"

class Allomas {
	String allomasNev;
	Vonat* vonatMegall;
	Ido idok;
public:
	Allomas() = default;
	Allomas(String _allomasNev, Vonat* _vonatMegall, Ido _idok);
	~Allomas();

	String getAllomasNev() const;
	Vonat* getVonatMegall() const;
	Ido getIdok() const;

	void setAllomasNev(const String& nev);
	void setVonatMegall(Vonat* vonat);
	void setIdok(const Ido& ido);
};
#endif // !ALLOMAS_H
