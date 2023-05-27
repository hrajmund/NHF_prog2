#include <iostream>
#include "Vonat.h"
#include "Jegy.h"
#include "Menetrend.h"
#include "TemplateKontener.h"
#include "string5.h"
#include "Menu.h"
#include "FileKezeles.h"
#include "memtrace.h"

int main()
{
	TemplateKontener<Vonat> vonatok = TemplateKontener<Vonat>();
	TemplateKontener<Kocsi> kocsik = TemplateKontener<Kocsi>();
	TemplateKontener<Menetrend> menetrendek = TemplateKontener<Menetrend>();
	TemplateKontener<Allomas> allomasok = TemplateKontener<Allomas>();
	kocsik = readKocsik(kocsik);
	vonatok = readVonatok(vonatok, kocsik);
	allomasok = readAllomasok(allomasok, vonatok);
	menetrendek = readMenetrendek(menetrendek, allomasok);
	std::cout << vonatok[0].getVonatNev() << std::endl;
	/*
	TemplateKontener<Jegy> jegyek = TemplateKontener<Jegy>();

	


    menu(vonatok, jegyek, menetrendek, kocsik);
    */
	return 0;
}
