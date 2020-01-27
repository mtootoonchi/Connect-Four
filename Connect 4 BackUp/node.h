#ifndef NODE_H
#define NODE_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <ctime>
using std::time;
using namespace std;

class Node
{
public:
    static unsigned int amountOfNodes;
    Node();
    short getCol();
    Node* minimax(bool maximizingPlayer, char alpha, char beta);
    Node* humanpick(short col);

private:
    Node(char board[6][7], short row, short col, bool color);
    //char board[6][7];
    Node* arr[7];
    short col;
    //bool color; // true means Red
    char whowin; // 2 = Red, 1 = Tie/Undecided, 0 = Yellow
    bool NospacesLeft;
    char staticEval(bool maximizingPlayer, char alpha, char beta);
    void WhoWin(char[6][7], short row, bool color);
    short goLeft(char[6][7], short row, short col, bool color);
    short goRight(char[6][7], short row, short col, bool color);
    short goDown(char[6][7], short row, short col, bool color);
    short goUpRight(char[6][7], short row, short col, bool color);
    short goUpLeft(char[6][7], short row, short col, bool color);
    short goDownRight(char[6][7], short row, short col, bool color);
    short goDownLeft(char[6][7], short row, short col, bool color);

};

#endif // NODE_H
