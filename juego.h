#ifndef JUEGO
#define JUEGO

#include "posicion.h"
#include "mapa.h"
#include "personaje.h"


class Juego {
    public:
        Juego() = default;
        void jugar();
        void chequearGanador();
        int calcularTurno();
        void mostrarMapa();
        void combate(Personaje *p1, Personaje *p2);
    private:
        Mapa mapa;
};

#endif