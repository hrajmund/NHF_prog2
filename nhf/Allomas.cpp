#include <iostream>
#include "Allomas.h"
#include "string5.h"
#include "Ido.h"
#include "Vonat.h"

Allomas::Allomas() {
	allomasNev = "";
	TemplateKontener<Vonat> vonatMegall = TemplateKontener<Vonat>();
	TemplateKontener<Ido> idok = TemplateKontener<Ido>();
}
Allomas::Allomas(String _allomasNev, TemplateKontener<Vonat> _vonatMegall, TemplateKontener<Ido> _idok) : allomasNev(_allomasNev), vonatMegall(_vonatMegall), idok(_idok) {}
Allomas::~Allomas() {}

String Allomas::getAllomasNev() const { return allomasNev; }
String Allomas::getAllomasNev() { return allomasNev; }
TemplateKontener<Vonat> Allomas::getVonatMegall() const { return vonatMegall; }
TemplateKontener<Ido> Allomas::getIdok() const { return idok; }

void Allomas::setAllomasNev(const String& nev) { allomasNev = nev; }
void Allomas::setVonatMegall(TemplateKontener<Vonat> vonat) {
	int vonatokSzama = vonatMegall.getSize();
	if (vonatokSzama >= 50) {
		throw "Tele a vonatok szama!";
	}
	vonatMegall = vonat; 
}
void Allomas::setIdok(const Ido& ido, Vonat v) { 
	idok.vegeBeszur(ido);
	vonatMegall.vegeBeszur(v);
}

Allomas& allomasKeres(String allNev, TemplateKontener<Allomas> allomasok) {
	for (int i = 0; i < allomasok.getSize(); i++) {
		Allomas allomas = allomasok[i];
		if (allomas.getAllomasNev() == allNev) {
			return allomas;
		}
	}
	TemplateKontener<Vonat> _vonatMeg = TemplateKontener<Vonat>();
	TemplateKontener<Ido> _idok = TemplateKontener<Ido>();
	Allomas nincsTalalat = Allomas("Nincs talalat", _vonatMeg, _idok);
	return nincsTalalat;
}
