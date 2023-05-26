#include <iostream>
#include "Menetrend.h"
#include "string5.h"
#include "Allomas.h"
#include "Vonat.h"
#include "Ido.h"
#include "Lista.h"
#include "TemplateKontener.h"
#include "memtrace.h"

Menetrend::Menetrend() {
	allomasok = nullptr;
	size = 0;
}
Menetrend::Menetrend(Allomas* _allomasok) {
	allomasok = _allomasok;
	// Számítsuk ki a tömb méretét
	while (_allomasok[size].getAllomasNev() != "") {
		size++;
	}
}
Menetrend::~Menetrend() {}

int Menetrend::getSize() const{ return size; }
void Menetrend::setSize(int s) { size = s; }

void Menetrend::listazas(std::ostream& os, const Menetrend &m) const {
	for (int i = 0; i < m.getSize(); i++) {
		std::cout << m.allomasok->getAllomasNev()[i] << std::endl;
	}
}
/*
bool jegyFelvetel(TemplateKontener<Menetrend> m, Allomas kezd, Allomas erk) {
	for (int i = 0; i < m.getSize(); i++) {
		for (int j = 0; j < m.getHead()->getData().getSize(); j++) {
			Allomas tmp = m.getHead()->getData().
			if(tmp == kezd)
		}
	}
}*/

void Menetrend::allomasAdd() {}
void Menetrend::allomasDel() {}

Allomas Menetrend::allomasKeres(String all) {
	for (int i = 0; i < size; i++) {
		if (allomasok[i].getAllomasNev() == all) {
			return allomasok[i];
		}
	}
	// Ha nem található az állomás a menetrendben, visszatérünk egy üres Allomas objektummal
	return Allomas();
}
