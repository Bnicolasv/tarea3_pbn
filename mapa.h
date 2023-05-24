#include <iostream>
#include "personaje.h"

class Mapa {
    public:
        Mapa(int ancho, int alto);
        ~Mapa();

        void crearMapa(int ancho, int alto);
        void agregarPersonaje(Personaje *personaje);
        void eliminarPersonaje(Personaje *Personaje);

    private:
        int ancho, alto;
};