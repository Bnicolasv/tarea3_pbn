#include <string>
#include <iostream>
#include "posicion.h"
#include "personaje.h"

class Juego {
    public:
        float calcularPromedios(Personaje* personajes[], int* cantidad_de_soldados);
        void jugar();
        void chequearGanador();
        int calcularTurno();
        void mostrarMapa();
        void combate(Personaje *p1, Personaje *p2);
};