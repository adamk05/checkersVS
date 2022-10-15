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
    cout << " " << (char)218 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)194 << (char)196 << (char)191 << endl;

    for (int i = 0; i < 8; i++)
    {

        if (i == 0) {
            cout << "A";
        }

        if (i == 1) {
            cout << "B";
        }

        if (i == 2) {
            cout << "C";
        }

        if (i == 3) {
            cout << "D";
        }

        if (i == 4) {
            cout << "E";
        }

        if (i == 5) {
            cout << "F";
        }

        if (i == 6) {
            cout << "G";
        }

        if (i == 7) {
            cout << "H";
        }

        for (int j = 0; j < 8; j++)
        {
            if (this->board[i][j].fieldState == FieldState::field_empty) {
                cout << (char)179 << " ";
            }
            else if (this->board[i][j].fieldState == FieldState::field_black) {
                cout << (char)179 << "x";
            }
            else{
                cout << (char)179 << "o";
            }

        }
        cout << (char)179 << endl;


    };
    cout << " ";
    cout << (char)192 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)217 << endl;
    cout << " ";
    for (int k = 1;k < 9;k++) {

        cout << " " << k;
    }

}