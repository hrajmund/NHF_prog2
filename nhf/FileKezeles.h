#ifndef FILEKEZELES_H
#define FILEKEZELES_H
#include <fstream>
#include <iostream>
#include "string5.h"
#include "StringStream.h"
#include "TemplateKontener.h"
#include "Lista.h"
#include "Jegy.h"
#include "Vonat.h"
#include "Allomas.h"
#include "Menetrend.h"
/*
void writeJegyekToFile(const TemplateKontener<Jegy>& jegyek);
*/

void readVonat(TemplateKontener<Vonat>& vonatok);

void readJegy(TemplateKontener<Jegy>& jegyek);

void readKocsi(TemplateKontener<Kocsi>& kocsik);

#endif // !FILEKEZELES_H
