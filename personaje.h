#ifndef PERSONAJE
#define PERSONAJE

#include <string>
#include "juego.h"

class Personaje {
    public:
        Personaje(std::string nombre, int vida, int fuerza, int velocidad, Posicion pos, int ejercito);
        ~Personaje();
        Personaje();

        Posicion moverse();
        void recibirAtaque(Personaje* enemigo);
        std::string getNombre() const;
        int getVida() const;
        int ataque() const;
        int getVelocidad() const;
        Posicion getPosicion() const;
        int getEjercito() const;
        Mapa* mapa;
        Juego* juego;

    private:
        std::string nombre;
        int vida, fuerza, velocidad, ejercito;
        Posicion* pos;
};

#endif