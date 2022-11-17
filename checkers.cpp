#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    game.move();
    game.move();
    game.board.drawBoard();
}

