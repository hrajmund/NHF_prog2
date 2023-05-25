#pragma once
#ifndef MENETREND_H
#define MENETREND_H

#include <iostream>
#include "string5.h"
#include "Allomas.h"
#include "Vonat.h"
#include "Ido.h"


class Menetrend {
	Allomas* allomasok;
public:
	Menetrend() = default;
	Menetrend(Allomas* _allomasok);
	~Menetrend();

	void listazas(std::ostream& os) const;
	void allomasAdd();
	void allomasDel();
	Allomas allomasKeres(String all);
};
#endif // !MENETREND_H
