//
// Created by Jiří Heralt on 29.11.2022.
//

#include "DependencyFinder.h"

DependencyFinder::DependencyFinder(Graph *graph) {
    this->graph = graph;
}

void DependencyFinder::findDependenciesFor(int number) {
    this->result.push_back(number);
    this->resultReady = false;

    GraphNode* node = graph->getNode(number);

    for (GraphNode*  parentNode : *node->getParents()) {
        findDependenciesFor(parentNode->getValue());
    }
}

vector<int> DependencyFinder::getResult() {
    if (!this->resultReady) {
        this->prepareResult();
    }
    return this->result;
}

void DependencyFinder::prepareResult() {
    sort( this->result.begin(), this->result.end() );
    this->result.erase( unique( this->result.begin(), this->result.end() ), this->result.end() );
}