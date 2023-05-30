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
    int espacio = 5; 
    int anchoLinea = (espacio + 1) * ancho + 1; 

    std::cout << "+" << std::string(anchoLinea, '-') << "+" << std::endl;

    for (int y = 0; y < alto; y++) {
        std::cout << " |";
        for (int x = 0; x < ancho; x++) {
            if (casillas[x][y] == nullptr) {
                std::cout << std::setfill(' ') << std::setw(espacio) << " " << "|"; // Casilla vacía
            } else {
                std::cout << std::setfill(' ') << std::setw(espacio) << casillas[x][y]->getNombre() << "|"; // Casilla ocupada por un personaje
            }
        }
        std::cout << std::endl;

        std::cout << "+" << std::string(anchoLinea, '-') << "+" << std::endl;
    }
}
