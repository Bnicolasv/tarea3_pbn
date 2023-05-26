#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "personaje.h"
#include <vector>


int main () {

    std::ifstream archivo("archivo.txt"); // Nombre del archivo a leer

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
        soldado1 >> nombre >> vida >> ataque >> velocidad >> pos_x >> pos_y;
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
        soldado2 >> nombre >> vida >> ataque >> velocidad >> pos_x >> pos_y;
        Posicion p = Posicion(pos_x, pos_y);
        soldados_equipo2.emplace_back(nombre, vida, ataque, velocidad, p);
    }

    archivo.close();

    return 0;
}

