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

bool str_bool(std::string const& s) {
    return s != "0";
}

TemplateKontener<Kocsi> readKocsik(TemplateKontener<Kocsi> kocsik) {
    std::ifstream file("kocsik.txt");
    if (!file.is_open()) {
        throw "Nem sikerult megnyitni.";
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);

        std::string KocsiSzam;
        std::getline(ss, KocsiSzam, ';');

        std::string ferohely;
        std::getline(ss, ferohely, ';');

        std::string kerekpar;
        std::getline(ss, kerekpar, '\n');

        Kocsi tmp = Kocsi(std::stoi(KocsiSzam), std::stoi(ferohely), str_bool(kerekpar));
        kocsik.vegeBeszur(tmp);

    }
    file.close();
    return kocsik;
}

TemplateKontener<Vonat> readVonatok(TemplateKontener<Vonat> vonatok, TemplateKontener<Kocsi> kocsik) {
	std::ifstream file("vonatok.txt");
    if (!file.is_open()) {
        throw "Nem sikerult megnyitni.";
    }
    
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string vNev = "";
        std::getline(ss, vNev, ';');

        std::string vTipus;
        std::getline(ss, vTipus, ';');
        TemplateKontener<Kocsi> vKocsik = TemplateKontener<Kocsi>();
        std::string kocsi;

        for (int j = 0; j < 10; j++) {
            std::string vKocsiSzam;
            if (j == 9) {
                std::getline(ss, vKocsiSzam, '\n');
            }
            else {
            std::getline(ss, vKocsiSzam, ';');
            }
            Kocsi tmp = kocsiKeres(std::stoi(vKocsiSzam), kocsik);
            vKocsik.vegeBeszur(tmp);
        }

        String _vNev = vNev;
        String _vTipus = vTipus;
        Vonat v = Vonat(_vNev, _vTipus, vKocsik);
        vonatok.vegeBeszur(v);
    }

    file.close();
    return vonatok;

}

TemplateKontener<Allomas> readAllomasok(TemplateKontener<Allomas> allomasok, TemplateKontener<Vonat> vonatok) {
    std::ifstream file("allomasok.txt");
    if (!file.is_open()) {
        throw "Nem sikerult megnyitni.";
    }

    std::string line;

    TemplateKontener<Vonat> aVonatok = TemplateKontener<Vonat>();
    TemplateKontener<Ido> aIdok = TemplateKontener<Ido>();
    std::string vonat;

    while (std::getline(file, line)) {
        std::istringstream ss(line);

        std::string allNev;
        std::getline(ss, allNev, ';');

        for (int i = 0; i < 50; i++) {
            std::string aVonatNev;
            if (i == 49) {
                std::getline(ss, aVonatNev, '\n');
            }
            else {
                std::getline(ss, aVonatNev, ';');
            }
            String _aVonatNev = aVonatNev;
            Vonat tmp = vonatKeres(_aVonatNev, vonatok);
            aVonatok.vegeBeszur(tmp);
        }
        for (int i = 0; i < 50; i++) {
            std::string aIdoOra;
            std::string aIdoPerc;
            if (i == 49) {
                std::getline(ss, aIdoOra, ':');
                std::getline(ss, aIdoPerc, '\n');
            }
            else {
                std::getline(ss, aIdoOra, ':');
                std::getline(ss, aIdoPerc, ';');
            }

            int ora = std::stoi(aIdoOra);
            int perc = std::stoi(aIdoPerc);
            Ido tmp = Ido(ora, perc);
            aIdok.vegeBeszur(tmp);
        }

        String _allNev = allNev;

        Allomas a = Allomas(_allNev, aVonatok, aIdok);
        allomasok.vegeBeszur(a);
    }
    file.close();
    return allomasok;
}

TemplateKontener<Menetrend> readMenetrendek(TemplateKontener<Menetrend> menetrendek, TemplateKontener<Allomas> allomasok) {
    std::ifstream file("menetrendek.txt");
    if (!file.is_open()) {
        throw "Nem sikerult megnyitni.";
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string allNev;
        int count = 0;
        TemplateKontener<Allomas> mAllomasok = TemplateKontener<Allomas>();
        for (int i = 0; i < 25; i++) {
            String _allNev = allNev;
            if (std::getline(ss, allNev)) {
                Allomas tmp = allomasKeres(_allNev,allomasok);
                mAllomasok.vegeBeszur(tmp);
                count++;
            }
            else if (std::getline(ss, allNev, ';')) {
                Allomas tmp = allomasKeres(_allNev, allomasok);
                mAllomasok.vegeBeszur(tmp);
                count++;
                break;
            }
        }
        Menetrend m = Menetrend(mAllomasok, count);
        menetrendek.vegeBeszur(m);
    }
    file.close();
    return menetrendek;
}

TemplateKontener<Jegy> readJegy(TemplateKontener<Kocsi> kocsik, TemplateKontener<Vonat> vonatok, TemplateKontener<Menetrend> menetrendek, TemplateKontener<Allomas> allomasok, TemplateKontener<Jegy> jegyek) {
    std::ifstream file("jegyek.txt");
    if (!file.is_open()) {
        throw "Nem sikerult megnyitni.";
    }


}