//
// Created by Jiří Heralt on 28.11.2022.
//
using namespace std;

#ifndef ALG2_PROJECT_DATAIMPORTER_H
#define ALG2_PROJECT_DATAIMPORTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Graph.h"

#define DATA_DELIMITER "->"

/**
 * @brief Jednoduchá třída starající se o správé naimportování vstupních dat
 */
class DataImporter {
public:
    DataImporter();
    ~DataImporter();
    bool readFile(string fileName);
    Graph* getResultGraph();

private:
    /**
     * @brief Uchovává výsledný vygenerovaný graf
     */
    Graph* resultGraph;
};


#endif //ALG2_PROJECT_DATAIMPORTER_H
