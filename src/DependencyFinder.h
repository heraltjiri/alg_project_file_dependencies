//
// Created by Jiří Heralt on 29.11.2022.
//

#ifndef ALG2_PROJECT_DEPENDENCYFINDER_H
#define ALG2_PROJECT_DEPENDENCYFINDER_H
#include "Graph.h"

class DependencyFinder {
private:
    Graph* graph;
public:
    DependencyFinder(Graph *graph);
    vector<int>* getDependenciesFor(int number);

};


#endif //ALG2_PROJECT_DEPENDENCYFINDER_H
