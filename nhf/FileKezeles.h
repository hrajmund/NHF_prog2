#ifndef FILEKEZELES_H
#define FILEKEZELES_H
#include <fstream>
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
        // V�gigiter�l�s a list�n �s az adatok ki�r�sa a f�jlba
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

            file << std::endl; // Sorv�gjel a jegyek k�z�tti elv�laszt�shoz

            current = current->getNext();
        }

        file.close();
        std::cout << "A Jegyek adatai ki�rva a jegy.txt f�jlba." << std::endl;
    }
    else {
        std::cout << "Hiba a f�jl megnyit�sa sor�n." << std::endl;
    }
}
*/
#endif // !FILEKEZELES_H
