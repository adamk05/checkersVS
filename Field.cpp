#include "Field.h"
#include <iostream>

Field::Field() {}

Field::Field(int x, int y) {
    this->x = x;
    this->y = y;
}

int Field::getX() {
    return this->x;
}

int Field::getY() {
    return this->y;
}
