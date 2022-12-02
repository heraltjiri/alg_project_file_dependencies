//
// Created by Jiří Heralt on 29.11.2022.
//

#ifndef ALG2_PROJECT_DEPENDENCYFINDER_H
#define ALG2_PROJECT_DEPENDENCYFINDER_H
#include "Graph.h"

/**
 * @brief Třídá která se stará o správné vyhledání závislostí vrcholů v grafu
 */
class DependencyFinder {
private:
    /**
     * @brief Graf, ve kterém hledáme závislosti
     */
    Graph* graph;

    /**
     * @brief Výsledný výstup - které vrcholy jsou na vstupním závislé
     */
    vector<int> result;

    /**
     * @brief Hodnota znamená, jestli již je výsledek připravený na výstup (např. správné seřazení) nebo ne
     */
    bool resultReady = false;

    void prepareResult();
public:
    DependencyFinder(Graph *graph);
    void findDependenciesFor(int number);
    vector<int> getResult();

};


#endif //ALG2_PROJECT_DEPENDENCYFINDER_H
