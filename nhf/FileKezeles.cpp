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

void readVonatok(TemplateKontener<Vonat> vonatok) {
	std::ifstream file("vonatNevek.txt");
    if (!file.is_open()) {
        std::cout << "Nem sikerult megnyitni." << std::endl;
        return;
    }
    //while(std::getline(file, line))
    std::string line;
    //std::getline(file, line);
    int sorSzamlalo;
    file >> sorSzamlalo;
    std::stringstream ss(line);
    ss.ignore('\n');
    for (int i = 0; i < sorSzamlalo; i++)
    {
        
        std::string vNev;
        std::getline(ss, vNev);

        std::string vTipus;
        std::getline(ss, vTipus);
        TemplateKontener<Kocsi> kocsik = TemplateKontener<Kocsi>();
        int* kocsiSzamok = new int[10];
        std::string kocsi;
        int j = 0;

        for (int j = 0; j < 10; j++) {
            ss >> kocsiSzamok[j];
            ss.ignore(' ');
            Kocsi tmp = Kocsi(kocsiSzamok[j], 0, false);
            kocsik.elejeBeszur(tmp);
        }

        /*while (std::getline(ss, kocsi, '\n')) {
            ss >> kocsiSzamok[j];
            ss.ignore(' ');
            Kocsi tmp = Kocsi(kocsiSzamok[j], 0, false);
            kocsik.elejeBeszur(tmp);
        }*/
        delete[] kocsiSzamok;
        String _vNev = vNev;
        String _vTipus = vTipus;
        Vonat v = Vonat(_vNev, _vTipus, kocsik);
        vonatok.vegeBeszur(v);
    }

    file.close();

}