//
// Created by Jiří Heralt on 29.11.2022.
//

#ifndef ALG2_PROJECT_DEPENDENCYFINDER_H
#define ALG2_PROJECT_DEPENDENCYFINDER_H
#include "Graph.h"

class DependencyFinder {
private:
    Graph* graph;
    vector<int> result;
    bool resultReady = false;
    void prepareResult();
public:
    DependencyFinder(Graph *graph);
    void findDependenciesFor(int number);
    vector<int> getResult();

};


#endif //ALG2_PROJECT_DEPENDENCYFINDER_H
