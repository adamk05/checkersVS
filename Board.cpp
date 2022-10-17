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
            cout << "1";
        }

        if (i == 1) {
            cout << "2";
        }

        if (i == 2) {
            cout << "3";
        }

        if (i == 3) {
            cout << "4";
        }

        if (i == 4) {
            cout << "5";
        }

        if (i == 5) {
            cout << "6";
        }

        if (i == 6) {
            cout << "7";
        }

        if (i == 7) {
            cout << "8";
        }

        for (int j = 0; j < 8; j++)
        {
            if (this->board[i][j].fieldState == FieldState::field_empty) {
                cout << (char)179 << " ";
            }
            else if (this->board[i][j].fieldState == FieldState::field_black) {
                cout << (char)179 << "b";
            }
            else{
                cout << (char)179 << "w";
            }

        }
        cout << (char)179 << endl;


    };
    cout << " ";
    cout << (char)192 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)193 << (char)196 << (char)217 << endl;
    cout << " ";
    for (int k = 0;k < 8;k++) {

        if (k == 0) {
            cout << " A ";
        }

        if (k == 1) {
            cout << "B ";
        }

        if (k == 2) {
            cout << "C ";
        }

        if (k == 3) {
            cout << "D ";
        }

        if (k == 4) {
            cout << "E ";
        }

        if (k == 5) {
            cout << "F ";
        }

        if (k == 6) {
            cout << "G ";
        }

        if (k == 7) {
            cout << "H";
        }
    }

}