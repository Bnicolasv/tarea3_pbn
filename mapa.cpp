#include <iostream>
#include <string>
#include <iomanip>
#include "personaje.h"
#include "mapa.h"


Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
    
    // Investigado desde https://levelup.gitconnected.com/learning-c-storing-class-objects-in-containers-ca12546f1a89
    // https://stackoverflow.com/questions/14444363/trying-to-store-objects-in-a-vector
    // https://www.scaler.com/topics/cpp-vector-resize/
    casillas.resize(alto, std::vector<Personaje*>(ancho, nullptr));
}


int Mapa::casillaCentralX() {   
    return ancho / 2;   // Como es impar siempre, se truncara y dara un resultado correcto al tratarse como int
}


int Mapa::casillaCentralY() {
    return alto / 2;    // Como es impar siempre, se truncara y dara un resultado correcto al tratarse como int
} 

int Mapa::getAncho() const{
    return ancho;
}

int Mapa::getAlto() const{
    return alto;
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
        std::cout << "Se ha eliminado " << personaje->getNombre() << " en la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    }
}

void Mapa::mostrarCasillas() {
    std::cout << " ";
    for (int i = 0; i < ancho; i++) {
        std::cout << "-----";
    }
    std::cout << std::endl;

    for (int j = 0; j < ancho; j++) {
        for (int i = 0; i < alto; i++) {
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
            std::cout << "-----";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<Personaje*> > Mapa::getCasillas() {
    return casillas;
}