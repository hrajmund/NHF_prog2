#include <iostream>
#include "Vonat.h"
#include "string5.h"
#include "Ido.h"
#include "Kocsi.h"
#include "TemplateKontener.h"
#include "memtrace.h"

Vonat::Vonat() {
	vonatNev = "";
	vonatTipus = "";
    TemplateKontener<Kocsi> kocsik = TemplateKontener<Kocsi>();
}

Vonat::Vonat(const String& _vonatNev, const String& _vonatTipus, TemplateKontener<Kocsi> _kocsik) :
	vonatNev(_vonatNev),
	vonatTipus(_vonatTipus),
	kocsik(_kocsik) {}

String Vonat::getVonatNev() const { return vonatNev; }
String Vonat::getVonatTipus() const { return vonatTipus; }
TemplateKontener<Kocsi> Vonat::getKocsik() const { return kocsik; }
int Vonat::getKocsiSzam() const {
    return kocsik.getSize();
}

void Vonat::setVonatNev(const String& nev) { vonatNev = nev; }
void Vonat::setVonatTipus(const String& tipus) { vonatTipus = tipus; }
void Vonat::setKocsik(Kocsi k) {
    kocsik.vegeBeszur(k);
}

void Vonat::kocsiAdd() {
    int kocsiSzam = getKocsiSzam();
    if (kocsiSzam == 10 || kocsiSzam == NULL) {
        throw "Maximalis kocsi!";
    }

    Kocsi newKocsi = Kocsi();
    setKocsik(newKocsi);
}

void Vonat::kocsiAdd(const Kocsi& kocsi) {
    int kocsiSzam = getKocsiSzam();
    if (kocsiSzam == 10 || kocsiSzam == NULL) {
        throw "Maximalis kocsi!";
    }
    setKocsik(kocsi);
}

void ujVonat(TemplateKontener<Vonat> vonatok, TemplateKontener<Kocsi> kocsik) {
    Vonat v = Vonat();

    std::cout << "Add meg a vonat nevet!" << std::endl;
    String vNev;
    std::cin >> vNev;
    v.setVonatNev(vNev);

    std::cout << "Add meg a vonat tipusat!" << std::endl;
    String vTipus;
    std::cin >> vTipus;
    v.setVonatTipus(vTipus);

    std::cout << "Valaszd ki, melyik kocsikat szeretned hozzaadni!" << std::endl
        << "Ha mar nem szeretnel uj kocsit hozzaadni, nyomd meg a 'Q'-t " << std::endl;
    char valasztas;
    int i = 0;
    //for(int i = 0; i < kocsik)
}

Vonat& vonatKeres(String& vonatNev, TemplateKontener<Vonat> vonatok) {
    for (int i = 0; i < vonatok.getSize(); i++) {
        Vonat vonat = vonatok[i];
        if (vonat.getVonatNev() == vonatNev) {
            return vonat;
        }
    }
    std::cout << "Nincs Találat!" << std::endl;
    TemplateKontener<Kocsi> kocsik = TemplateKontener<Kocsi>();
    Vonat nincsTalalat = Vonat("", "", kocsik);
    return nincsTalalat;
}
void vonatModosit() {}