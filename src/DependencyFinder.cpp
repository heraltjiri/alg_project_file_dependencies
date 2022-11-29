//
// Created by Jiří Heralt on 29.11.2022.
//

#include "DependencyFinder.h"

DependencyFinder::DependencyFinder(Graph *graph) {
    this->graph = graph;
}

vector<int>* DependencyFinder::getDependenciesFor(int number) {
    printf("%d, ", number);

    GraphNode* node = graph->getNode(number);

    for (GraphNode*  parentNode : *node->getParents()) {
        //printf("Val: %d /", parentNode->getValue());
        getDependenciesFor(parentNode->getValue());
    }
}