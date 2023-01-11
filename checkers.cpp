#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    game.board.board[1][2].fieldState = field_black;
    game.board.board[0][1].fieldState = field_empty;
    game.board.board[7][0].fieldState = field_empty;
    game.board.board[7][6].fieldState = field_empty;
    while (true) {
        game.move();
    }
    game.board.drawBoard();
}

