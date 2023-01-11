#pragma once
#include "Player.h"
#include "Board.h"

class Game {
public:
    Player player1;
    Player player2;
    Player actualPlayer;
    Board board;
    Player winner;

    Game();
    bool move();
    bool move(int x, int y);
    bool gameEnd();
};