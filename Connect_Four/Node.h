//#ifndef NODE_H
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
	Node(char[6][7], short row, short col, char alpha, char beta, bool maximizingPlayer);
	~Node();
	short getCol();
	char getWin();

private:
	Node* next;
	short col;
	char whowin;
	void WhoWin(char[6][7], short row, bool color);
	short goLeft(char[6][7], short row, short col, bool color);
	short goRight(char[6][7], short row, short col, bool color);
	short goDown(char[6][7], short row, short col, bool color);
	short goUpRight(char[6][7], short row, short col, bool color);
	short goUpLeft(char[6][7], short row, short col, bool color);
	short goDownRight(char[6][7], short row, short col, bool color);
	short goDownLeft(char[6][7], short row, short col, bool color);
};

