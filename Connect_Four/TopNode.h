#include "Node.h"
class TopNode
{
public:
	TopNode(char[6][7], bool maximizingPlayer); // max true = red
	~TopNode();
	short getColDecision();

private:
	Node* arr[7];
	Node* bestNodes[7];
	short amountOfBestNodes;
	short colDecision;
	char bestValue;
};

