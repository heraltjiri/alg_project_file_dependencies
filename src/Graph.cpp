//
// Created by Jiří Heralt on 28.11.2022.
//

#include <string>
#include <iostream>
#include "Graph.h"

using namespace std;

/**
 * @brief Konstruktor třídy Graph
 */
Graph::Graph() {
    vertices = new map<int,GraphNode*>();
}

/**
 * @brief Destruktor třídy Graph
 */
Graph::~Graph() {
    vertices->clear();
    delete vertices;
}

/**
 * @bried Metoda na přidání orientované hrany grafu mezi dvěma vrcholy
 * @param source První vrchol (ze kterého jde hrana)
 * @param target Druhý vrchol (do kterého hrana směřuje)
 */
void Graph::addEdge(int source, int target) {
    // Insert or find source node in graph
    GraphNode* sourceNode = nullptr;
    if (vertices->find(source) == vertices->end()) {
        sourceNode = new GraphNode(source);
        vertices->insert(pair<int, GraphNode*>(source, sourceNode));
    }
    else {
        sourceNode = vertices->at(source);
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

/**
 * @brief Metoda na získání uzlu grafu podle jeho hodnoty
 * @param number Hodnota vrcholu
 * @return Vrátí pointer na vrchol grafu pokud existuje, jinak nullptr
 */
GraphNode *Graph::getNode(int number) {
    if (vertices->find(number) == vertices->end()) {
        return nullptr;
    }
    else {
        return vertices->at(number);
    }
}