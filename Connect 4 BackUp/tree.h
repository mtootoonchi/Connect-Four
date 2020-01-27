#ifndef TREE_H
#define TREE_H
#include "node.h"


class Tree
{

private:
    Node* topNode;
    Node* currentNode;
    //bool firstTime;

public:
    Tree();
    short getAIpick(bool maximizingPlayer);
    void sendHumanpick(short col);
    void resetTree();
};

#endif // TREE_H
