#include <iostream>
#include <string>
#include "personaje.h"
#include "posicion.h"

Personaje::Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> fuerza = fuerza;
    this -> velocidad = velocidad;
    this -> pos = &pos;
}

Personaje::~Personaje() {}

int Personaje::ataque() {
    return fuerza;
}

Posicion Personaje::moverse() {

}

void Personaje::recibirAtaque(Personaje* enemigo) {
    this -> vida -= enemigo -> ataque();
}