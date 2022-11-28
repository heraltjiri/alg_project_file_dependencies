#include <iostream>
#include <string>
#include "src/DataImporter.h"

using namespace std;

int main() {
    string inputFile = "data.txt";
    DataImporter* dataImporter = new DataImporter();
    dataImporter->readFile(inputFile);

    return 0;
}
