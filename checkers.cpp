#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
<<<<<<< HEAD
  
    game.board.board[6][1].fieldState = field_white;
    game.board.board[7][0].fieldState = field_empty;
    game.board.board[1][6].fieldState = field_black;
    game.board.board[0][7].fieldState = field_empty;
=======

    game.board.board[1][2].fieldState = field_black;
    game.board.board[0][1].fieldState = field_empty;
    game.board.board[7][0].fieldState = field_empty;
    game.board.board[7][6].fieldState = field_empty;
>>>>>>> adam

    while (game.gameEnd() == false) {
        game.move();
    }
    game.board.drawBoard();
    
}

