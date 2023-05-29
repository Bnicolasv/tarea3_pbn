#include <iostream>
#include <string>
#include "personaje.h"


Personaje::Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos, int ejercito) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> fuerza = fuerza;
    this -> velocidad = velocidad;
    this -> pos = &pos;
    this -> ejercito = ejercito;
}

Personaje::Personaje() {}

Personaje::~Personaje() {}

std::string Personaje::getNombre() const{
    return nombre;
}
int Personaje::getVida() const{
    return vida;
}

int Personaje::ataque() const{
    return fuerza;
}

int Personaje::getVelocidad() const{
    return velocidad;
}

Posicion Personaje::getPosicion() const{
    return *pos;
}

int Personaje::getEjercito() const {
    return ejercito;
}

void Personaje::recibirAtaque(Personaje* enemigo) {
    vida -= enemigo -> ataque();
}


Posicion Personaje::moverse() {

    






}
