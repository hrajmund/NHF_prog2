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

bool str_bool(std::string const& s);
TemplateKontener<Vonat> readVonatok(TemplateKontener<Vonat> vonatok, TemplateKontener<Kocsi> kocsik);
TemplateKontener<Kocsi> readKocsik(TemplateKontener<Kocsi> kocsik);
TemplateKontener<Allomas> readAllomasok(TemplateKontener<Allomas> allomasok, TemplateKontener<Vonat> vonatok);
TemplateKontener<Menetrend> readMenetrendek(TemplateKontener<Menetrend> menetrendek, TemplateKontener<Allomas> allomasok);
TemplateKontener<Jegy> readJegy(TemplateKontener<Kocsi> kocsik, TemplateKontener<Vonat> vonatok, TemplateKontener<Menetrend> menetrendek, TemplateKontener<Allomas> allomasok, TemplateKontener<Jegy> jegyek);

#endif // !FILEKEZELES_H
