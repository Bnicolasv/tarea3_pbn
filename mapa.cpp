#include <iostream>
#include <string>
#include <iomanip>
#include "personaje.h"
#include "mapa.h"


Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
    casillas.resize(ancho, std::vector<Personaje*>(alto, nullptr));
}

Mapa::~Mapa() {
}


int Mapa::casillaCentralX() {
    return ancho / 2;
}


int Mapa::casillaCentralY() {
    return alto / 2;
} 

void Mapa::agregarPersonaje(Personaje* personaje) {
    int pos_x = personaje->getPosicion().getX();
    int pos_y = personaje->getPosicion().getY();
    if (casillas[pos_y][pos_x] == nullptr) {
        casillas[pos_y][pos_x] = personaje;
        std::cout << "Se ha agregado " << personaje->getNombre() << " a la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    }
}

void Mapa::eliminarPersonaje(Personaje* personaje) {
    int pos_x = personaje->getPosicion().getX();
    int pos_y = personaje->getPosicion().getY();

    if (casillas[pos_y][pos_x] != nullptr) {
        casillas[pos_y][pos_x] = nullptr;
        std::cout << "Se ha eliminado " << personaje->getNombre() << " en la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    }
}

void Mapa::mostrarCasillas() {

    // CAMBIAR ESTO EN BASE AL ANCHO DEL TABLERO Y NO ALGO GENERICO
    // std::cout << "------------------------------------------------------" << std::endl;

    for (int j = 0; j < alto; j++) {
        for (int i = 0; i < ancho; i++) {
            if (casillas[i][j] != nullptr) {
                // POR AHORA ESTA SOLO CON LA PRIMERA LETRA DEL NOMBRE
                std::cout << "| " << casillas[i][j]->getNombre()[0] << " "; 
            } else {
                std::cout << "|  "; 
            }
        }
        std::cout << "|  " << std::endl;
    }
    
    // // CAMBIAR ESTO EN BASE AL ANCHO DEL TABLERO Y NO ALGO GENERICO
    std::cout << "------------------------------------------------------" << std::endl;
}

std::vector<std::vector<Personaje*>> Mapa::getCasillas() {
    return casillas;
}