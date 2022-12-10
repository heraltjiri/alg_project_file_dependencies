//
// Created by Jiří Heralt on 28.11.2022.
//

#ifndef ALG2_PROJECT_GRAPHNODE_H
#define ALG2_PROJECT_GRAPHNODE_H
#include <vector>

using namespace std;

/**
 * @brief Jednoduchá třída reprezentující vrchol grafu
 */
class GraphNode {
private:
    /**
     * @brief Hodnota vrcholu
     */
    int value;

    /**
     * @brief Vazba na rodiče vrcholu
     */
    vector<GraphNode*> parents;

    /**
     * @brief Určuje jestli byl již tento vrchol navštíven (označování navštívených vrcholů pro průchod grafem)
     */
    bool visited = false;
public:
    GraphNode(int value);
    void addParent(GraphNode* parent);
    vector<GraphNode*>* getParents();
    int getValue();
    void setVisited(bool visited = true);
    bool getVisited();
};


#endif //ALG2_PROJECT_GRAPHNODE_H
