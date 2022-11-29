//
// Created by Jiří Heralt on 28.11.2022.
//

#ifndef ALG2_PROJECT_GRAPHNODE_H
#define ALG2_PROJECT_GRAPHNODE_H
#include <vector>

using namespace std;

class GraphNode {
private:
    int value;
    vector<GraphNode*> parents;
public:
    GraphNode(int value);
    void addParent(GraphNode* parent);
};


#endif //ALG2_PROJECT_GRAPHNODE_H
