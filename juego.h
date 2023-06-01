#ifndef JUEGO
#define JUEGO

#include "posicion.h"
#include "mapa.h"
#include "personaje.h"


class Juego {
    public:
        Juego() = default;
        float calcularPromediosEjercito1(Mapa* mapa_ptr);
        float calcularPromediosEjercito2(Mapa* mapa_ptr);
        void jugar();
        void chequearGanador(Personaje* ejercito1[], int* cantidad_soldados_ejercito1, Personaje* ejercito2[], int* cantidad_soldados_ejercito2);
        int calcularTurno(float promedio_velocidad_ejercito1, float promedio_velocidad_ejercito2);
        void mostrarMapa();
        void combate(Personaje *p1, Personaje *p2);
    private:
        Mapa mapa;
};

#endif