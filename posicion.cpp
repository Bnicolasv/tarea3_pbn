#include <iostream>
#include <string>
#include "posicion.h"

Posicion::Posicion(int x, int y) {
    this -> x = x;
    this -> y = y;
}

Posicion::~Posicion() {}

// Getter
int Posicion::getX() {
    return x;
}

// Getter
int Posicion::getY() {
    return y;
}

// Setter
void Posicion::set(int x, int y) {
    this -> x = x;
    this -> y = y;
}