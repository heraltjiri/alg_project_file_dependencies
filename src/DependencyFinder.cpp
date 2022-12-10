//
// Created by Jiří Heralt on 29.11.2022.
//

#include <algorithm>
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
    GraphNode* node = graph->getNode(number);

    if (node == nullptr) {
        return;
    }

    if (node->getVisited()) {
        return;
    }

    // Označíme vrchol jako objevený
    node->setVisited();

    this->result.push_back(number);
    this->resultReady = false;

    // Pokračujeme rekurzivně v průchodu grafem dál, i pro všechny "rodiče" daného vrcholu
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
    this->resultReady = true;
}

/**
 * @brief Zjistí, jestli se v grafu vyskytovaly nějaké závislosti nebo ne (výsledek je prázdný)
 */
bool DependencyFinder::hasDependencies() {
    if (this->result.size() == 0) {
        return false;
    }
    return true;
}
