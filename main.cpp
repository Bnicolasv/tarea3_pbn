#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include "personaje.h"
#include "mapa.h"
#include "juego.h"

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

    Personaje *soldados_ejercito1[cantidad_de_soldados1];

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        getline(archivo, linea);
        stringstream soldado1(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        getline(soldado1, nombre, ',');
        soldado1 >> vida;
        soldado1.ignore();
        soldado1 >> fuerza;
        soldado1.ignore();
        soldado1 >> velocidad;
        soldado1.ignore();
        soldado1 >> pos_x;
        soldado1.ignore();
        soldado1 >> pos_y;

        Posicion pos = Posicion(pos_x, pos_y);
        soldados_ejercito1[i] = new Personaje(nombre, vida, fuerza, velocidad, pos, 1);
    }

    getline(archivo, linea);
    stringstream soldados2(linea);
    int cantidad_de_soldados2;
    soldados2 >> cantidad_de_soldados2;

    Personaje *soldados_ejercito2[cantidad_de_soldados2];

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        getline(archivo, linea);
        stringstream soldado2(linea);
        string nombre;
        int vida, fuerza, velocidad, pos_x, pos_y;

        getline(soldado2, nombre, ',');
        soldado2 >> vida;
        soldado2.ignore(); 
        soldado2 >> fuerza;
        soldado2.ignore();
        soldado2 >> velocidad;
        soldado2.ignore();
        soldado2 >> pos_x;
        soldado2.ignore();
        soldado2 >> pos_y;

        Posicion pos = Posicion(pos_x, pos_y);
        soldados_ejercito2[i] = new Personaje(nombre, vida, fuerza, velocidad, pos, 2);
    }

    archivo.close();


    // ==========================================================================================================

    Mapa mapa(alto, ancho);

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        mapa.agregarPersonaje(soldados_ejercito1[i]);
    }

    for (int j = 0; j < cantidad_de_soldados2; j++) {
        mapa.agregarPersonaje(soldados_ejercito2[j]);
    }

    mapa.mostrarCasillas();


    Juego juego;
    juego.calcularPromedios(soldados_ejercito1, &cantidad_de_soldados1);
    juego.calcularPromedios(soldados_ejercito2, &cantidad_de_soldados2);


    for (int i = 0; i < cantidad_de_soldados1; i++) {
        delete soldados_ejercito1[i];
    }

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        delete soldados_ejercito2[i];
    }
    

    return 0;
}

