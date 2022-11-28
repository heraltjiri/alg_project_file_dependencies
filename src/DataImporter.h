//
// Created by Jiří Heralt on 28.11.2022.
//
using namespace std;

#ifndef ALG2_PROJECT_DATAIMPORTER_H
#define ALG2_PROJECT_DATAIMPORTER_H

#include <string>
#include <iostream>
#include <fstream>

#define DATA_DELIMITER "->"

class DataImporter {
public:
    bool readFile(string fileName);

private:
    bool dataLoaded;
};


#endif //ALG2_PROJECT_DATAIMPORTER_H
