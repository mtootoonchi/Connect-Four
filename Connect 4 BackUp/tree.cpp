#include "tree.h"

Tree::Tree()
{
    topNode = new Node();
    currentNode = topNode;
    //firstTime = true;
}

short Tree::getAIpick(bool maximizingPlayer) // true red is AI
{
    currentNode = currentNode->minimax(maximizingPlayer, '0', '2');
    return currentNode->getCol();
}

void Tree::sendHumanpick(short col)
{
    currentNode = currentNode->humanpick(col);
}

void Tree::resetTree()
{
    currentNode = topNode;
}
