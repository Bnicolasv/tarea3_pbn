#include <iostream>
#include <string>
#include "personaje.h"
#include "mapa.h"


Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
}


Mapa::~Mapa() {
}


int Mapa::casillaCentralX() {
    return ancho / 2;
}


int Mapa::casillaCentralY() {
    return alto / 2;
} 


void Mapa::crearMapa(int ancho, int alto) {

}

void Mapa::agregarPersonaje(Personaje* personaje) {

}

void Mapa::eliminarPersonaje(Personaje* personaje) {

}