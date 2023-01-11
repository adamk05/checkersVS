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

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
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
                   && (position_column_check < 6 && board.getField(position_row_check + 2, position_column_check + 2) != nullptr && board.getField(position_row_check + 2, position_column_check + 2)->fieldState == FieldState::field_empty)) {
                   options++;
                   vector<Field*> optionsArray = { board.getField(position_row_check + 2, position_column_check + 2), board.getField(position_row_check + 1, position_column_check + 1) };
                   optionsMap[options] = optionsArray;
                   cout << options << ". Bicie pionka z " << board.rows[position_row_check + 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check + 2] << board.columns[position_column_check + 2] << endl;
               }
               
               if ((position_column_check > 0 && board.getField(position_row_check + 1, position_column_check - 1)->fieldState == FieldState::field_black)
                   && (position_column_check > 1 && board.getField(position_row_check + 2, position_column_check - 2) != nullptr && board.getField(position_row_check + 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
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
                   string userOption = "0";
                   while (stoi(userOption) < 1 || stoi(userOption) > options) {
                       cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                       cin >> userOption;
                       while (!check_number(userOption)) {
                           cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                           cin >> userOption;
                       }
                   }
                   Field* finalField = optionsMap.find(stoi(userOption))->second.at(0);
                   Field* beatenField = optionsMap.find(stoi(userOption))->second.at(1);
                   if (beatenField != nullptr) {
                       beatenField->fieldState = FieldState::field_empty;
                   }
                   board.getField(position_row_check, position_column_check)->fieldState = FieldState::field_empty;
                   if (finalField->getX() == 7) {
                       finalField->fieldState = field_white_king;
                   }
                   else {
                       finalField->fieldState = FieldState::field_white;
                   }
               }
           }
           else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_white_king) {
               //ruch hetmanem
               int hetmanOptions = 0;
               map<int, vector<Field*>> hetmanOptionsMap;
               if (position_column_check != 7 && position_row_check != 0) { //przek¹tna prawo-góra
                   bool canMove = true;
                   int hetmanColumn = position_column_check;
                   int hetmanRow = position_row_check;
                   while (canMove) {
                       hetmanColumn++;
                       hetmanRow--;
                       if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow - 1, hetmanColumn + 1)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow - 1, hetmanColumn + 1), this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black) {
                           canMove = false;
                       }
                       else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                           canMove = false;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow - 1, hetmanColumn + 1)->fieldState != FieldState::field_empty) {
                           canMove = false;
                       }
                   }
               }
               if (position_column_check != 0 && position_row_check != 0) { //przek¹tna lewo-góra
                   bool canMove = true;
                   int hetmanColumn = position_column_check;
                   int hetmanRow = position_row_check;
                   while (canMove) {
                       hetmanColumn++;
                       hetmanRow--;
                       if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow - 1, hetmanColumn - 1)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow - 1, hetmanColumn - 1), this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black) {
                           canMove = false;
                       }
                       else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                           canMove = false;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow - 1, hetmanColumn - 1)->fieldState != FieldState::field_empty) {
                           canMove = false;
                       }
                   }
               }
               if (position_column_check != 7 && position_row_check != 7) { //przek¹tna prawo-dó³
                   bool canMove = true;
                   int hetmanColumn = position_column_check;
                   int hetmanRow = position_row_check;
                   while (canMove) {
                       hetmanColumn++;
                       hetmanRow--;
                       if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow + 1, hetmanColumn + 1)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow + 1, hetmanColumn + 1), this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black) {
                           canMove = false;
                       }
                       else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                           canMove = false;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow + 1, hetmanColumn + 1)->fieldState != FieldState::field_empty) {
                           canMove = false;
                       }
                   }
               }
               if (position_column_check != 0 && position_row_check != 7) { //przek¹tna lewo-dó³
                   bool canMove = true;
                   int hetmanColumn = position_column_check;
                   int hetmanRow = position_row_check;
                   while (canMove) {
                       hetmanColumn++;
                       hetmanRow--;
                       if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow + 1, hetmanColumn - 1)->fieldState == FieldState::field_empty) {
                           hetmanOptions++;
                           vector<Field*> option = { this->board.getField(hetmanRow + 1, hetmanColumn - 1), this->board.getField(hetmanRow, hetmanColumn) };
                           hetmanOptionsMap[hetmanOptions] = option;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black) {
                           canMove = false;
                       }
                       else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                           canMove = false;
                       }
                       else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_black_king && this->board.getField(hetmanRow + 1, hetmanColumn - 1)->fieldState != FieldState::field_empty) {
                           canMove = false;
                       }
                   }
               }
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
                    vector<Field*> optionsArray = { board.getField(position_row_check - 2, position_column_check + 2), board.getField(position_row_check - 1, position_column_check + 1) };
                    optionsMap[options] = optionsArray;
                    cout << options << ". Bicie pionka z " << board.rows[position_row_check - 1] << board.columns[position_column_check + 1] << " na " << board.rows[position_row_check - 2] << board.columns[position_column_check + 2] << endl;
                }

                if ((position_column_check > 0 && board.getField(position_row_check - 1, position_column_check - 1)->fieldState == FieldState::field_white)
                    && (position_column_check > 1 && board.getField(position_row_check - 2, position_column_check - 2)->fieldState == FieldState::field_empty)) {
                    options++;
                    vector<Field*> optionsArray = { board.getField(position_row_check - 2, position_column_check - 2), board.getField(position_row_check - 1, position_column_check - 1) };
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

                if (options == 0) {
                    cout << "Nie mozesz sie ruszyc tym pionkiem, wybierz innego" << endl;
                    return false;
                }
                else {
                    //tu jest wybór ruchu pionka
                    string userOption = "0";
                    while (stoi(userOption) < 1 || stoi(userOption) > options) {
                        cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                        cin >> userOption;
                        while (!check_number(userOption)) {
                            cout << "Wybierz ruch (wpisz numer ruchu, który wybierasz) " << endl;
                            cin >> userOption;
                        }
                    }
                    Field* finalField = optionsMap.find(stoi(userOption))->second.at(0);
                    Field* beatenField = optionsMap.find(stoi(userOption))->second.at(1);
                    if (beatenField != nullptr) {
                        beatenField->fieldState = FieldState::field_empty;
                    }
                    board.getField(position_row_check, position_column_check)->fieldState = FieldState::field_empty;
                    if (finalField->getX() == 0) {
                        finalField->fieldState = FieldState::field_black_king;
                    }
                    else {
                        finalField->fieldState = FieldState::field_black;
                    }
                }
            }
            else if (board.getField(position_row_check, position_column_check)->fieldState == FieldState::field_black_king) {
                //ruch hetmanem
                int hetmanOptions = 0;
                map<int, vector<Field*>> hetmanOptionsMap;
                if (position_column_check != 7 && position_row_check != 0) { //przek¹tna prawo-góra
                    bool canMove = true;
                    int hetmanColumn = position_column_check;
                    int hetmanRow = position_row_check;
                    while (canMove) {
                        hetmanColumn++;
                        hetmanRow--;
                        if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow - 1, hetmanColumn + 1)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow - 1, hetmanColumn + 1), this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white) {
                            canMove = false;
                        }
                        else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                            canMove = false;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow - 1, hetmanColumn + 1)->fieldState != FieldState::field_empty) {
                            canMove = false;
                        }
                    }
                }
                if (position_column_check != 0 && position_row_check != 0) { //przek¹tna lewo-góra
                    bool canMove = true;
                    int hetmanColumn = position_column_check;
                    int hetmanRow = position_row_check;
                    while (canMove) {
                        hetmanColumn++;
                        hetmanRow--;
                        if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow - 1, hetmanColumn - 1)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow - 1, hetmanColumn - 1), this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white) {
                            canMove = false;
                        }
                        else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                            canMove = false;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow - 1, hetmanColumn - 1)->fieldState != FieldState::field_empty) {
                            canMove = false;
                        }
                    }
                }
                if (position_column_check != 7 && position_row_check != 7) { //przek¹tna prawo-dó³
                    bool canMove = true;
                    int hetmanColumn = position_column_check;
                    int hetmanRow = position_row_check;
                    while (canMove) {
                        hetmanColumn++;
                        hetmanRow--;
                        if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow + 1, hetmanColumn + 1)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow + 1, hetmanColumn + 1), this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white) {
                            canMove = false;
                        }
                        else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                            canMove = false;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow + 1, hetmanColumn + 1)->fieldState != FieldState::field_empty) {
                            canMove = false;
                        }
                    }
                }
                if (position_column_check != 0 && position_row_check != 7) { //przek¹tna lewo-dó³
                    bool canMove = true;
                    int hetmanColumn = position_column_check;
                    int hetmanRow = position_row_check;
                    while (canMove) {
                        hetmanColumn++;
                        hetmanRow--;
                        if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow + 1, hetmanColumn - 1)->fieldState == FieldState::field_empty) {
                            hetmanOptions++;
                            vector<Field*> option = { this->board.getField(hetmanRow + 1, hetmanColumn - 1), this->board.getField(hetmanRow, hetmanColumn) };
                            hetmanOptionsMap[hetmanOptions] = option;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white) {
                            canMove = false;
                        }
                        else if (hetmanColumn == 0 || hetmanColumn == 7 || hetmanRow == 0 || hetmanRow == 7) { //to siê nie zmienia dla inncyh przk¹tncyh
                            canMove = false;
                        }
                        else if (this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white || this->board.getField(hetmanRow, hetmanColumn)->fieldState == FieldState::field_white_king && this->board.getField(hetmanRow + 1, hetmanColumn - 1)->fieldState != FieldState::field_empty) {
                            canMove = false;
                        }
                    }
                }
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

