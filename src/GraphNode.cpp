//
// Created by Jiří Heralt on 28.11.2022.
//

#include "GraphNode.h"

GraphNode::GraphNode(int value) {
   this->value = value;
}

void GraphNode::addParent(GraphNode *parent) {
    parents.push_back(parent);
}

vector<GraphNode *>* GraphNode::getParents() {
    return &this->parents;
}

int GraphNode::getValue() {
    return value;
}