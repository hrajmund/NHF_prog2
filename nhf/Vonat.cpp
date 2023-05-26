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
	kocsik = nullptr;
}

Vonat::Vonat(const String& _vonatNev, const String& _vonatTipus, Kocsi* _kocsik) :
	vonatNev(_vonatNev),
	vonatTipus(_vonatTipus),
	kocsik(_kocsik) {}

String Vonat::getVonatNev() const { return vonatNev; }
String Vonat::getVonatTipus() const { return vonatTipus; }
Kocsi* Vonat::getKocsik() const { return kocsik; }
int Vonat::getKocsiSzam() const {
	// Megszámoljuk a kocsikat, amelyek nem NULL pointerek
	int count = 0;
	for (int i = 0; kocsik[i] != nullptr; i++) {
		count++;
	}
	return count;
}

void Vonat::setVonatNev(const String& nev) { vonatNev = nev; }
void Vonat::setVonatTipus(const String& tipus) { vonatTipus = tipus; }
void Vonat::setKocsik(Kocsi* kocsik) { this->kocsik = kocsik; }

void Vonat::kocsiAdd() {
    int kocsiSzam = getKocsiSzam();
    if (kocsiSzam == NULL) { kocsiSzam = 0; }

    // Dinamikusan növeljük a kocsik tömb méretét
    Kocsi* temp = new Kocsi[kocsiSzam + 2];
    

    // Másoljuk át az eddigi kocsikat az új tömbbe
    for (int i = 0; i < kocsiSzam; i++) {
        temp[i] = kocsik[i];
    }

    // Töröljük az eredeti kocsikat
    delete[] kocsik;

    // Az új kocsi hozzáadása
    Kocsi newKocsi;
    temp[kocsiSzam] = newKocsi;
    temp[kocsiSzam + 1] = nullptr;

    // Frissítjük a kocsik adattagot
    kocsik = temp;
}

void Vonat::kocsiAdd(const Kocsi& kocsi) {
    int kocsiSzam = getKocsiSzam();
    Kocsi* ujKocsik = new Kocsi[kocsiSzam + 1];

    // Lemásoljuk az eddigi kocsikat az új tömbbe
    for (int i = 0; i < kocsiSzam; i++) {
        ujKocsik[i] = kocsik[i];
    }

    // Az új kocsi hozzáadása
    ujKocsik[kocsiSzam] = kocsi;

    // Felszabadítjuk az eredeti kocsik tömböt
    delete[] kocsik;

    // Az új kocsik tömböt rendeljük a vonathoz
    kocsik = ujKocsik;
}

void ujVonat(TemplateKontener<Vonat> vonatok, Kocsi* kocsik) {
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
void vonatModosit() {}