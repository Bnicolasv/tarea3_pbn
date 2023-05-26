#include <iostream>
#include <string>
#include "posicion.h"

Posicion::Posicion(int x, int y) {
    this -> x = x;
    this -> y = y;
}

Posicion::~Posicion() {}

// Getter
int Posicion::getX() const{
    return x;
}

// Getter
int Posicion::getY() const{
    return y;
}

// Setter
void Posicion::set(int x, int y) {
    this -> x = x;
    this -> y = y;
}