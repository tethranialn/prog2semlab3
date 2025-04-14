#include "FileProcessing.h"
#include <iostream>
bool readMarker(ifstream& in, ofstream& out, List& list, const char marker) {
    char buffer[256];
    int lineCount = 0;
    bool markerFound = false;

    while (in.getline(buffer, 255)) {
        int i = 0;
        bool foundMarker = false;
        while (buffer[i] != '\0') {
            if (buffer[i] == marker) {
                foundMarker = true;
                buffer[i] = '\0'; 
                break;
            }
            i++;
        }

        if (foundMarker) {
            markerFound = true;
        }

        list.push_back(buffer);
        out << "-> " << buffer << '\n';
        lineCount++;

        if (markerFound) break;
    }

    out << "\nВсего считано строк: " << lineCount << '\n';
    return markerFound;
}

void processFile(const char* inputFile, const char* outputFile) {
    List list;
    ofstream out(outputFile);
    if (!out) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    ifstream in(inputFile);
    if (!in) {
        out << "ОШИБКА: Не удалось открыть входной файл!" << endl;
        out.close();
        return;
    }

    out << "---ДАННЫЕ ИЗ ФАЙЛА---\n";

    char marker;
    in >> marker;
    in.ignore(); 
    while (in.peek() == ' ') in.get(); 

    char valueToDelete[256];
    in.getline(valueToDelete, 255); 
    out << "Заданный элемент для удаления: \"" << valueToDelete << "\"\n";

    if (!readMarker(in, out, list, marker)) {
        out << "Маркер не найден!" << endl;
    }

    out << "\n---РЕЗУЛЬТАТ ОБРАБОТКИ---\n";

    int initialSize = list.getSize();
    list.removeLast(valueToDelete);
    int removedCount = initialSize - list.getSize();

    list.printToFile(out, true);

    out.close();
}
