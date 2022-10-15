#include "Color.h"
#include "Player.h"
#include <iostream>

Player::Player(std::string name, Color color) {
    this->name = name;
    this->color = color;
}

std::string Player::getName() {
    return this->name;
}

Color Player::getColor() {
    return this->color;
}