#include <iostream>
#include <string>
#include <iomanip>
#include "personaje.h"
#include "mapa.h"


Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
    casillas.resize(ancho, std::vector<Personaje*>(alto, nullptr));

    /* Inicializa una matriz de ancho x alto la cual contendra dentro punteros a objetos de la clase Personaje
    la inicializa vacia con nullptr, por ahora es de la forma: 
    casillas = [
        [nullptr, nullptr, nullptr, nullptr], 
        [nullptr, nullptr, nullptr, nullptr],
        [nullptr, nullptr, nullptr, nullptr],
        [nullptr, nullptr, nullptr, nullptr],
        ]
    */
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

    if (casillas[pos_x][pos_y] == nullptr) {
        casillas[pos_x][pos_y] = personaje;
        std::cout << "Se ha agregado " << personaje->getNombre() << " a la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    }
}

void Mapa::eliminarPersonaje(Personaje* personaje) {
    int pos_x = personaje->getPosicion().getX();
    int pos_y = personaje->getPosicion().getY();

    if (casillas[pos_x][pos_y] != nullptr) {
        casillas[pos_x][pos_y] = nullptr;
        std::cout << "Se ha eliminado " << personaje->getNombre() << " de la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    }
}

void Mapa::mostrarCasillas() {

    std::cout << "------------------------------------------------------" << std::endl;
    for (int i = 0; i < ancho; i++) {
        for (int j = 0; j < alto; j++) {
            if (casillas[i][j] != nullptr) {
                std::cout << casillas[i][j]->getNombre() << " esta en la posicion " << i << "," << j << std::endl;
            }
        }
    }

}