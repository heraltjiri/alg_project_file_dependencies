//
// Created by Jiří Heralt on 28.11.2022.
//

#include "DataImporter.h"

DataImporter::DataImporter() {
    resultGraph = new Graph();
}

DataImporter::~DataImporter() {
    delete resultGraph;
}

bool DataImporter::readFile(string fileName) {
    ifstream infile(fileName);

    string line;
    if (infile.is_open()) {
        int row = 0;
        while (getline(infile, line))
        {
            row++;
            string delimiter = DATA_DELIMITER;
            int position = line.find(delimiter);

            if (position == string::npos) { // If delimiter was not found in the line
                cout << "Chyba na řádku " << row << " vstupního souboru. Každý řádek vstupního souboru musí obsahovat dělící znak " << DATA_DELIMITER << "." << endl;
                return false;
            }

            string source = line.substr(0, position);
            string target = line.substr(position + delimiter.length());

            int sourceInt;
            int targetInt;
            try {
                sourceInt = stoi(source);
                targetInt = stoi(target);
            }
            catch (const std::exception & e) {
                cout << "Neplatná hodnota na řádku " << row << "." << endl;
            }

            resultGraph->addEdge(sourceInt, targetInt);

            printf("%d -> %d \n", sourceInt, targetInt);
        }
        infile.close();
    }
    else {
        cout << "Chyba. Nepodařilo se otevřít soubor." << endl;
        return false;
    }
}
