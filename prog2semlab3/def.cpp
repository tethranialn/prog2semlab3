#include "functions.h"
#include <iostream>
bool readMarker(ifstream& in, ofstream& out, SPISOK& spisok, const char marker)
{
    char buffer[256];
    int lineCount = 0;
    bool markerFound = false;
    while (in.getline(buffer, 255)) 
    {
        int i = 0;
        bool foundMarker = false;
        while (buffer[i] != '\0') 
        {
            if (buffer[i] == marker) 
            {
                foundMarker = true;
                buffer[i] = '\0';
                break;
            }
            i++;
        }
        if (foundMarker)
        {
            markerFound = true;
        }
        spisok.push_back(buffer);
        out << "-> " << buffer << '\n';
        lineCount++;
        if (markerFound) break;
    }
    out << "\nnumber of readed lines: " << lineCount << '\n';
    return markerFound;
}

void processFile(const char* inputFile, const char* outputFile) 
{
    SPISOK spisok;
    ofstream out(outputFile);
    if (!out) 
    {
        cerr << "out file is not open" << endl;
        return;
    }
    ifstream in(inputFile);
    if (!in)
    {
        out << "in file is not open" << endl;
        out.close();
        return;
    }
    char marker;
    in >> marker;
    in.ignore();
    while (in.peek() == ' ') in.get();
    char valueToSave[256];
    in.getline(valueToSave, 255);
    out << "target value: \"" << valueToSave << "\"\n\n";
    out << "file data:\n\n";
    if (!readMarker(in, out, spisok, marker)) 
    {
        out << "marker not found" << endl;
    }
    out << "\nresult of processing:\n\n";
    int initialSize = spisok.getSize();
    spisok.removeAllExcept(valueToSave);
    int removedCount = initialSize - spisok.getSize();
    spisok.printToFile(out, true);
    out.close();
}
