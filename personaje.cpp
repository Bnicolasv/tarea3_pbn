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

// Tira error si es que la funcion se llama igual que el atributo ataque
int Personaje::ataque() {
    return fuerza;
}

Posicion Personaje::moverse() {
    // Escribir la logica que se especifica en el enunciado para moverse por el mapa
}

void Personaje::recibirAtaque(Personaje* enemigo) {
    this -> vida -= enemigo -> fuerza;

    // if (vida <= 0 ) {
        // llamar a destructor? o esto debe ser responsabilidad de juego.combate()
    // }
}