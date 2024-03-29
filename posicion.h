#include "juego.h"

#ifndef POSICION
#define POSICION

class Posicion {
    public:
        Posicion(int x, int y);
        ~Posicion();

        int getX() const;
        int getY() const;
        void set(int x, int y);

    private:
        int x, y;
};

#endif