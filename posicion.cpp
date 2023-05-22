#include <iostream>
#include <string>
#include "posicion.h"

Posicion::Posicion(int x, int y){
    this->x = x;
    this->y = y;
}

Posicion::~Posicion(){}

int Posicion::getX(){
    std::cout <<  x << std::endl;
}

int Posicion::getY(){
    std::cout <<  y << std::endl;
}

void Posicion::set(int x, int y){

}