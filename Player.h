#pragma once
#include <iostream>
#include "Color.h"

class Player {
private:
    std::string name;
    Color color;
public:
    Player();
    Player(std::string name, Color color);

    std::string getName();
    Color getColor();

};