//
// Created by Jiří Heralt on 29.11.2022.
//

#include "DependencyFinder.h"

/**
 * @brief Konstruktor třídy DependencyFinder
 * @param graph vstupní graf, nad kterým budeme hledat závislosti
 */
DependencyFinder::DependencyFinder(Graph *graph) {
    this->graph = graph;
}

/**
 * @brief Spustí vyhledávání závislostí nad grafem
 * @param number Číslo vrcholu, který hledáme
 */
void DependencyFinder::findDependenciesFor(int number) {

    // Avoid circular dependency
    if (find(this->result.begin(), this->result.end(), number) != this->result.end()) {
        return;
    }

    this->result.push_back(number);
    this->resultReady = false;

    GraphNode* node = graph->getNode(number);

    for (GraphNode*  parentNode : *node->getParents()) {
        findDependenciesFor(parentNode->getValue());
    }
}

/**
 * @brief Metoda na vrácení výsledku, pokud je potřeba tak jej seřadí
 * @return Vrátí seřazený vektor s výsledkem
 */
vector<int> DependencyFinder::getResult() {
    if (!this->resultReady) {
        this->prepareResult();
    }
    return this->result;
}

/**
 * @brief Připraví výsledek na výstup
 */
void DependencyFinder::prepareResult() {
    sort( this->result.begin(), this->result.end() );
    // Unique results
    //this->result.erase( unique( this->result.begin(), this->result.end() ), this->result.end() );
    this->resultReady = true;
}