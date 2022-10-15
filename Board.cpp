#include "Board.h"
#include "Field.h"
#include "FieldState.h"
#include "iostream"

using namespace std;

Board::Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Field field(i, j);
            this->board[i][j] = field;

            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    this->board[i][j].fieldState = FieldState::field_empty;
                }
                else
                {
                    if (i <= 2)
                    {
                        this->board[i][j].fieldState = FieldState::field_white;
                    }
                    else if (i >= 5)
                    {
                        this->board[i][j].fieldState = FieldState::field_black;
                    }
                    else
                    {
                        this->board[i][j].fieldState = FieldState::field_empty;
                    }
                }
            }
            else
            {
                if (j % 2 != 0)
                {
                    this->board[i][j].fieldState = FieldState::field_empty;
                }
                else
                {
                    if (i <= 2)
                    {
                        this->board[i][j].fieldState = FieldState::field_white;
                    }
                    else if (i >= 5)
                    {
                        this->board[i][j].fieldState = FieldState::field_black;
                    }
                    else
                    {
                        this->board[i][j].fieldState = FieldState::field_empty;
                    }
                }
            }
        }
    }
}

Field* Board::getField(int x, int y)
{
    return &this->board[x][y];
}

void Board::drawBoard()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (this->board[i][j].fieldState)
            {
            case FieldState::field_empty:
                cout << "O ";
                break;
            case FieldState::field_black:
                cout << "# ";
                break;
            case FieldState::field_white:
                cout << "& ";
                break;
            default:
                break;
            }
        }
        cout << "\n";
    }
}