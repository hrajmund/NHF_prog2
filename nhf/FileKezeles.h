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
#endif // !FILEKEZELES_H
