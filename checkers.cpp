#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            game.board.board[i][j].fieldState = FieldState::field_empty;
        }
    }

    game.board.board[3][6].fieldState = FieldState::field_white;
    game.board.board[6][5].fieldState = FieldState::field_black;
    game.board.board[6][7].fieldState = FieldState::field_black;
    game.board.board[1][1].fieldState = FieldState::field_black;
    game.board.board[7][4].fieldState = FieldState::field_black;

    while (game.gameEnd() == false) {
        game.move();
    }
    game.board.drawBoard();
    
}

