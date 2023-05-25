#ifndef KOCSI_H
#define KOCSI_H

#include <iostream>

class Kocsi {
	int sorSzam;
	int ferohely;
	bool kerekpar;
public:
	Kocsi();
	Kocsi(int _sorszam, int _ferohely, bool _kerekpar);
	~Kocsi();
	
	int getSorSzam() const;
	int getFerohely() const;
	bool getKerekpar() const;

	void setSorSzam(int szam);
	void setFerohely(int hely);
	void setKerekpar(bool vanKerekpar);

	void listazas(std::ostream& os) const;
};


#endif // !KOCSI_H
