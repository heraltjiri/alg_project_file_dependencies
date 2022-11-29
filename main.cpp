#include <iostream>
#include <string>
#include "src/DataImporter.h"
#include "src/DependencyFinder.h"

using namespace std;

int main() {
    string inputFile = "data.txt";
    DataImporter dataImporter;

    if (dataImporter.readFile(inputFile) == false) {
        return 1;
    }

    DependencyFinder finder(dataImporter.getResultGraph());
    finder.getDependenciesFor(1);

    return 0;
}
