#include <iostream>
#include <vector>
#include "personaje.h"

class Mapa {
    public:
        Mapa(int ancho, int alto);
        ~Mapa();

        int casillaCentralX();
        int casillaCentralY();
        void mostrarMapa();
        void agregarPersonaje(Personaje* personaje);
        void eliminarPersonaje(Personaje* personaje);
        void mostrarCasillas(); 

    private:
        int ancho, alto;
        std::vector<std::vector<Personaje*> > casillas;
};