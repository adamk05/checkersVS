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
    cout << "Wybierz swoj nick graczu 1!" << endl;
    cin >> name1;

    cout << "Wybierz swoj nick graczu 2!" << endl;
    cin >> name2;

    srand(time(0));
    int color = rand() % 2 + 1;
    

    if (color == 1) {
        Player p1(name1, white);
        Player p2(name2, black);

        this->player1 = p1;
        this->player2 = p2;

        this->actualPlayer = p1;

        cout << "Gracz " << name1 << " zaczyna";
    }
    else {
        Player p1(name1, black);
        Player p2(name2, white);

        this->player1 = p1;
        this->player2 = p2;

        this->actualPlayer = p2;

        cout << "Gracz " << name2 << " zaczyna!";
    }

    
}

void Game::move() {

    char actual_position_column_char;
    string actual_position_column;
    string actual_position_row;

    int position_column_check;
    int position_row_check;

    string move_position;
    bool right_field = false;

    
    
    while (right_field == false) {
        cout << "Wybierz pole z pionkiem, którym chcesz ruszyc " << this->actualPlayer.getName() << endl;
        cout << "Kolumna: ";
        cin >> actual_position_column_char;
        cout << "" << endl;
        cout << "Rzad: ";
        cin >> actual_position_row;
        cout << "" << endl;

        actual_position_column = toupper(actual_position_column_char);


        if (actual_position_column == "A") {        

            position_column_check = 0;
            right_field = true;
        }
        else if (actual_position_column == "B") {   

            position_column_check = 1;
            right_field = true;
        }
        else if (actual_position_column == "C") {   

            position_column_check = 2;
            right_field = true;
        }
        else if (actual_position_column == "D") {   

            position_column_check = 3;
            right_field = true;
        }
        else if (actual_position_column == "E") {   

            position_column_check = 4;
            right_field = true;
	}
        else if (actual_position_column == "F") {   

            position_column_check = 5;
            right_field = true;
        }
        else if (actual_position_column == "G") {   

            position_column_check = 6;
            right_field = true;
        }
        else if (actual_position_column == "H") {   

            position_column_check = 7;
            right_field = true;
        }
        else {
            cout << "Wpisz poprawne pole" << endl;
            right_field = false;
            continue;
        }
        

        if (actual_position_row == "1") {        

            position_row_check = 0;
            right_field = true;
        }
        else if (actual_position_row == "2") {   

            position_row_check = 1;
            right_field = true;
        }
        else if (actual_position_row == "3") {   

            position_row_check = 2;
            right_field = true;
        }
        else if (actual_position_row == "4") {   

            position_row_check = 3;
            right_field = true;
        }
        else if (actual_position_row == "5") {   

            position_row_check = 4;
            right_field = true;
        }
        else if (actual_position_row == "6") {   

            position_row_check = 5;
            right_field = true;
        }
        else if (actual_position_row == "7") {   

            position_row_check = 6;
            right_field = true;
        }
        else if (actual_position_row == "8") {   

            position_row_check = 7;
            right_field = true;
        }
        else {
            cout << "Wpisz poprawne pole" << endl;
            right_field = false;
            continue;
        }
        

        if (this->actualPlayer.getColor() == white) {

           if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_white) {

               cout << "Rusz sie bialym pionkiem";
           }
           else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_white_king) {

               cout << "Rusz sie bialym hetmanem";

           }
           else {
            	cout << "Wpisz poprawne pole" << endl;
               right_field = false;
           }

        }
        else {

            if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_black) {

                cout << "Rusz sie czarnym pionkiem";
            }
            else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_black_king) {

                cout << "Rusz sie czarnym hetmanem";
            }
            else {
            	cout << "Wpisz poprawne pole" << endl;
                right_field = false;
            }

        }

    }

    
    if (this->actualPlayer.getName() == this->player1.getName()) {

        this->actualPlayer = player2;
    }
    else
    {
        this->actualPlayer = player1;
    }
}

bool Game::gameEnd() {
	return false;
}
