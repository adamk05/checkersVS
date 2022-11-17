#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Color.h"
#include "Field.h"
#include "FieldState.h"
#include "cstdlib"
#include "iostream"
#include "time.h"
#include <map>
#include <vector>
using namespace std;

Game::Game() {
    string name1;
    string name2;

    Board board;
    this->board = board;

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

        cout << "Gracz " << name1 << " zaczyna!" << endl;
    }
    else {
        Player p1(name1, black);
        Player p2(name2, white);

        this->player1 = p1;
        this->player2 = p2;

        this->actualPlayer = p2;

        cout << "Gracz " << name2 << " zaczyna!" << endl;
    }
}

bool Game::move() {
    char actual_position_column_char;
    string actual_position_column;
    string actual_position_row;

    int position_column_check;
    int position_row_check;

    string move_position;
    int options = 0;
    map<int, vector<Field*>> optionsMap;

    this->board.drawBoard();
    cout << "Wybierz pole z pionkiem, ktorym chcesz ruszyc " << this->actualPlayer.getName() << endl;
    cout << "Kolumna: ";
    cin >> actual_position_column_char;
    cout << "" << endl;
    cout << "Rzad: ";
    cin >> actual_position_row;
    cout << "" << endl;

    actual_position_column = toupper(actual_position_column_char);



    if (actual_position_column == "A") {
        position_column_check = 0;
    }
    else if (actual_position_column == "B") {
        position_column_check = 1;
    }
    else if (actual_position_column == "C") {
        position_column_check = 2;
    }
    else if (actual_position_column == "D") {
        position_column_check = 3;
    }
    else if (actual_position_column == "E") {
        position_column_check = 4;
    }
    else if (actual_position_column == "F") {
        position_column_check = 5;
    }
    else if (actual_position_column == "G") {
        position_column_check = 6;
    }
    else if (actual_position_column == "H") {
        position_column_check = 7;
    }
    else {
        cout << "Wpisz poprawne pole" << endl;
        return false;
    }

    if (actual_position_row == "1") {
        position_row_check = 0;
    }
    else if (actual_position_row == "2") {
        position_row_check = 1;
    }
    else if (actual_position_row == "3") {
        position_row_check = 2;
    }
    else if (actual_position_row == "4") {
        position_row_check = 3;
    }
    else if (actual_position_row == "5") {
        position_row_check = 4;
    }
    else if (actual_position_row == "6") {
        position_row_check = 5;
    }
    else if (actual_position_row == "7") {
        position_row_check = 6;
    }
    else if (actual_position_row == "8") {
        position_row_check = 7;
    }
    else {
        cout << "Wpisz poprawne pole" << endl;
        return false;
    }   
        if (this->actualPlayer.getColor() == white) {

           if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_white) {

               cout << "Wybierz, który ruch chcesz wykonaæ" << endl;

               if (position_column_check < 7 && board.getField(position_row_check + 1, position_column_check + 1)->fieldState == FieldState::field_empty) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 1, position_column_check + 1), nullptr };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Prawy skos " << board.rows[position_row_check + 1] << board.columns[position_column_check + 1] << endl;
               }

               if (position_column_check > 0 && board.getField(position_row_check + 1, position_column_check - 1)->fieldState == FieldState::field_empty) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 1, position_column_check - 1), nullptr };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Lewy skos " << board.rows[position_row_check + 1] << board.columns[position_column_check - 1] << endl;
               }

               if ((position_column_check < 7 && board.getField(position_row_check + 1, position_column_check + 1)->fieldState == FieldState::field_black)
                   && (position_column_check < 6 && board.getField(position_row_check + 2, position_column_check + 2)->fieldState == FieldState::field_empty)) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 2, position_column_check + 2), board.getField(position_row_check + 1, position_column_check + 1) };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Bicie pionka z " << board.rows[position_row_check + 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check + 2] << board.columns[position_column_check + 2] << endl;
               }
               
               if ((position_column_check > 0 && board.getField(position_row_check + 1, position_column_check - 1)->fieldState == FieldState::field_black)
                   && (position_column_check > 1 && board.getField(position_row_check + 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 2, position_column_check - 2), board.getField(position_row_check + 1, position_column_check - 1) };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Bicie pionka z " << board.rows[position_row_check + 1] << board.columns[position_column_check - 1] << " na " << board.rows[position_row_check + 2] << board.columns[position_column_check - 2] << endl;
               }

               if ((position_column_check < 7 && board.getField(position_row_check + 1, position_column_check + 1)->fieldState == FieldState::field_black_king)
                   && (position_column_check < 6 && board.getField(position_row_check + 2, position_column_check + 2)->fieldState == FieldState::field_empty)) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 2, position_column_check + 2), board.getField(position_row_check + 1, position_column_check + 1) };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Bicie hetmana z " << board.rows[position_row_check + 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check + 2] << board.columns[position_column_check + 2] << endl;
               }

               if ((position_column_check > 0 && board.getField(position_row_check + 1, position_column_check - 1)->fieldState == FieldState::field_black_king)
                   && (position_column_check > 1 && board.getField(position_row_check + 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 2, position_column_check - 2), board.getField(position_row_check + 1, position_column_check - 1) };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Bicie hetmana z " << board.rows[position_row_check + 1] << board.columns[position_column_check - 1] << " na " << board.rows[position_row_check + 2] << board.columns[position_column_check - 2] << endl;
               }

               if(options == 0) {
                   cout << "Nie mozesz sie ruszyc tym pionkiem, wybierz innego"<<endl;
                   return false;
               } 
               else {
                   int userOption = 0;
                   while (userOption < 1 || userOption > options) {
                       cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                       cin >> userOption;
                   }
                   Field* finalField = optionsMap.find(userOption)->second.at(0);
                   Field* beatenField = optionsMap.find(userOption)->second.at(1);
                   if (beatenField != nullptr) {
                       beatenField->fieldState = FieldState::field_empty;
                   }
                   board.getField(position_row_check, position_column_check)->fieldState = FieldState::field_empty;
                   finalField->fieldState = FieldState::field_white;
               }
           }
           else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_white_king) {
                cout << "Rusz sie bialym hetmanem";
           }
           else {
                cout << "Wpisz poprawne pole" << endl;
                return false;
           }

        }
        else {
            if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_black) {
                if (position_column_check < 7 && board.getField(position_row_check - 1, position_column_check + 1)->fieldState == FieldState::field_empty) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check + 1), nullptr };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Prawy skos" << board.rows[position_row_check - 1] << board.columns[position_column_check + 1] << endl;
                }

                if (position_column_check > 0 && board.getField(position_row_check - 1, position_column_check - 1)->fieldState == FieldState::field_empty) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check - 1), nullptr };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Lewy skos" << board.rows[position_row_check - 1] << board.columns[position_column_check - 1] << endl;
                }

                if ((position_column_check < 7 && board.getField(position_row_check - 1, position_column_check + 1)->fieldState == FieldState::field_white)
                    && (position_column_check < 6 && board.getField(position_row_check - 2, position_column_check + 2)->fieldState == FieldState::field_empty)) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check + 1), board.getField(position_row_check - 2, position_column_check + 2) };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Bicie pionka z " << board.rows[position_row_check - 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check - 2] << board.columns[position_column_check + 2] << endl;
                }

                if ((position_column_check > 0 && board.getField(position_row_check - 1, position_column_check - 1)->fieldState == FieldState::field_white)
                    && (position_column_check > 1 && board.getField(position_row_check - 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check - 1), board.getField(position_row_check - 2, position_column_check + 2) };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Bicie pionka z " << board.rows[position_row_check - 1] << board.columns[position_column_check - 1] << " na " << board.rows[position_row_check - 2] << board.columns[position_column_check - 2] << endl;
                }

                if ((position_column_check < 7 && board.getField(position_row_check - 1, position_column_check + 1)->fieldState == FieldState::field_black_king)
                    && (position_column_check < 6 && board.getField(position_row_check - 2, position_column_check + 2)->fieldState == FieldState::field_empty)) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check + 1), board.getField(position_row_check - 2, position_column_check + 2) };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Bicie hetmana z " << board.rows[position_row_check - 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check - 2] << board.columns[position_column_check + 2] << endl;
                }

                if ((position_column_check > 0 && board.getField(position_row_check - 1, position_column_check - 1)->fieldState == FieldState::field_black_king)
                    && (position_column_check > 1 && board.getField(position_row_check - 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 1, position_column_check - 1), board.getField(position_row_check - 2, position_column_check - 2) };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Bicie hetmana z " << board.rows[position_row_check - 1] << board.columns[position_column_check - 1] << " na " << board.rows[position_row_check - 2] << board.columns[position_column_check - 2] << endl;
                }

                if(options == 0) {
                    cout << "Nie mozesz sie ruszyc tym pionkiem, wybierz innego" << endl;
                    return false;
                }
                else {
                    int userOption = 0;
                    while (userOption < 1 || userOption > options) {
                        cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                        cin >> userOption;
                    }
                    Field* finalField = optionsMap.find(userOption)->second.at(0);
                    Field* beatenField = optionsMap.find(userOption)->second.at(1);
                    if (beatenField != nullptr) {
                        beatenField->fieldState = FieldState::field_empty;
                    }
                    board.getField(position_row_check, position_column_check)->fieldState = FieldState::field_empty;
                    finalField->fieldState = FieldState::field_black;
                }
            }
            else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_black_king) {
                cout << "Rusz sie czarnym hetmanem"<<endl;
            }
            else {
            	cout << "Wpisz poprawne pole" << endl;
                return false;
            }
        }
    


    if (this->actualPlayer.getName() == this->player1.getName()) {
        this->actualPlayer = player2;
    }
    else
    {
        this->actualPlayer = player1;
    }
    return true;
}

bool Game::gameEnd() {
    return false;
}
