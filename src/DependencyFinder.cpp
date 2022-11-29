//
// Created by Jiří Heralt on 29.11.2022.
//

#include "DependencyFinder.h"

DependencyFinder::DependencyFinder(Graph *graph) {
    this->graph = graph;
}

void DependencyFinder::findDependenciesFor(int number) {
    this->result.push_back(number);

    GraphNode* node = graph->getNode(number);

    for (GraphNode*  parentNode : *node->getParents()) {
        findDependenciesFor(parentNode->getValue());
    }
}

vector<int> DependencyFinder::getResult() {
    return this->result;
}