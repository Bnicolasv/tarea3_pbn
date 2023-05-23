#include <iostream>
#include <string>
#include "personaje.h"
#include "posicion.h"

Personaje::Personaje(std::string nombre, int vida, int ataque, int velocidad, Posicion pos) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> ataque = ataque;
    this -> velocidad = velocidad;
    this -> pos = pos;
}

Personaje::~Personaje() {}

// Tira error si es que la funcion se llama igual que el atributo ataque
int Personaje::getAtaque() {
    return ataque;
}

Posicion Personaje::moverse() {
    // Escribir la logica que se especifica en el enunciado para moverse por el mapa
}

void Personaje::recibirAtaque(Personaje* enemigo) {
    this -> vida -= enemigo -> ataque;

    // if (vida <= 0 ) {
        // llamar a destructor? o esto debe ser responsabilidad de juego.combate()
    // }
}