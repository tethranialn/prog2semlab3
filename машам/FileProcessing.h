#pragma once
using namespace std;
#include "List.h"
#include <fstream>

bool readMarker(ifstream& in, ofstream& out, List& list, const char marker);
void processFile(const char* inputFile, const char* outputFile);
