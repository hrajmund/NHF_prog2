#pragma once
#ifndef ALLOMAS_H
#define ALLOMAS_H

#include <iostream>
#include "Ido.h"
#include "string5.h"
#include "Vonat.h"
#include "TemplateKontener.h"
#include "memtrace.h"

class Allomas {
	String allomasNev;
	TemplateKontener<Vonat> vonatMegall;
	TemplateKontener<Ido> idok;
public:
	Allomas();
	Allomas(String _allomasNev, TemplateKontener<Vonat> _vonatMegall, TemplateKontener<Ido> _idok);
	~Allomas();

	String getAllomasNev() const;
	String getAllomasNev();
	TemplateKontener<Vonat> getVonatMegall() const;
	TemplateKontener<Ido> getIdok() const;

	void setAllomasNev(const String& nev);
	void setVonatMegall(TemplateKontener<Vonat> vonat);
	void setIdok(const Ido& ido, Vonat v);
};

Allomas& allomasKeres(String allNev, TemplateKontener<Allomas> allomasok);
#endif // !ALLOMAS_H
