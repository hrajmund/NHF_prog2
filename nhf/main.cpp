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
	readVonatok(vonatok);
	std::cout << vonatok[0].getVonatNev() << std::endl;
	/*
	TemplateKontener<Jegy> jegyek = TemplateKontener<Jegy>();
	TemplateKontener<Menetrend> menetrendek = TemplateKontener<Menetrend>();
	TemplateKontener<Kocsi> kocsik = TemplateKontener<Kocsi>();


    menu(vonatok, jegyek, menetrendek, kocsik);
    */
	return 0;
}
