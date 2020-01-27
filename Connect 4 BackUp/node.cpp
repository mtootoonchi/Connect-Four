#include "node.h"

unsigned int Node::amountOfNodes = 0;

Node::Node()
{
    //color = true;
    amountOfNodes++;
    for(short i = 0; i < 7; i++)
    {
        char temp[6][7];
        for(short j = 0; j < 6; j++)
        {
            for(short k = 0; k < 7; k++)
            {
                temp[j][k] = '-';
            }
        }
        temp[5][i] = 'R';
        arr[i] = new Node(temp, 5, i, false);
    }
}

Node::Node(char board[6][7], short row, short col, bool color)
{
    /*
    for(short i = 0; i < 6; i++)
    {
        for(short j = 0; j < 7; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }*/
    this->col = col;
    //this->color = color;
    NospacesLeft = true;
    amountOfNodes++;
    WhoWin(board, row, color);

    for(short i = 0; i < 7; i++)
    {
        arr[i] = nullptr;
        if(board[0][i] == '-')
            NospacesLeft = false;
    }
    if(!NospacesLeft && (whowin == '1'))
    {
        for(short i = 0; i < 7; i++)
        {
            char temp[6][7];
            for(short j = 0; j < 6; j++)
            {
                for(short k = 0; k < 7; k++)
                {
                    temp[j][k] = board[j][k];
                }
            }
            for(short j = 5; j >= 0; j--)
            {
                if(temp[j][i] == '-')
                {
                    if(color)
                    {
                        temp[j][i] = 'R';
                    }
                    else
                    {
                        temp[j][i] = 'Y';
                    }
                    arr[i] = new Node(temp, j, i, !color);
                    j = -1;
                }
            }
        }
    }
}

Node* Node::minimax(bool maximizingPlayer, char alpha, char beta)
{
    Node* ranArr[7];
    char evals[7];
    short maxArr = 0;
    char bestOption;
    for(short i = 0; i < 7; i++)
    {
        ranArr[i] = nullptr;
    }
    if(maximizingPlayer)
    {
        bestOption = '0';
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != nullptr)
            {
                evals[i] = arr[i]->staticEval(!maximizingPlayer, alpha, beta);
                if(evals[i] > bestOption)
                    bestOption = evals[i];
            }
        }
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != nullptr && evals[i] == bestOption)
            {
                ranArr[i] = arr[i];
                maxArr++;
            }
        }
        return ranArr[rand() % maxArr];
    }
    else
    {
        bestOption = '2';
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != nullptr)
            {
                evals[i] = arr[i]->staticEval(!maximizingPlayer, alpha, beta);
                if(evals[i] < bestOption)
                    bestOption = evals[i];
            }
        }
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != nullptr && evals[i] == bestOption)
            {
                ranArr[i] = arr[i];
                maxArr++;
            }
        }
        return ranArr[rand() % maxArr];
    }
}

char Node::staticEval(bool maximizingPlayer, char alpha, char beta)
{
    if(whowin == '0' || whowin == '2' || NospacesLeft)
    {
        return whowin;
    }
    if(maximizingPlayer)
    {
        char maxEval = '0';
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != nullptr)
            {
                char eval = arr[i]->staticEval(!maximizingPlayer, alpha, beta);
                if(eval > maxEval)
                    maxEval = eval;
                if(eval > alpha)
                    alpha = eval;
                if(beta <= alpha)
                    i = 7;
            }
        }
        return maxEval;
    }
    else
    {
        char minEval = '2';
        for(short i = 0; i < 7; i++)
        {
            if(arr[i] != 0)
            {
                char eval = arr[i]->staticEval(!maximizingPlayer, alpha, beta);
                if(eval < minEval)
                    minEval = eval;
                if(eval < beta)
                    beta = eval;
                if(beta <= alpha)
                    i = 7;
            }
        }
        return minEval;
    }
}

Node* Node::humanpick(short col)
{
    for(short i = 0; i < 7; i++)
    {
        if(arr[i] != nullptr)
        {
            if(arr[i]->getCol() == col)
            {
                return arr[i];
            }
        }
    }
}

short Node::getCol()
{
    return col;
}

void Node::WhoWin(char board[6][7], short row, bool color)
{
    if(color)
    {
        if(goLeft(board, row, col - 1, color) + goRight(board, row, col + 1, color) > 2 || goUpLeft(board, row - 1, col - 1, color) + goDownRight(board, row + 1, col + 1, color) > 2 || goDownLeft(board, row + 1, col - 1, color) + goUpRight(board, row - 1, col + 1, color) > 2 || goDown(board, row + 1, col, color) > 2)
        {
            whowin = '2';
        }
        else
        {
            whowin = '1';
        }
    }
    else
    {
        if(goLeft(board, row, col - 1, color) + goRight(board, row, col + 1, color) > 2 || goUpLeft(board, row - 1, col - 1, color) + goDownRight(board, row + 1, col + 1, color) > 2 || goDownLeft(board, row + 1, col - 1, color) + goUpRight(board, row - 1, col + 1, color) > 2 || goDown(board, row + 1, col, color) > 2)
        {
            whowin = '0';
        }
        else
        {
            whowin = '1';
        }
    }
}

short Node::goLeft(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goLeft(board, row, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goLeft(board, row, col - 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goRight(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goRight(board, row, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goRight(board, row, col + 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goDown(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goDown(board, row + 1, col, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goDown(board, row + 1, col, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goUpRight(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goUpRight(board, row - 1, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goUpRight(board, row - 1, col + 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goUpLeft(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goUpLeft(board, row - 1, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goUpLeft(board, row - 1, col - 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goDownRight(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goDownRight(board, row + 1, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goDownRight(board, row + 1, col + 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}

short Node::goDownLeft(char board[6][7], short row, short col, bool color)
{
    if(row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if(color)
        {
            if(board[row][col] == 'R')
            {
                return 1 + goDownLeft(board, row + 1, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if(board[row][col] == 'Y')
            {
                return 1 + goDownLeft(board, row + 1, col - 1, color);
            }
            else
                return 0;
        }
    }
    else
        return 0;
}
