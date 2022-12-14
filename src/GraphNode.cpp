//
// Created by Jiří Heralt on 28.11.2022.
//

#include "GraphNode.h"

/**
 * @brief Konstruktor třídy GraphNode
 * @param value Hodnota vrcholu
 */
GraphNode::GraphNode(int value) {
   this->value = value;
}

/**
 * @bried Přidá vazbu na rodiče vrcholu
 * @param parent Pointer na rodičovský vrchol
 */
void GraphNode::addParent(GraphNode *parent) {
    parents.push_back(parent);
}

/**
 * @bried Metoda na získání přímých rodičů vrcholu (pouze přímí)
 * @return Vrátí přímé rodiče vrcholu
 */
vector<GraphNode *>* GraphNode::getParents() {
    return &this->parents;
}

/**
 * @bried Metoda na získání hodnoty vrcholu
 * @return Hodnota vrcholu
 */
int GraphNode::getValue() {
    return value;
}


/**
 * @bried Metoda na nastavení informace, zda byl daný vrchol již navštívený (pro průchod grafem)
 */
void GraphNode::setVisited(bool visited) {
    this->visited = visited;
}


/**
 * @bried Metoda na získání informace, zda byl daný vrchol již navštívený
 * @return Byl vrchol navštívený?
 */
bool GraphNode::getVisited() {
    return visited;
}
