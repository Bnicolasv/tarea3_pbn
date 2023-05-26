#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "personaje.h"
#include <vector>

int main() {
    std::ifstream archivo("soldados_short.txt");

    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    std::getline(archivo, linea);

    std::stringstream dimensiones(linea);
    int ancho, alto;
    dimensiones >> ancho >> alto;

    std::getline(archivo, linea);
    std::stringstream soldados1(linea);
    int cantidad_de_soldados1;
    soldados1 >> cantidad_de_soldados1;

    std::vector<Personaje> soldados_equipo1;

    for (int i = 0; i < cantidad_de_soldados1; ++i) {
        std::getline(archivo, linea);
        std::stringstream soldado1(linea);
        std::string nombre;
        int vida, ataque, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        std::getline(soldado1, nombre, ',');
        soldado1 >> vida;
        soldado1.ignore(); // Ignoramos la coma
        soldado1 >> ataque;
        soldado1.ignore();
        soldado1 >> velocidad;
        soldado1.ignore();
        soldado1 >> pos_x;
        soldado1.ignore();
        soldado1 >> pos_y;

        Posicion p = Posicion(pos_x, pos_y);
        soldados_equipo1.emplace_back(nombre, vida, ataque, velocidad, p);
    }

    std::getline(archivo, linea);
    std::stringstream soldados2(linea);
    int cantidad_de_soldados2;
    soldados2 >> cantidad_de_soldados2;

    std::vector<Personaje> soldados_equipo2;

    for (int i = 0; i < cantidad_de_soldados2; ++i) {
        std::getline(archivo, linea);
        std::stringstream soldado2(linea);
        std::string nombre;
        int vida, ataque, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        std::getline(soldado2, nombre, ',');
        soldado2 >> vida;
        soldado2.ignore(); // Ignoramos la coma
        soldado2 >> ataque;
        soldado2.ignore();
        soldado2 >> velocidad;
        soldado2.ignore();
        soldado2 >> pos_x;
        soldado2.ignore();
        soldado2 >> pos_y;

        Posicion p = Posicion(pos_x, pos_y);
        soldados_equipo2.emplace_back(nombre, vida, ataque, velocidad, p);
    }

    archivo.close();

    std::cout << "Soldados del equipo 1:" << std::endl;
    for (const auto& Personaje : soldados_equipo1) {
        std::cout << "Nombre: " << Personaje.getNombre() << std::endl;
        std::cout << "Vida: " << Personaje.getVida() << std::endl;
        std::cout << "Ataque: " << Personaje.getFuerza() << std::endl;
        std::cout << "Velocidad: " << Personaje.getVelocidad() << std::endl;
        std::cout << "Posicion: " << Personaje.getPosicion().getX() << "," << Personaje.getPosicion().getY() << std::endl;
        std::cout << std::endl;
    }

    // Imprimir soldados_equipo2
    std::cout << "Soldados del equipo 2:" << std::endl;
    for (const auto& Personaje : soldados_equipo2) {
        std::cout << "Nombre: " << Personaje.getNombre() << std::endl;
        std::cout << "Vida: " << Personaje.getVida() << std::endl;
        std::cout << "Ataque: " << Personaje.getFuerza() << std::endl;
        std::cout << "Velocidad: " << Personaje.getVelocidad() << std::endl;
        std::cout << "Posicion: " << Personaje.getPosicion().getX() << "," << Personaje.getPosicion().getY() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}

