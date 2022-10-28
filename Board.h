#pragma once
#include "Field.h"
#include <iostream>

class Board {
public:
    Field board[8][8];

    string rows[8];

    string columns[8];

    Board();

    Field* getField(int x, int y);

    void drawBoard();
};
