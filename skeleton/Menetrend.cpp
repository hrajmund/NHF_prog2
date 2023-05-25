#include <iostream>
#include "Menetrend.h"
#include "string5.h"
#include "Allomas.h"
#include "Vonat.h"
#include "Ido.h"

Menetrend::Menetrend(Allomas* _allomasok) : allomasok(_allomasok) {}
Menetrend::~Menetrend() {}

void Menetrend::listazas(std::ostream& os) const {}
void Menetrend::allomasAdd() {}
void Menetrend::allomasDel() {}
Allomas Menetrend::allomasKeres(String all) {
	Vonat v1 = Vonat();
	Vonat v2 = Vonat();
	Vonat* vk = new Vonat[2];
	vk[0] = v1;
	vk[1] = v2;
	Ido i = Ido(1, 2, 3);
	String s = String("c");
	Allomas a = Allomas(s, vk, i);
	return a;
}