#pragma once
#include "Field.h"
#include <string>
#include <iostream>

class Board {
public:
    Field board[8][8];

    std::string columns[8] = { "A", "B", "C", "D", "E", "F", "G", "H" };

    std::string rows[8] = { "1", "2", "3", "4", "5", "6", "7", "8" };

    Board();

    Field* getField(int x, int y);

    void drawBoard();
};
