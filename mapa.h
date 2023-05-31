#include <iostream>
#include <vector>
#include "personaje.h"

class Mapa {
    public:
        Mapa(int ancho, int alto);
        int casillaCentralX();
        int casillaCentralY();
        int getAncho();
        int getAlto();
        void agregarPersonaje(Personaje* personaje);
        void eliminarPersonaje(Personaje* personaje);
        void mostrarCasillas(); 
        std::vector<std::vector<Personaje*>> getCasillas();

    private:
        int ancho, alto;
        std::vector<std::vector<Personaje*> > casillas;
};