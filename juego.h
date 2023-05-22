#include <string>
#include <iostream>
#include "posicion.h"
#include "personaje.h"

class Juego{
    public:
        Juego();
        ~Juego();
        void jugar();
        void chequearGanador();
        int calcularTurno();
        void mostrarMapa();
        void combate(Personaje *p1, Personaje *p2);
};