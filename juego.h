#include <string>
#include <iostream>
#include "posicion.h"
#include "personaje.h"

class Juego {
    public:
        float calcularPromedios(Personaje* personajes[], int* cantidad_de_soldados);
        void jugar();
        void chequearGanador(Personaje* ejercito1[], int* cantidad_soldados_ejercito1, Personaje* ejercito2[], int* cantidad_soldados_ejercito2);
        int calcularTurno(float* promedio_velocidad_ejercito1, float* promedio_velocidad_ejercito2);
        void mostrarMapa();
        void combate(Personaje *p1, Personaje *p2);
};