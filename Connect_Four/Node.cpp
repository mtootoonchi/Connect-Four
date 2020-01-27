#include "Node.h"
Node::Node(char board[6][7], short row, short col, char alpha, char beta, bool maximizingPlayer) // true red ^
{
    this->col = col;
    WhoWin(board, row, maximizingPlayer);
    bool notOver = false;
    for (short i = 0; i < 7; i++)
    {
        if (board[0][i] == '-')
            notOver = true;
    }
    if (!(whowin == '0') && !(whowin == '2') && notOver)
    {
        if (maximizingPlayer)
        {
            char maxEval = '0';
            for (short i = 0; i < 7; i++)
            {
                if (board[0][i] == '-')
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
                            tempBoard[j][i] = 'R';
                            next = new Node(tempBoard, j, i, alpha, beta, !maximizingPlayer);
                            j = -1;
                        }
                    }
                    char eval = next->getWin();
                    delete next;
                    if (eval > maxEval)
                        maxEval = eval;
                    if (eval > alpha)
                        alpha = eval;
                    if (beta <= alpha)
                        i = 7;
                }
            }
            whowin = maxEval;
        }
        else
        {
            char minEval = '2';
            for (short i = 0; i < 7; i++)
            {
                if (board[0][i] == '-')
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
                            tempBoard[j][i] = 'Y';
                            next = new Node(tempBoard, j, i, alpha, beta, !maximizingPlayer);
                            j = -1;
                        }
                    }
                    char eval = next->getWin();
                    delete next;
                    if (eval < minEval)
                        minEval = eval;
                    if (eval < beta)
                        beta = eval;
                    if (beta <= alpha)
                        i = 7;
                }
            }
            whowin = minEval;
        }
    }
}

void Node::WhoWin(char board[6][7], short row, bool color)
{
    if (color)
    {
        if (goLeft(board, row, col - 1, color) + goRight(board, row, col + 1, color) > 2 || goUpLeft(board, row - 1, col - 1, color) + goDownRight(board, row + 1, col + 1, color) > 2 || goDownLeft(board, row + 1, col - 1, color) + goUpRight(board, row - 1, col + 1, color) > 2 || goDown(board, row + 1, col, color) > 2)
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
        if (goLeft(board, row, col - 1, color) + goRight(board, row, col + 1, color) > 2 || goUpLeft(board, row - 1, col - 1, color) + goDownRight(board, row + 1, col + 1, color) > 2 || goDownLeft(board, row + 1, col - 1, color) + goUpRight(board, row - 1, col + 1, color) > 2 || goDown(board, row + 1, col, color) > 2)
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goLeft(board, row, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goRight(board, row, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goDown(board, row + 1, col, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goUpRight(board, row - 1, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goUpLeft(board, row - 1, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goDownRight(board, row + 1, col + 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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
    if (row >= 0 && col >= 0 && row < 6 && col < 7)
    {
        if (color)
        {
            if (board[row][col] == 'R')
            {
                return 1 + goDownLeft(board, row + 1, col - 1, color);
            }
            else
                return 0;
        }
        else
        {
            if (board[row][col] == 'Y')
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

char Node::getWin()
{
    return whowin;
}

short Node::getCol()
{
	return col;
}

Node::~Node()
{
	//delete next;
}