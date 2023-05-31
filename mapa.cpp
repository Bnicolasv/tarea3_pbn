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


int Mapa::casillaCentralX() {
    return ancho / 2;
}


int Mapa::casillaCentralY() {
    return alto / 2;
} 

int Mapa::getAncho() {
    return ancho;
}

int Mapa::getAlto() {
    return alto;
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
    std::cout << " ";
    for (int i = 0; i < ancho; i++) {
        std::cout << "--------";
    }
    std::cout << std::endl;

    for (int j = 0; j < alto; j++) {
        for (int i = 0; i < ancho; i++) {
            std::cout << "| ";
            if (casillas[i][j] != nullptr) {
                std::string nombre = casillas[i][j]->getNombre();
                int espacios = 6 - nombre.length();
                int espacios_izq = espacios / 2;
                int espacios_der = espacios - espacios_izq;

                std::cout << std::setw(espacios_izq) << "" << nombre << std::setw(espacios_der) << " ";
            } else {
                std::cout << std::setw(6) << " ";
            }
        }
        std::cout << "|" << std::endl;

        std::cout << " ";
        for (int i = 0; i < ancho; i++) {
            std::cout << "--------";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<Personaje*>> Mapa::getCasillas() {
    return casillas;
}