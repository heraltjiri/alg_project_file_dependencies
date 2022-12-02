//
// Created by Jiří Heralt on 28.11.2022.
//

#ifndef ALG2_PROJECT_GRAPH_H
#define ALG2_PROJECT_GRAPH_H
#include "GraphNode.h"
#include <map>

using namespace std;

/**
 * @brief Jednoduchá třída reprezentující graf
 */
class Graph {
private:
    /**
     * @brief Všechny vrcholy grafu
     */
    map<int, GraphNode*> *vertices;
public:
    Graph();
    ~Graph();
    void addVertex(int number);
    void addEdge(int source, int target);
    GraphNode* getNode(int number);
};

#endif //ALG2_PROJECT_GRAPH_H
