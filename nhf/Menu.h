#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Vonat.h"
#include "Menetrend.h"
#include "Jegy.h"
#include "TemplateKontener.h"
#include "string5.h"
#include "memtrace.h"
void menu(TemplateKontener<Vonat> vonatok, TemplateKontener<Jegy> jegyek, TemplateKontener<Menetrend> menetrendek, Kocsi* kocsik) {

	std::cout << "Vonatjegy" << std::endl;
	std::cout << "(1.) Jegy" << std::endl
		<< "(2.) Menetrendek, allomasok" << std::endl
		<< "(3.) Vonat" << std::endl
		<< "(4.) Kilepes" << std::endl
		<< "Valassz menupontot!" << std::endl;
	char menupont;
	std::cin >> menupont;

	while (menupont != '4') {
		switch (menupont)
		{
		case '1': {
			ujJegy(jegyek);
			std::cout << "(1.) Jegy" << std::endl
				<< "(2.) Menetrendek, allomasok" << std::endl
				<< "(3.) Vonat" << std::endl
				<< "(4.) Kilepes" << std::endl
				<< "Valassz menupontot!" << std::endl;
			std::cin >> menupont;
			break;
		}
		case '2':
			std::cout << "(5.) Uj allomas" << std::endl
				<< "(6.) Meglevo allomas modositasa" << std::endl
				<< "(7.) Uj menetrend" << std::endl
				<< "(8.) Menetrend modositasa" << std::endl;
			std::cin >> menupont;
			switch (menupont) {
			case '5':
				std::cout << "Szia" << std::endl;
				std::cin >> menupont;
				break;
			}
			break;
		case '3':
			std::cout << "(5.) Uj vonat" << std::endl
				<< "(6.) Meglevo vonat modositasa" << std::endl;
			std::cin >> menupont;
			switch (menupont) {
			case '5':
				//ujVonat();
				break;
			case '6':
				vonatModosit();
				break;
			}
		default:
			break;
		}
	}
}

#endif // !MENU_H
