#include "juego.h"
#include <vector>

#ifndef MAPA_H
#define MAPA_H

class Personaje;
class Juego;

class Mapa {
    public:
        Mapa(int ancho, int alto);
        int casillaCentralX();
        int casillaCentralY();
        int getAncho() const;
        int getAlto() const;
        void agregarPersonaje(Personaje* personaje);
        void eliminarPersonaje(Personaje* personaje);
        void mostrarCasillas(); 
        std::vector<std::vector<Personaje*>> getCasillas();

    private:
        int ancho, alto;
        std::vector<std::vector<Personaje*>> casillas;
};

#endif