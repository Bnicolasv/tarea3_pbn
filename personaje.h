#include <string>
#include <iostream>
#include "posicion.h"

class Personaje{
    public:
        Personaje(std::string nombre, int vida, int ataque, int velocidad, Posicion pos);
        ~Personaje();
    private:
        std::string nombre;

}