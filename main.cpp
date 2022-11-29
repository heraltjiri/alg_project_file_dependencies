#include <iostream>
#include <string>
#include "src/DataImporter.h"
#include "src/DependencyFinder.h"

using namespace std;

int main(int argc, char* argv[]) {

    // Kontrola vstupnich parametru
    if (argc < 3) {
        cerr << "Chybny vstup. Pouziti: " << argv[0] << " VSTUPNI_SOUBOT.txt CISLO_ZMENENEHO_SOUBORU" << endl;

        return 1;
    }

    string inputFile = argv[1];
    int dependenciesFor;

    try {
        dependenciesFor = stoi(argv[2]);
    }
    catch (exception e) {
        cerr << "Chybny vstup. Druhý parametr musí být integer." << endl;
        return 1;
    }

    // Importování dat ze souboru
    DataImporter dataImporter;

    if (!dataImporter.readFile(inputFile)) {
        return 1;
    }

    // Nalezení závislostí
    DependencyFinder finder(dataImporter.getResultGraph());
    finder.findDependenciesFor(dependenciesFor);

    // Vypsání výsledku
    cout << endl << "Závislé soubory: " << endl;
    for (auto e : finder.getResult()) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
