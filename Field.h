#pragma once
#include "FieldState.h"

class Field {
private:
    int x;
    int y;
public:
    FieldState fieldState;

    Field();
    Field(int x, int y);

    int getX();
    int getY();
};