bool Game::move(int x, int y) {
    FieldState color = this->board.board[x][y].fieldState;
    if (color == FieldState::field_white) {
            if (y < 7 && board.getField(x + 1, y + 1)->fieldState == FieldState::field_empty) {
                return true;
            }

            if (y > 0 && board.getField(x + 1, y - 1)->fieldState == FieldState::field_empty) {
                return true;
            }

            if ((y < 7 && board.getField(x + 1, y + 1)->fieldState == FieldState::field_black)
                && (y < 6 && board.getField(x + 2, y + 2) != nullptr && board.getField(x + 2, y + 2)->fieldState == FieldState::field_empty)) {
                return true;
            }

            if ((y > 0 && board.getField(x + 1, y - 1)->fieldState == FieldState::field_black)
                && (y > 1 && board.getField(x + 2, y - 2) != nullptr && board.getField(x + 2, y - 2)->fieldState == FieldState::field_empty)) {
                return true;
            }

            if ((y < 7 && board.getField(x + 1, y + 1)->fieldState == FieldState::field_black_king)
                && (y < 6 && board.getField(x + 2, y + 2)->fieldState == FieldState::field_empty)) {
                return true;
            }

            if ((y > 0 && board.getField(x + 1, y - 1)->fieldState == FieldState::field_black_king)
                && (y > 1 && board.getField(x + 2, y - 2)->fieldState == FieldState::field_empty)) {
                return true;
            }
        
        return false;
    }
    else if (color == FieldState::field_black) {
        if (y < 7 && board.getField(x - 1, y + 1)->fieldState == FieldState::field_empty) {
            return true;
        }

        if (y > 0 && board.getField(x - 1, y - 1)->fieldState == FieldState::field_empty) {
            return true;
        }

        if ((y < 7 && board.getField(x - 1, y + 1)->fieldState == FieldState::field_white)
            && (y < 6 && board.getField(x - 2, y + 2)->fieldState == FieldState::field_empty)) {
            return true;
        }

        if ((y > 0 && board.getField(x - 1, y - 1)->fieldState == FieldState::field_white)
            && (y > 1 && board.getField(x - 2, y - 2)->fieldState == FieldState::field_empty)) {
            return true;
        }

        if ((y < 7 && board.getField(x - 1, y + 1)->fieldState == FieldState::field_black_king)
            && (y < 6 && board.getField(x - 2, y + 2)->fieldState == FieldState::field_empty)) {
            return true;
        }

        if ((y > 0 && board.getField(x - 1, y - 1)->fieldState == FieldState::field_black_king)
            && (y > 1 && board.getField(x - 2, y - 2)->fieldState == FieldState::field_empty)) {
            return true;
        }
        return false;
    }
    else {
        return false;
    }

}

