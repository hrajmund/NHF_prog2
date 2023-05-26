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

void readVonatok(TemplateKontener<Vonat> vonatok);

#endif // !FILEKEZELES_H
