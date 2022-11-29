//
// Created by Jiří Heralt on 28.11.2022.
//

#include <string>
#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph() {
    vertices = new map<int,GraphNode*>();
}
Graph::~Graph() {
    vertices->clear();
    delete vertices;
}

void Graph::addEdge(int source, int target) {
    // Insert or find source node in graph
    GraphNode* sourceNode = nullptr;
    if (vertices->find(source) == vertices->end()) {
        sourceNode = new GraphNode(source);
        vertices->insert(pair<int, GraphNode*>(source, sourceNode));
    }
    else {
        GraphNode* sourceNode = vertices->at(source);
    }

    // Insert or find target node in graph
    GraphNode* targetNode = nullptr;

    if (vertices->find(target) == vertices->end()) {
        targetNode = new GraphNode(target);
        vertices->insert(pair<int, GraphNode*>(target, targetNode));
        targetNode->addParent(sourceNode);
    }
    else {
        GraphNode* targetNode = vertices->at(target);
        targetNode->addParent(sourceNode);
    }
}
