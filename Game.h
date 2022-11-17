#pragma once
#include "Player.h"
#include "Board.h"

class Game {
public:
    Player player1;
    Player player2;
    Player actualPlayer;
    Board board;

    Game();
    bool move();
    bool gameEnd();
};