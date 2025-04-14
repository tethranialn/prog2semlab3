#pragma once
using namespace std;
#include "spisok.h"
#include <fstream>

bool readMarker(ifstream& in, ofstream& out, SPISOK& spisok, const char marker);
void processFile(const char* inputFile, const char* outputFile);
