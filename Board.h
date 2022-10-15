#pragma once
#include "Field.h"

class Board {
public:
    Field board[8][8];

    Board();

    Field* getField(int x, int y);

    void drawBoard();
};
