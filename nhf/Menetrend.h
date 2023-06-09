#pragma once
#ifndef MENETREND_H
#define MENETREND_H

#include <iostream>
#include "string5.h"
#include "Allomas.h"
#include "Vonat.h"
#include "Ido.h"
#include "TemplateKontener.h"
#include "Jegy.h"
#include "memtrace.h"


class Menetrend {
private:
	TemplateKontener<Allomas> allomasok;
	int size;
public:
	Menetrend();
	Menetrend(TemplateKontener<Allomas> _allomasok);
	Menetrend(TemplateKontener<Allomas> _allomasok, int _size);
	~Menetrend();

	int getSize() const;
	void setSize(int s);

	void listazas(std::ostream& os, const Menetrend& m) const;
	void allomasAdd();
	void allomasDel();
	//Allomas allomasKeres(String all);
	
};

bool jegyFelvetel(TemplateKontener<Menetrend> m, Allomas kezd, Allomas erk);

#endif // !MENETREND_H