bool Game::gameEnd() {

    bool any_white=false;
    bool any_black=false;

    for (int i = 0; i < 8;i++) {
        for (int j = 0; j < 8; j++) {

            if (board.getField(i, j)->fieldState == FieldState::field_white || board.getField(i, j)->fieldState == FieldState::field_white_king) {
                any_white=true;
            }
            else if (board.getField(i, j)->fieldState == FieldState::field_black || board.getField(i, j)->fieldState == FieldState::field_black_king) {
                any_black=true;
            }

        }

    }

    bool any_moves_black=false;
    bool any_moves_white=false;

    for (int k = 0; k < 8;k++) {
        for (int l = 0; l < 8; l++) {
            //move(i, j) move(i,j)->options == 0
            if (this->board.getField(k, l)->fieldState == FieldState::field_white_king) { 
                any_moves_white = true;
                 
            }

            if (this->board.getField(k, l)->fieldState == FieldState::field_white) {
            if (this->move(k, l) == true) {
                any_moves_white = true;
                
            }
        }

            if (this->board.getField(k, l)->fieldState == FieldState::field_black_king) {
                any_moves_black = true;
                
            }

            if (this->board.getField(k, l)->fieldState == FieldState::field_black) {
                if (this->move(k, l) == true) {
                    any_moves_black = true;
                   
                }
            }
       }
    }

    if (any_black && any_white && any_moves_black && any_moves_white) {
        return false;
    }

    else {
        
        if (any_black == false) {
            if (this->player1.getColor() == Color::white)
                cout << player1.getName() << " wygral" << endl;
            else {
                cout << player2.getName() << " wygral" << endl;
            }

        }
        else if(any_white==false) {
            if (this->player1.getColor() == Color::black) {
                cout << player1.getName() << " wygral" << endl;
            }
            else {
                cout << player2.getName() << " wygral" << endl;
            }
        }
        else if (!any_moves_black || !any_moves_white) {
            cout << "remis" << endl;
        }

        return true;
    }
    
    return false;
}
