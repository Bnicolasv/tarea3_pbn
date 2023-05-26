#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "personaje.h"
#include <vector>

using namespace std;

int main() {
    ifstream archivo("soldados_short.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    string linea;
    getline(archivo, linea);

    stringstream dimensiones(linea);
    string ancho_str, alto_str;
    getline(dimensiones, ancho_str, ',');
    getline(dimensiones, alto_str, ',');
    int ancho = stoi(ancho_str);
    int alto = stoi(alto_str);

    getline(archivo, linea);
    stringstream soldados1(linea);
    int cantidad_de_soldados1;
    soldados1 >> cantidad_de_soldados1;

    vector<Personaje> soldados_equipo1;

    for (int i = 0; i < cantidad_de_soldados1; ++i) {
        getline(archivo, linea);
        stringstream soldado1(linea);
        string nombre;
        int vida, ataque, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        getline(soldado1, nombre, ',');
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

    getline(archivo, linea);
    stringstream soldados2(linea);
    int cantidad_de_soldados2;
    soldados2 >> cantidad_de_soldados2;

    vector<Personaje> soldados_equipo2;

    for (int i = 0; i < cantidad_de_soldados2; ++i) {
        getline(archivo, linea);
        stringstream soldado2(linea);
        string nombre;
        int vida, ataque, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        getline(soldado2, nombre, ',');
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

    cout << "Soldados del equipo 1:" << endl;
    for (const auto& Personaje : soldados_equipo1) {
        cout << "Nombre: " << Personaje.getNombre() << endl;
        cout << "Vida: " << Personaje.getVida() << endl;
        cout << "Ataque: " << Personaje.getFuerza() << endl;
        cout << "Velocidad: " << Personaje.getVelocidad() << endl;
        cout << "Posicion: " << Personaje.getPosicion().getX() << "," << Personaje.getPosicion().getY() << endl;
        cout << endl;
    }

    // Imprimir soldados_equipo2
    cout << "Soldados del equipo 2:" << endl;
    for (const auto& Personaje : soldados_equipo2) {
        cout << "Nombre: " << Personaje.getNombre() << endl;
        cout << "Vida: " << Personaje.getVida() << endl;
        cout << "Ataque: " << Personaje.getFuerza() << endl;
        cout << "Velocidad: " << Personaje.getVelocidad() << endl;
        cout << "Posicion: " << Personaje.getPosicion().getX() << "," << Personaje.getPosicion().getY() << endl;
        cout << endl;
    }
    return 0;
}

