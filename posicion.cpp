#include <iostream>
#include <string>
#include "posicion.h"

Posicion::Posicion(int x, int y) {
    this -> x = x;
    this -> y = y;
}

Posicion::~Posicion() {}

int Posicion::getX() const{
    return x;
}

int Posicion::getY() const{
    return y;
}

void Posicion::set(int x, int y) {
    this -> x = x;
    this -> y = y;
}