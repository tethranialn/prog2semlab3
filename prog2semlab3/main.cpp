/*
Удалить все элементы со значениями, отличающимися от заданного значения
*/
#include "functions.h"
#include <iostream>
using namespace std;
void main()
{
    const char* inputFile = "in.txt";
    const char* outputFile = "out.txt";
    processFile(inputFile, outputFile);
    cout << "processing completed" << endl;
}