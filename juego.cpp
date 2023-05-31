#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include "personaje.h"
#include "mapa.h"
#include "juego.h"
#include "posicion.h"

using namespace std;


float Juego::calcularPromedios(Personaje* personajes[], int* cantidad_de_soldados) {
    int suma_velocidades_ejercito = 0;
    float promedio_velocidad_ejercito = 0;

    for (int i = 0; i < *cantidad_de_soldados; i++) {
        suma_velocidades_ejercito += personajes[i]->getVelocidad();  
    }

    promedio_velocidad_ejercito = static_cast<float>(suma_velocidades_ejercito) / static_cast<int>(*cantidad_de_soldados);    
    std::cout << "El promedio de velocidades del ejercito es : " << promedio_velocidad_ejercito << std::endl;
}


void Juego::jugar() {
    ifstream archivo("soldados_short.txt");
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

    cout << "TEST COMBATES" << endl;
    for (int i = 0; i < cantidad_de_soldados1; i++) {
        juego.combate(soldados_ejercito1[i], soldados_ejercito2[i]);
    }
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < cantidad_de_soldados1; i++) {
        delete soldados_ejercito1[i];
    }

    for (int i = 0; i < cantidad_de_soldados2; i++) {
        delete soldados_ejercito2[i];
    }
}


void Juego::chequearGanador(Personaje* soldados_ejercito1[], int* cantidad_soldados_ejercito1, Personaje* soldados_ejercito2[], int* cantidad_soldados_ejercito2) {
    bool ejercito1_pierde = true;
    for (int i = 0; i < *cantidad_soldados_ejercito1; i++) {
        if (soldados_ejercito1[i]->getVida() > 0) {
            ejercito1_pierde = false;
            break;
        }
    }

    if (ejercito1_pierde) {
        std::cout << "El ejercito 1 tiene todos sus soldados muertos. Ha ganado el ejercito 2" << std::endl;
        return;
    }

    bool ejercito2_pierde = true;
    for (int i = 0; i < *cantidad_soldados_ejercito2; i++) {
        if (soldados_ejercito2[i]->getVida() > 0) {
            ejercito2_pierde = false;
            break;
        }
    }

    if (ejercito2_pierde) {
        std::cout << "El ejercito 2 tiene todos sus soldados muertos. Ha ganado el ejercito 1" << std::endl;
        return;
    }
}

// Para ver quien parte?
int Juego::calcularTurno(float* promedio_velocidad_ejercito1, float* promedio_velocidad_ejercito2) {
    int indice_ejercito = 0;
    if (*promedio_velocidad_ejercito1 > *promedio_velocidad_ejercito2) {
        return indice_ejercito = 1;
    }
    else {
        return indice_ejercito = 2;
    }
}

void Juego::mostrarMapa() {

}


void Juego::combate(Personaje *p1, Personaje *p2) {
    // Ataca primero el personaje con mayor velocidad. Si tienen la misma velocidad, parte el que tenga 
    // mayor ataque. Si tienen misma velocidad y ataque, parte el que tenga mayor vida. 
    
    std::cout << "Comienza la pelea entre " << p1->getNombre() << " y " << p2->getNombre() << ":" << std::endl; 

    Personaje* atacante;
    Personaje* defensor;
    Personaje* ganador;

    if (p1->getVelocidad() > p2->getVelocidad()) {
        atacante = p1;
        defensor = p2;

        // FALTA MOSTRAR JUNTO AL NOMBRE EL EJERCITO AL CUAL PERTENECEN 'BENJA1', 'PEDRO2'
        std::cout << "La velocidad de " << atacante->getNombre() << " es de " << atacante->getVelocidad() << ", ";
        std::cout << "la de " << defensor->getNombre() << " es de " << defensor->getVelocidad() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << std::endl;
    }

    else if (p2->getVelocidad() > p1->getVelocidad()) {
        atacante = p2;
        defensor = p1;

        std::cout << "La velocidad de " << atacante->getNombre() << " es de " << atacante->getVelocidad() << ", ";
        std::cout << "la de " << defensor->getNombre() << " es de " << defensor->getVelocidad() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << std::endl;
    }

    else if (p1->ataque() > p2->ataque()) {
        atacante = p1;
        defensor = p2;
        
        std::cout << "El ataque de " << atacante->getNombre() << " es de " << atacante->ataque() << ", ";
        std::cout << "el de " << defensor->getNombre() << " es de " << defensor->ataque() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << std::endl;
    }

    else if (p2->ataque() > p1->ataque()) {
        atacante = p2;
        defensor = p1;

        std::cout << "El ataque de " << atacante->getNombre() << " es de " << atacante->ataque() << ", ";
        std::cout << "el de " << defensor->getNombre() << " es de " << defensor->ataque() << ", ";
        std::cout << "comienza atacando " << atacante->getNombre() << std::endl;
    }

    else if (p1->getVida() > p2->getVida()) {
        atacante = p1;
        defensor = p2;

        std::cout << "La vida de " << atacante->getNombre() << " es de " << atacante->getVida() << ",";
        std::cout << "la de " << defensor->getNombre() << " es de " << defensor->getVida() << ",";
        std::cout << "comienza atacando" << atacante->getNombre() << std::endl;
    }

    else if (p2->getVida() > p1->getVida()) {
        atacante = p2;
        defensor = p1;

        std::cout << "La vida de " << atacante->getNombre() << " es de " << atacante->getVida() << ",";
        std::cout << "la de " << defensor->getNombre() << " es de " << defensor->getVida() << ",";
        std::cout << "comienza atacando" << atacante->getNombre() << std::endl;
    }

    // Una vez que ya se sabe quien ataca y quien defiende, comienzan a pegarse hasta que uno de ellos pierda
    while (atacante->getVida() > 0 && defensor->getVida() > 0) {
        defensor->recibirAtaque(atacante);
        std::cout << atacante->getNombre() << " inflinge " << atacante->ataque() << " de dano a ";
        std::cout << defensor->getNombre() << ", vida restante: " << defensor->getVida() << std::endl;

        // https://www.geeksforgeeks.org/swap-in-cpp/
        std::swap(atacante, defensor);
    }

    // Evalua con el operador ternario '?' cual personaje quedo como ganador
    // https://es.stackoverflow.com/questions/384162/qu%C3%A9-hace-el-operador-en-c
    ganador = (p1->getVida() > 0) ? p1:p2;
    std::cout << "Combate finalizado, ha ganado " << ganador->getNombre() << std::endl;
}