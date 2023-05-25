#pragma once
#ifndef VONAT_H
#define VONAT_H

#include "string5.h"
#include "Ido.h"
#include "Kocsi.h"

class Vonat {
	String vonatNev;
	String vonatTipus;
	Kocsi* kocsik;

public:
	Vonat() = default;
	Vonat(const String& _vonatNev, const String& _vonatTipus, Kocsi* _kocsik);

	String getVonatNev() const;
	String getVonatTipus() const;
	Kocsi* getKocsik() const;

	void setVonatNev(const String& nev);
	void setVonatTipus(const String& tipus);
	void setKocsik(Kocsi* kocsik);

	void kocsiAdd();
};

#endif