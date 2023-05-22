#include <iostream>
#include <string>
#include "personaje.h"
#include "posicion.h"

Personaje::Personaje(std::string nombre, int vida, int ataque, int velocidad, Posicion pos){
    this->nombre = nombre;
    this->vida = vida;
    this->ataque = ataque;
    this->velocidad = velocidad;
    this->pos = pos;
}

Personaje::~Personaje(){

}

int Personaje::ataque(){

}

Posicion Personaje::moverse(){

}

void Personaje::recibirAtaque(){

}