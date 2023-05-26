#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "personaje.h"

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

    Personaje *soldados_equipo1[cantidad_de_soldados1];

    cout << "SOLDADOS EQUIPO 1" << endl;
    for (int i = 0; i < cantidad_de_soldados1; ++i) {
        soldados_equipo1[i] = new Personaje();
        getline(archivo, linea);
        stringstream soldado1(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        getline(soldado1, nombre, ',');
        soldado1 >> vida;
        soldado1.ignore(); // Ignoramos la coma
        soldado1 >> fuerza;
        soldado1.ignore();
        soldado1 >> velocidad;
        soldado1.ignore();
        soldado1 >> pos_x;
        soldado1.ignore();
        soldado1 >> pos_y;

        Posicion p = Posicion(pos_x, pos_y);

        soldados_equipo1[i] = new Personaje(nombre, vida, fuerza, velocidad, p);

        cout << soldados_equipo1[i] -> getNombre() << " ";
        cout << soldados_equipo1[i] -> getVida() << " ";
        cout << soldados_equipo1[i] -> ataque() << " ";
        cout << soldados_equipo1[i] -> getVelocidad() << " ";
        cout << soldados_equipo1[i] -> getPosicion().getX() << " ";
        cout << soldados_equipo1[i] -> getPosicion().getY() << endl;
    }

    getline(archivo, linea);
    stringstream soldados2(linea);
    int cantidad_de_soldados2;
    soldados2 >> cantidad_de_soldados2;

    Personaje *soldados_equipo2[cantidad_de_soldados2];

    cout << "SOLDADOS EQUIPO 2" << endl;
    for (int i = 0; i < cantidad_de_soldados2; ++i) {
        soldados_equipo2[i] = new Personaje();
        getline(archivo, linea);
        stringstream soldado2(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        // Utilizamos getline con delimitador ',' en lugar de espacio
        getline(soldado2, nombre, ',');
        soldado2 >> vida;
        soldado2.ignore(); // Ignoramos la coma
        soldado2 >> fuerza;
        soldado2.ignore();
        soldado2 >> velocidad;
        soldado2.ignore();
        soldado2 >> pos_x;
        soldado2.ignore();
        soldado2 >> pos_y;

        Posicion p = Posicion(pos_x, pos_y);

        soldados_equipo2[i] = new Personaje(nombre, vida, fuerza, velocidad, p);
        
        cout << soldados_equipo2[i] -> getNombre() << " ";
        cout << soldados_equipo2[i] -> getVida() << " ";
        cout << soldados_equipo2[i] -> ataque() << " ";
        cout << soldados_equipo2[i] -> getVelocidad() << " ";
        cout << soldados_equipo2[i] -> getPosicion().getX() << " ";
        cout << soldados_equipo2[i] -> getPosicion().getY() << endl;
    }

    archivo.close();

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        delete soldados_equipo1[i];
    }

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        delete soldados_equipo2[i];
    }
    
    return 0;
}

