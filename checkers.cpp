#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    while (true) {
        game.move();
    }
    game.board.drawBoard();
}

