#include <iostream>
#include <string>
#include "src/DataImporter.h"
#include "src/DependencyFinder.h"

using namespace std;

int main() {
    string inputFile = "data.txt";
    int dependenciesFor = 10;

    DataImporter dataImporter;

    if (dataImporter.readFile(inputFile) == false) {
        return 1;
    }

    DependencyFinder finder(dataImporter.getResultGraph());
    finder.findDependenciesFor(dependenciesFor);


    for (auto e : finder.getResult()) {

        cout << e << " ";
    }

    return 0;
}
