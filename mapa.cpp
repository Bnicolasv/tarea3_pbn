#include <iostream>
#include <string>
#include <iomanip>
#include "personaje.h"
#include "mapa.h"


Mapa::Mapa(int ancho, int alto) {
    this -> ancho = ancho;
    this -> alto = alto;
    
    // Vectores investigados desde https://bitbucket.org/rdelpianoc/pbn/src/master/12%20herencia%20y%20polimorfismo/main.cpp
    // https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
    // https://levelup.gitconnected.com/learning-c-storing-class-objects-in-containers-ca12546f1a89
    // https://stackoverflow.com/questions/14444363/trying-to-store-objects-in-a-vector
    // https://www.scaler.com/topics/cpp-vector-resize/
    casillas.resize(alto, std::vector<Personaje*>(ancho, nullptr));
}


int Mapa::casillaCentralX() {   
    return ((ancho - 1) / 2);   // Como es impar siempre, se truncara y dara un resultado correcto al tratarse como int
}


int Mapa::casillaCentralY() {
    return ((alto - 1) / 2);    // Como es impar siempre, se truncara y dara un resultado correcto al tratarse como int
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
        personaje->~Personaje();
        int pos_x = personaje->getPosicion().getX();
        int pos_y = personaje->getPosicion().getY();

        casillas[pos_x][pos_y] = nullptr;
        std::cout << "Se ha eliminado " << personaje->getNombre() << personaje->getEjercito() << " en la posicion " << personaje->getPosicion().getX() << "," << personaje->getPosicion().getY() << std::endl;
    
}

// Inspirado de https://en.cppreference.com/w/cpp/io/manip
// https://es.stackoverflow.com/questions/146605/cual-es-el-prop%C3%B3sito-de-la-funcion-setw-de-la-biblioteca-iomanip-en-c
// https://es.stackoverflow.com/questions/60783/imprimir-bordes-de-una-matriz-c

void Mapa::mostrarCasillas() {
    for (int j = 0; j < ancho; j++) {
        std::cout << "------";
    }
    std::cout << std::endl;

    for (int i = 0; i < alto; i++) {
        for (int linea = 0; linea < 2; linea++) {
            for (int j = 0; j < ancho; j++) {
                std::cout << "|";
            
            
            
                if (casillas[i][j] != nullptr) {
                    std::string nombre = casillas[i][j]->getNombre();
                    int ejercito = casillas[i][j]->getEjercito();
                    int espacios_nombre = 5 - nombre.length();
                    int espacios_ejercito = 5 - std::to_string(ejercito).length();
                    int espacios_izq_nombre = espacios_nombre / 2;
                    int espacios_der_nombre = espacios_nombre - espacios_izq_nombre;
                    int espacios_izq_ejercito = espacios_ejercito / 2;
                    int espacios_der_ejercito = espacios_ejercito - espacios_izq_ejercito;

                    if (linea == 0) {
                        std::cout << std::setw(espacios_izq_nombre) << "" << nombre << std::setw(espacios_der_nombre) << "";
                    } 
                    
                    else if (linea == 1) {
                        std::cout << std::setw(espacios_izq_ejercito) << "" << ejercito << std::setw(espacios_der_ejercito) << "";
                    }
                } 
                
                else {
                    std::cout << std::setw(5) << "";
                }
            }
            std::cout << "|" << std::endl;
        }

        for (int j = 0; j < ancho; j++) {
            std::cout << "------";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<Personaje*> > Mapa::getCasillas() {
    return casillas;
}