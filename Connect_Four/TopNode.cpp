#include "TopNode.h"
#include <iostream>
TopNode::TopNode(char board[6][7], bool maximizingPlayer)
{
	for (short i = 0; i < 7; i++)
	{
		char tempBoard[6][7];
        for (short j = 0; j < 6; j++)
        {
            for (short k = 0; k < 7; k++)
            {
                tempBoard[j][k] = board[j][k];
            }
        }
        for (short j = 5; j >= 0; j--)
        {
            if (board[j][i] == '-')
            {
                if (maximizingPlayer)
                    tempBoard[j][i] = 'R';
                else
                    tempBoard[j][i] = 'Y';
                arr[i] = new Node(tempBoard, j, i, '0', '2', !maximizingPlayer);
                j = -1;
            }
        }
	}
    if (maximizingPlayer)
    {
        bestValue = '0';
        for (short i = 0; i < 7; i++)
        {
            if (arr[i]->getWin() > bestValue)
                bestValue = arr[i]->getWin();
        }
    }
    else
    {
        bestValue = '2';
        for (short i = 0; i < 7; i++)
        {
            if (arr[i]->getWin() < bestValue)
                bestValue = arr[i]->getWin();
        }
    }
    amountOfBestNodes = 0;
    for (short i = 0; i < 7; i++)
    {
        if (arr[i]->getWin() == bestValue)
        {
            bestNodes[amountOfBestNodes] = arr[i];
            amountOfBestNodes++;
        }
    }
    colDecision = bestNodes[rand() % amountOfBestNodes]->getCol();
    delete[] bestNodes;
}

short TopNode::getColDecision()
{
    return colDecision;
}

TopNode::~TopNode()
{
	delete[] arr;
}