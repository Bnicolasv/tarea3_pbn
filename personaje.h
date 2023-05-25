#include <string>
#include <iostream>
#include "posicion.h"

class Personaje {
    public:
        Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos);
        ~Personaje();

        int ataque();
        Posicion moverse();
        void recibirAtaque(Personaje* enemigo);

    private:
        std::string nombre;
        int vida, fuerza, velocidad;
        Posicion* pos;
};