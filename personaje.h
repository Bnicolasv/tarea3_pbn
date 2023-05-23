#include <string>
#include <iostream>
#include "posicion.h"

class Personaje {
    public:
        Personaje(std::string nombre, int vida, int ataque, int velocidad, Posicion pos);
        ~Personaje();

        int getAtaque();
        Posicion moverse();
        void recibirAtaque(Personaje* enemigo);

    private:
        std::string nombre;
        int vida, ataque, velocidad;
        Posicion pos;
};