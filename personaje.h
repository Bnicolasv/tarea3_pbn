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
        std::string getNombre() const;
        int getVida() const;
        int getFuerza() const;
        int getVelocidad() const;
        Posicion getPosicion() const;

    private:
        std::string nombre;
        int vida, fuerza, velocidad;
        Posicion* pos;
};