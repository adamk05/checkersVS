#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    game.board.board[6][1].fieldState = field_white;
    game.board.board[6][5].fieldState = field_white;
    game.board.board[7][0].fieldState = field_empty;
    game.board.board[7][6].fieldState = field_empty;

    for (int i = 0;i < 8;i++) {
        for (int j = 0; j < 8;j++) {
            game.board.board[i][j].fieldState = field_empty;
        }
    }

   
    game.board.board[3][1].fieldState = field_white;
    game.board.board[5][1].fieldState = field_black;
    game.board.board[6][2].fieldState = field_black;
    game.board.board[7][3].fieldState = field_black;

  
   

   
    while (game.gameEnd() == false) {
        game.move();
    }
    game.board.drawBoard();
    
}

