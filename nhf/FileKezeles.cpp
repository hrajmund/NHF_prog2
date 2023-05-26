#include <fstream>
#include <iostream>
#include "FileKezeles.h"
#include "string5.h"
#include "StringStream.h"
#include "TemplateKontener.h"
#include "Lista.h"
#include "Jegy.h"
#include "Vonat.h"
#include "Allomas.h"
#include "Menetrend.h"

/*
void writeJegyekToFile(const TemplateKontener<Jegy>& jegyek) {
    std::ofstream file("jegy.txt");
    
    if (file.is_open()) {
        // Végigiterálás a listán és az adatok kiírása a fájlba
        Lista<Jegy>* current = jegyek.getHead();
        while (current) {
            Jegy jegy = current->getData();

            file << jegy.getUtasNev() << ";"
                << jegy.getSzulIdo().getEv() << ";"
                << jegy.getSzulIdo().getHonap() << ";"
                << jegy.getSzulIdo().getNap() << ";"
                << jegy.getKedvezEsEgyeb() << ";"
                << jegy.getTrain().getVonatNev() << ";"
                << jegy.getTrain().getVonatTipus() << ";" << std::endl;

            file << std::endl; // Sorvégjel a jegyek közötti elválasztáshoz

            current = current->getNext();
        }

        file.close();
        std::cout << "A Jegyek adatai kiírva a jegy.txt fájlba." << std::endl;
    }
    else {
        std::cout << "Hiba a fájl megnyitása során." << std::endl;
    }
}
*/

void readVonat(TemplateKontener<Vonat>& vonatok) {
    std::ifstream file("vonatok.txt");
    if (!file.is_open()) {
        std::cout << "Hiba: Nem sikerult megnyitni a fajlt." << std::endl;
        return;
    }
    int count = 0;
    String line;
    while (getLine(file, line)) {
        StringStream ss(line);

        String vonatNev, vonatTipus, kocsikStr;
        ss >> vonatNev;
        ss >> vonatTipus;
        ss >> kocsikStr;

        Vonat vonat(vonatNev, vonatTipus, nullptr);

        StringStream kocsikStream(kocsikStr);
        String kocsiSorszam;
        while (kocsikStream >> kocsiSorszam) {
            int sorszam = Stoi(kocsiSorszam);
            Kocsi tmp = Kocsi(sorszam, 0, false);
            vonat.kocsiAdd(tmp);
        }

        vonatok.vegeBeszur(vonat);
    }
    file.close();
}

void readJegy(TemplateKontener<Jegy>& jegyek) {
    std::ifstream file("jegyek.txt");
    if (!file.is_open()) {
        std::cout << "Hiba: Nem sikerult megnyitni a fajlt." << std::endl;
        return;
    }

    String line;
    while (getLine(file, line)) {
        StringStream ss(line);

        String nev;
        Ido ido;
        String kedvez;
        Vonat vonat;
        Allomas indulas;
        Allomas erkezes;

        ss >> nev;
        ss >> convertIdoToString(ido);
        ss >> kedvez;
        ss >> vonat.getVonatNev();
        ss >> indulas.getAllomasNev();
        ss >> erkezes.getAllomasNev();

        Jegy jegy(nev, ido, kedvez, vonat, indulas, erkezes);
        jegyek.vegeBeszur(jegy);
    }

    file.close();
}

void readKocsi(TemplateKontener<Kocsi>& kocsik) {
    std::ifstream file("kocsik.txt");
    if (!file.is_open()) {
        std::cout << "Hiba: Nem sikerult megnyitni a fajlt." << std::endl;
        return;
    }

    String line;
    while (getLine(file, line)) {
        StringStream ss(line);
        if (!getLine(file, line, ';'))
            break;
        
        int sorszam = Stoi(line);

        if (!getLine(file, line, ';'))
            break;

        int ferohely = Stoi(line);

        if (!getLine(file, line))
            break;

        bool kerekpar = (line == "true");

        Kocsi k = Kocsi(sorszam, ferohely, kerekpar);
        kocsik.vegeBeszur(k);
    }
}