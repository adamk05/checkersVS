#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Color.h"
#include "Field.h"
#include "FieldState.h"
#include "cstdlib"
#include "iostream"
#include "time.h"
using namespace std;

Game::Game() {
    string name1;
    string name2;
    
    cout<<endl;
    cout << "wybierz swoj nick graczu 1!" << endl;
    cin >> name1;

    cout << "wybierz swoj nick graczu 2!" << endl;
    cin >> name2;

    srand(time(0));
    int color = rand() % 2 + 1;
    

    if (color == 1) {
        Player p1(name1, white);
        Player p2(name2, black);

        this->player1 = p1;
        this->player2 = p2;

        cout << "gracz " << name1 << " zaczyna";
    }
    else {
        Player p1(name1, black);
        Player p2(name2, white);

        this->player1 = p1;
        this->player2 = p2;

        cout << "Gracz " << name2 << " zaczyna!";
    }

    
}

void Game::move() {

}

bool Game::gameEnd() {
	return false;
}