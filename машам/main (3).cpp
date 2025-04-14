#include "FileProcessing.h"
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    const char* inputFile = "inp.txt";
    const char* outputFile = "out.txt";

    processFile(inputFile, outputFile);

    cout << "Обработка завершена" << endl;

    return 0;
}
