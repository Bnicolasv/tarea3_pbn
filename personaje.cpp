#include <iostream>
#include <string>
#include "personaje.h"


Personaje::Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> fuerza = fuerza;
    this -> velocidad = velocidad;
    this -> pos = &pos;
}

Personaje::Personaje(){
    
}

Personaje::~Personaje() {}

//Getters

std::string Personaje::getNombre() const{
    return nombre;
}
int Personaje::getVida() const{
    return vida;
}

int Personaje::getFuerza() const{
    return fuerza;
}

int Personaje::getVelocidad() const{
    return velocidad;
}

Posicion Personaje::getPosicion() const{
    return *pos;
}




// int Personaje::ataque() {
//     return fuerza;
// }

// Posicion Personaje::moverse() {

// }

// void Personaje::recibirAtaque(Personaje* enemigo) {
//     this -> vida -= enemigo -> ataque();
// }